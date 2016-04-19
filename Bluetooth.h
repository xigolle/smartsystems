// Bluetooth.h

#ifndef _BLUETOOTH_h
#define _BLUETOOTH_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif
class Bluetooth {
public:
	Bluetooth(int serialport);
	char getInput();
private:
	int _serialport;
	char _choice;
};

#endif

