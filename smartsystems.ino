
const int enableLeft = 5;
const int enableRight = 6;
const int inputLeftFront = A0;
const int inputLeftBack = A1;
const int inputRightBack = A2;
const int inputRightFront = A3;
char choice;
void setup()
{
	//start serial connection

	Serial.begin(9600);

	pinMode(enableLeft, OUTPUT);
	pinMode(enableRight, OUTPUT);
	pinMode(inputLeftFront, OUTPUT);
	pinMode(inputLeftBack, OUTPUT);
	pinMode(inputRightBack, OUTPUT);
	pinMode(inputRightFront, OUTPUT);
	/*
	pinMode(inputLeftFront, OUTPUT);
	pinMode(inputLeftBack, OUTPUT);
	pinMode(inputRightBack, OUTPUT);
	pinMode(inputRightFront, OUTPUT);
	*/
}

void loop()
{
	if (Serial.available()) {
		Serial.print("Serial is available");
		//if the choise changed put the new value in the variable
		choice = Serial.read();


	}


	if (choice == '0') {
		//stop the car
		carStop();
	}
	else if (choice == '1') {
		//drive car forward
		//Serial.print("Driving car forward");
		carForward(200);
	}
	else if (choice == '2') {
		//turn left slow
		carTurnLeft(200, false);
	}
	else if (choice == '3') {
		//turn left fast
		carTurnLeft(200, true);
	}
	else if (choice == '4') {
		//turn right slow
		carTurnRight(200, false);
	}
	else if (choice == '5') {
		//turn right fast
		carTurnRight(200, true);
	}
	else if (choice == '6') {
		//drive car backwards
		carBackwards(200);
	}


}
void carStop() {
	Serial.print("Stopping");
	analogWrite(enableLeft, LOW);
	analogWrite(enableRight, LOW);
	digitalWrite(A0, LOW);
	digitalWrite(A1, LOW);
	digitalWrite(A2, LOW);
	digitalWrite(A3, LOW);
}
void carForward(int speed) {
	Serial.print("driving forward");
	analogWrite(enableLeft, speed);
	analogWrite(enableRight, speed);
	digitalWrite(inputLeftFront, LOW);
	digitalWrite(inputLeftBack, HIGH);
	digitalWrite(inputRightFront, LOW);
	digitalWrite(inputRightBack, HIGH);

}
void carBackwards(int speed) {
	Serial.print("driving backwards");
	analogWrite(enableLeft, speed);
	analogWrite(enableRight, speed);
	digitalWrite(inputLeftFront, HIGH);
	digitalWrite(inputLeftBack, LOW);
	digitalWrite(inputRightFront, HIGH);
	digitalWrite(inputRightBack, LOW);
}
void carTurnLeft(int speed, bool fast) {
	Serial.print("Turning left");

	if (fast) {
		analogWrite(enableLeft, speed);
		analogWrite(enableRight, speed);
		digitalWrite(inputLeftFront, HIGH);
		digitalWrite(inputLeftBack, LOW);
		digitalWrite(inputRightFront, LOW);
		digitalWrite(inputRightBack, HIGH);
	}
	else {
		analogWrite(enableLeft, speed);
		analogWrite(enableRight, 0);
		digitalWrite(inputLeftFront, HIGH);
		digitalWrite(inputLeftBack, LOW);
		digitalWrite(inputRightFront, LOW);
		digitalWrite(inputRightBack, LOW);
	}
}
void carTurnRight(int speed, bool fast) {
	Serial.print("Turning right");

	if (fast) {
		analogWrite(enableLeft, speed);
		analogWrite(enableRight, speed);
		digitalWrite(inputLeftFront, LOW);
		digitalWrite(inputLeftBack, HIGH);
		digitalWrite(inputRightFront, HIGH);
		digitalWrite(inputRightBack, LOW);
	}
	else {
		analogWrite(enableLeft, 0);
		analogWrite(enableRight, speed);
		digitalWrite(inputLeftFront, LOW);
		digitalWrite(inputLeftBack, LOW);
		digitalWrite(inputRightFront, HIGH);
		digitalWrite(inputRightBack, LOW);
	}
}


