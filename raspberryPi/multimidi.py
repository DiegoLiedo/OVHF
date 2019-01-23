#!/usr/bin/env python3
import rtmidi

midiin = rtmidi.MidiIn()
midiin2 = rtmidi.MidiIn()
midiin3 = rtmidi.MidiIn()
midiin4 = rtmidi.MidiIn()

ports = range(midiin.get_port_count())
if ports:
    for i in ports:
        print(midiin.get_port_name(i))
    midiin.open_port(1)
    print("Opening port",1) 
    midiin2.open_port(2)
    print("Opening port",2)
    midiin3.open_port(3)
    print("Opening port",3) 
    midiin4.open_port(4)
    print("Opening port",4)
    while True:
        m = midiin.get_message()
        m2 = midiin2.get_message()
        m3 = midiin3.get_message()
        m4 = midiin4.get_message()
        if m:
            print("1",m) 
        elif m2:
            print("2",m2)
        elif m3:
            print("3",m3)
        elif m4:
            print("4",m4)   
	
else:
    print('NO MIDI INPUT PORTS!')
