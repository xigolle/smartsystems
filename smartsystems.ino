//definieer alle variabelen die later gebruikt worden in de code
//alle variabelen zijn afgestemd op basis van de pin layout.
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

//variabelen om de afstand van alle sensoren te bewaren.
long  disForSens, disBackSens, disLeftSens, disRightSens;
//de snelheid dat de wielen gaan draaien
int speed = 200;
//bool om aan te geven of de auto al een keer gestopt is of niet
bool distanceStopped = false;
//hieronder worden alle acties beschreven door middel van een array
//in die array komen de parameters te staan om die bepaalde actie uit te voeren.
//deze array wordt dan als paramater door gegeven aan de carMove methode en deze zal de juiste actie uitvoeren
//dit is zo gedaan om geen dubbele code en leesbaarheid te behouden
int carstop[] = { 0,0,LOW,LOW,LOW,LOW };
int carForward[] = { speed,speed,LOW,HIGH,LOW,HIGH };
int carBackward[] = { speed, speed,HIGH,LOW,HIGH,LOW };
int carLeftAs[] = { speed,speed,HIGH,LOW,LOW,HIGH };
int carLeft[] = { speed,0,HIGH,LOW,LOW,LOW };
int carRightAs[] = { speed,speed,LOW,HIGH,HIGH,LOW };
int carRight[] = { 0,speed,LOW,LOW,HIGH,LOW };
//variabele om de keuze te onthouden die wordt doorgegeven van uit de serial
char choice;
char tempChoice;
void setup()
{
	//start serial connection

	Serial.begin(9600);
	Serial2.begin(9600);

	//alle pinnen worden op de juist pinmode gezet
	//zo worden alle echo pin van de sensoren op INPUt gezet
	//de rest zoals de output van de H-brug en de trigger van de sensoren worden op OUTPUT gezet
	pinMode(sensTrigBack, OUTPUT);
	pinMode(sensTrigRight, OUTPUT);
	pinMode(sensTrigLeft, OUTPUT);
	pinMode(sensTrigFront, OUTPUT);
	pinMode(sensEchoBack, INPUT);
	pinMode(sensEchoRight, INPUT);
	pinMode(sensEchoLeft, INPUT);
	pinMode(sensEchoFront, INPUT);
	pinMode(enableLeft, OUTPUT);
	pinMode(enableRight, OUTPUT);
	pinMode(inputLeftFront, OUTPUT);
	pinMode(inputLeftBack, OUTPUT);
	pinMode(inputRightBack, OUTPUT);
	pinMode(inputRightFront, OUTPUT);

}

void loop()
{

	if (Serial2.available()) {
		tempChoice = Serial2.read();
		Serial.println(choice);
	}
	if (!(tempChoice == 1 && disForSens <= 15)) {
		choice = tempChoice;
	}
	else if (!(tempChoice == 6 && disBackSens <= 15)) {
		choice = tempChoice;
	}





	disForSens = getDistance(sensTrigFront, sensEchoFront);
	//printDistante(1, disForSens);
	disBackSens = getDistance(sensTrigBack, sensEchoBack);
	//printDistante(2, disBackSens);
	disLeftSens = getDistance(sensTrigLeft, sensEchoLeft);
	//printDistante(3, disLeftSens);
	disRightSens = getDistance(sensTrigRight, sensEchoRight);
	//printDistante(4, disRightSens);

	delay(1000);

	/*if (disForSens <= 10 && distanceStopped == false) {
=======
	//hier wordt er gecontroleerd of dat de bij de voorste sensor een object binnen 10 cm zit.
	//zoja zal de auto stoppen
	if (disForSens <= 10 && distanceStopped == false) {
>>>>>>> origin/ReadingSensor
		choice = '0';
		distanceStopped = true;
	}
	//hier wordt er gekeken wanneer het bovenstaande niet waar is of er al weer een commando ingegeven is.
	else {
		if (Serial2.available()) {
			Serial.print("Serial is available");

			choice = Serial.read();
	 Serial.println(choice);
			distanceStopped = false;

		}
<<<<<<< HEAD
	}*/
	//}
	//hieronder wordt gekeken welke keuze gemaakt is en op basis hiervan gaat de auto actie ondernemen
	//dit wordt nog in een functie geplaatst als ook omgevormd naar een switch statement.
	/*
	0 = auto laten stoppen.
	1 = auto vooruit laten rijden.
	2 = auto naar links laten draaien ( maar 1 wiel die draait).
	3 = auto naar links laten draaien om zijn as ( 2 wielen draaien in tegenovergestelde richting).
	4 = auto naar rechts laten draaien ( maar 1 wiel die draait).
	5 = auto naar rechts laten draaien om zijn as ( 2 wielen draaien in tegenovergestelde richting).
	6 = auto achteruit laten rijden.
	*/
	if (choice == '0') {
		//stop the car
		Serial.println("stop");
		carMove(carstop);
	}
	else if (choice == '1') {
		//drive car forward
		Serial.println("forward");
		carMove(carForward);
	}
	else if (choice == '2') {
		//turn left slow
		Serial.println("slow left");
		carMove(carLeft);
	}
	else if (choice == '3') {
		//turn left fast
		Serial.println("fast left");
		carMove(carLeftAs);
	}
	else if (choice == '4') {
		//turn right slow
		Serial.println("slow right");
		carMove(carRight);
	}
	else if (choice == '5') {
		//turn right fast
		Serial.println("fast right");
		carMove(carRightAs);
	}
	else if (choice == '6') {
		//drive car backwards
		Serial.println("backwards");
		carMove(carBackward);
	}



}
//getDistance verwacht een trigger pin en een echo pin.
//Er wordt eerst een HIGH gegeven om een trig te versturen
//daarna wordt er even gewacht en de trigger gestopt ( LOW)
// er wordt gekeken hoe lang het duurt voor de pulse binnenkomt op de echo pin
// hierna wordt de pulse tijd omgezet naar afstand (cm) en dit wordt gereturned.
long getDistance(int trigPin, int echoPin) {
	digitalWrite(trigPin, HIGH);
	delayMicroseconds(10);
	digitalWrite(trigPin, LOW);
	unsigned long pulseTime = pulseIn(echoPin, HIGH);
	int distance = pulseTime / 58;
	return distance;
}
//printDistance verwacht een id en een distance( dist).
//de Id wordt gebruikt om te herkennen welke sensor wordt afgedrukt en wordt dan ook direct geprint
//daarna wordt er gekeken of de afstand tussen de juist parameters komt dus niet out of range is.
//wanneer dat wel is wordt er "Out of range" geprint
//als hij niet out of range is wordt er een dash(-) uitgeprint op basis van de afstand bij 10 cm worden er 10 dashes (-) geprint
//en daarna ook nog de afstand ( in getal) en de maat (cm)
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
//carMove verwachten een array.
//in deze array staan al de acties die de auto moet doen om te bewegen.
//de array wordt uitgelezen en op de goeie pin uitgevoerd waardoor de auto dus zal bewegen.

void carMove(int movement[]) {
	analogWrite(enableLeft, movement[0]);
	analogWrite(enableRight, movement[1]);
	digitalWrite(inputLeftFront, movement[2]);
	digitalWrite(inputLeftBack, movement[3]);
	digitalWrite(inputRightFront, movement[4]);
	digitalWrite(inputRightBack, movement[5]);
}


