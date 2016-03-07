int enableLeft = 5;
int enableRight = 6;
int inputLeftFront = 0;
int inputLeftBack = 1;
int inputRightBack = 10;
int inputRightFront = 15;

void setup()
{
	//start serial connection
	
	Serial.begin(9600);
	while (!Serial);/*
	pinMode(enableLeft, OUTPUT);
	pinMode(enableRight, OUTPUT);
	pinMode(inputLeftFront, OUTPUT);
	pinMode(inputLeftBack, OUTPUT);
	pinMode(inputRightBack, OUTPUT);
	pinMode(inputRightFront, OUTPUT);
	/* add setup code here */
	
	}

	void loop()
	{
		if (Serial.available()) {
			Serial.print(Serial.read());
		}
			Serial.print("Hello arduino");





	}
	
