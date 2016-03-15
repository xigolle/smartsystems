int enableLeft = 5;
int enableRight = 6;
char wheelFrontLeft = 'A0';
char wheelBackLeft = 'A1';
int wheelBackRight = 2;
int wheelFrontRight = 4;
char choise = '1';

void setup() {
	Serial.begin(9600);
	pinMode(enableLeft, OUTPUT);
	pinMode(enableRight, OUTPUT);
	pinMode(A0, OUTPUT);
	pinMode(A1, OUTPUT);
	pinMode(A2, OUTPUT);
	pinMode(A3, OUTPUT);
}

void loop() {
	carForward();
	if (Serial.available()) {
		choise = Serial.read();
		if (choise == '0') {
			Serial.print("options is zero");
			//carStop();
		}
		else if (choise == '1') {
			Serial.print("options is 1");
				
			
			
		}
	}

}


void carStop() {
	digitalWrite(enableLeft, LOW);
	digitalWrite(enableRight, HIGH);
}
void carForward() {
	Serial.print("Running forward");
	analogWrite(enableLeft, 150);
	analogWrite(enableRight, 150);
	digitalWrite(A2, HIGH);
	digitalWrite(A3, LOW);
	digitalWrite(A0, LOW);
	digitalWrite(A1, HIGH);
}