#ifdef controller
void setup_controller() {
  WiFi.softAP(ssid, password, 0, 0, 7);//ssid,passphrase,channel,hidden,max client number
  bFirst = true;
  vid = pid = 0;
  if (Usb.Init() == -1) {
    while (1); //halt
  }
}
void MIDI_poll()
{
  char buf[20];
  char msg[9];
  uint8_t bufMidi[4];
  uint16_t  rcvd;

  if (Midi.vid != vid || Midi.pid != pid) {
    sprintf(buf, "VID:%04X, PID:%04X", Midi.vid, Midi.pid);
    Serial.println(buf);
    vid = Midi.vid;
    pid = Midi.pid;
  }
  if (Midi.RecvData( &rcvd,  bufMidi) == 0 ) {
    uint32_t time = (uint32_t)millis();
    sprintf(buf, "%04X%04X: ", (uint16_t)(time >> 16), (uint16_t)(time & 0xFFFF)); // Split variable to prevent warnings on the ESP8266 platform
    //      Serial.print(buf); //buf=tiempo en hexadecimal
    //    Serial.print(rcvd); //tamaño del paquete recibido
    //      Serial.print(':');
    onOff = bufMidi[1];
    note = bufMidi[2];
    if (onOff == 0x90) lastNote=note;
    velocity = bufMidi[3];
    if (onOff == 0x90)ledcWriteTone(0, notes[note]);
    if (onOff == 0x80 && note==lastNote)ledcWriteTone(0, 0);
    //          Serial.print(onOff,HEX);
    //          Serial.print(",");
    //          Serial.print(note,HEX);
    //          Serial.print(",");
    //          Serial.println(velocity,HEX);
    //          Serial.println();
    sprintf(msg, "%02X", onOff);
    sprintf(msg, "%02X", note);
    sprintf(msg, "%02X", velocity);
    udp.beginPacket(IPAddress(192, 168, 4, 2), 3927);
//udp.write(note);

    for (int i = 1; i < 4; i++) {
      sprintf(buf, ",%02X", bufMidi[i]);
      Serial.print(bufMidi[i]);
      Serial.print(',');
      udp.print(bufMidi[i]);
      udp.print(',');

    }
    Serial.println();
    udp.endPacket();
  }
}
#endif
