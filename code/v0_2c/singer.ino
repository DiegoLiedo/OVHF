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

  int packetSize = udp.parsePacket();
  if (packetSize)
  {
    int len = udp.read(incomingPacket, 8);
    if (len > 0)
    {
      incomingPacket[len] = 0;
    }
 Serial.printf(incomingPacket);

  }
}

