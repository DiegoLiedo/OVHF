Second version of the controller:
ESP32: 
1. Creates a WiFi network. 
2. Reads MIDI input from a MAX3421 (USB host).
3. Plays the input note on pin 25.
4. Sends the MIDI message UDP through port 3927
