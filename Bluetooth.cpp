// 
// 
// 
#include "Arduino.h"
#include "Bluetooth.h"
Bluetooth::Bluetooth(int serialport) {
	Serial2.begin(serialport);
	_serialport = serialport;
}
char Bluetooth::getInput() {
	if (Serial2.available) {
		_choice = Serial2.read();
		Serial.println("test bluetooth input" + _choice);
		return _choice;

	}
}

