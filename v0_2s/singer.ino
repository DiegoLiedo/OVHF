#ifdef singer
void setup_singer() {
  Serial.println("Iniciando WiFi");
  WiFi.begin(ssid, password);
  if (WiFi.waitForConnectResult() != WL_CONNECTED) {
    Serial.println("WiFi Failed");
    while (1) {
      delay(1000);
    }
  }
  //  server.begin();
  udp.begin(3927);
  Serial.printf("Servidor Iniciado\n");
}
#endif
void udpRead() {
  int packetSize = udp.parsePacket();
  if (packetSize)
  {
    Serial.print("Tamaño de paquete: ");
    Serial.println(packetSize);
    int len = udp.read(incomingPacket, 12);
    char * pch;
    pch = strtok(incomingPacket, ",");
    onOff = atoi(pch);
    //    note = udp.parseInt();
    //    velocity = udp.parseInt();
   for(int i = 0; i<3;i++){
    if (pch != NULL) {
      Serial.print("valores strtok: ");
      Serial.print(pch);
      Serial.print('\t');
      pch = strtok(NULL, ",");

    }
//    if (i=0)onOff=atoi(pch);
    if (i=1)note=atoi(pch);
    if (i=2)velocity=atoi(pch);
    }
    //    Serial.print("valores en msg[]");
    //    for (int i = 0; i < 6; i++) {
    //      Serial.println(msg[i]);
    //    }
    //    onOff = (10*msg[0])+msg[1];
    //    note = (10*msg[2])+msg[3];
    //    velocity = (10*msg[4])+msg[5];
    //onOff = incomingPacket[1];
    //note = incomingPacket[4];
    //velocity = incomingPacket[7];
    if (onOff == 144)ledcWriteTone(0, notes[note]);
    if (onOff == 128)ledcWriteTone(0, 0);
    if (len > 0)
    {
      incomingPacket[len] = 0;
    }

    Serial.println();
    Serial.println("--------------------------");
    Serial.print(onOff);
    Serial.print(',');
    Serial.print(note);
    Serial.print(',');
    Serial.println(velocity);
    //    Serial.println(temp);

  }
}

