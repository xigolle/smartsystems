int enableLeft = 5;
int enableRight = 6;
int inputLeftFront = 0;
int inputLeftBack = 1;
int inputRightBack = 10;
int inputRightFront = 15;
char choice;
void setup()
{
	//start serial connection

	Serial.begin(9600);
	
	pinMode(enableLeft, OUTPUT);
	pinMode(enableRight, OUTPUT);
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
		Serial.print("Stopping car");
	}
	else if (choice == '1') {
		//drive car forward
		Serial.print("Driving car forward");
		carForward(255);
	}




}

void carForward(int speed) {
	digitalWrite(enableLeft, HIGH);
	digitalWrite(enableRight, HIGH);
	digitalWrite(A0, HIGH);
	digitalWrite(A1, LOW);
	digitalWrite(A2, HIGH);
	digitalWrite(A3, LOW);
}

