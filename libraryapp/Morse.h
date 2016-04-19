// Morse.h

#ifndef _MORSE_h
#define _MORSE_h


#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

class Morse {
public:
	Morse(int pin);
	void dot();
	void dash();
private:
	int _pin;
};

#endif

