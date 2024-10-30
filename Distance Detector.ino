int ledPin1 = 8;
int buzzPin = 7;
int trigPin = 10;
int echoPin = 9;
int  duration;
int distance;


void setup() {
  pinMode(ledPin1,OUTPUT);
  pinMode(buzzPin,OUTPUT);
  pinMode(trigPin,OUTPUT);
  pinMode(echoPin,INPUT);
  Serial.begin(9600);

}

void loop() {
  digitalWrite(trigPin, LOW);  
	delayMicroseconds(2);  
	digitalWrite(trigPin, HIGH);  
	delayMicroseconds(10);  
	digitalWrite(trigPin, LOW);  
  duration = pulseIn(echoPin, HIGH);
  distance = (duration*.0343)/2;
  
  if (distance<=200){
    digitalWrite(ledPin1, HIGH);
    tone(buzzPin,1000);
    delay(distance); 
    noTone(buzzPin);
    delay(distance);
  } else{
    digitalWrite(ledPin1, LOW);
    noTone(buzzPin);
    delay(1000);
  }

}
