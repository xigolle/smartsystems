
#define enableLeft 2
#define enableRight 3
#define inputLeftFront  A0
#define inputLeftBack  A1
#define inputRightBack  A2
#define inputRightFront  A3
#define sensEchoBack  9
#define sensTrigBack  8
#define sensEchoRight 11
#define sensTrigRight 10
#define sensEchoLeft 7
#define sensTrigLeft 6
#define sensEchoFront 13
#define sensTrigFront 12
#define LEDPin  13


long duration, disForSens, disBackSens, disLeftSens, disRightSens;
int speed = 200;
bool distanceStopped = false;
int carstop[] = { 0,0,LOW,LOW,LOW,LOW };
int carForward[] = { speed,speed,LOW,HIGH,LOW,HIGH };
int carBackward[] = { speed, speed,HIGH,LOW,HIGH,LOW };
int carLeftAs[] = { speed,speed,HIGH,LOW,LOW,HIGH };
int carLeft[] = { speed,0,HIGH,LOW,LOW,LOW };
int carRightAs[] = { speed,speed,LOW,HIGH,HIGH,LOW };
int carRight[] = { 0,speed,LOW,LOW,HIGH,LOW };
char choice;
void setup()
{
	//start serial connection

	Serial.begin(9600);
	pinMode(sensTrigBack, OUTPUT);
	pinMode(sensTrigRight, OUTPUT);
	pinMode(sensTrigLeft, OUTPUT);
	pinMode(sensTrigFront, OUTPUT);
	pinMode(sensEchoBack, INPUT);
	pinMode(sensEchoRight, INPUT);
	pinMode(sensEchoLeft, INPUT);
	pinMode(sensEchoFront, INPUT);
	pinMode(LEDPin, OUTPUT);
	pinMode(enableLeft, OUTPUT);
	pinMode(enableRight, OUTPUT);
	pinMode(inputLeftFront, OUTPUT);
	pinMode(inputLeftBack, OUTPUT);
	pinMode(inputRightBack, OUTPUT);
	pinMode(inputRightFront, OUTPUT);

}

void loop()
{

	


//Serial.println(disForSens);
	disForSens = getDistance(sensTrigFront, sensEchoFront);
	printDistante(1, disForSens);
	/*delay(150);*/
	disBackSens = getDistance(sensTrigBack, sensEchoBack);
	printDistante(2, disBackSens);
	//delay(150);
	disLeftSens = getDistance(sensTrigLeft, sensEchoLeft);
	printDistante(3, disLeftSens);
	//delay(150);
	disRightSens = getDistance(sensTrigRight, sensEchoRight);
	printDistante(4, disRightSens);
	//delay(500);

	if (disForSens <= 10 && distanceStopped == false) {
		choice = '0';
		distanceStopped = true;
	}
	else {
		if (Serial.available()) {
			Serial.print("Serial is available");
			//if the choise changed put the new value in the variable
			choice = Serial.read();
			distanceStopped = false;

		}
	}
	if (choice == '0') {
		//stop the car
		carMove(carstop);
	}
	else if (choice == '1') {
		//drive car forward
		carMove(carForward);
	}
	else if (choice == '2') {
		//turn left slow
		carMove(carLeft);
	}
	else if (choice == '3') {
		//turn left fast
		carMove(carLeftAs);
	}
	else if (choice == '4') {
		//turn right slow
		carMove(carRight);
	}
	else if (choice == '5') {
		//turn right fast
		carMove(carRightAs);
	}
	else if (choice == '6') {
		//drive car backwards
		carMove(carBackward);
	}


}

long getDistance(int trigPin, int echoPin) {
	digitalWrite(trigPin, HIGH);
	delayMicroseconds(10);
	digitalWrite(trigPin, LOW);
	unsigned long pulseTime = pulseIn(echoPin, HIGH);
	int distance = pulseTime / 58;
	return distance;
}
void printDistante(int id, int dist) {
	Serial.print(id);
	if (dist >= 120 || dist <= 0) {
		Serial.println("Out of range");
	}
	else {
		for (int i = 0; i <= dist; i++) {
			Serial.print('-');

		}
		Serial.print(dist, DEC);
		Serial.println("cm");
	}
}
void carMove(int movement[]) {
	analogWrite(enableLeft, movement[0]);
	analogWrite(enableRight, movement[1]);
	digitalWrite(inputLeftFront, movement[2]);
	digitalWrite(inputLeftBack, movement[3]);
	digitalWrite(inputRightFront, movement[4]);
	digitalWrite(inputRightBack, movement[5]);
}


