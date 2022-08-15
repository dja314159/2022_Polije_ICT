//Creating a smart city where the traffic lights at the crosswalk turn red when the bus approaches
int echoPin = 2;
int trigPin = 3;
int red_led = 4;
int yellow_led = 5;
int green_led = 6;
void setup() {
// Ultrasonic sensor and traffic light sensor pin settings
Serial.begin(9600);
pinMode(trigPin, OUTPUT);
pinMode(echoPin, INPUT);
pinMode(red_led, OUTPUT);
pinMode(yellow_led, OUTPUT);
pinMode(green_led, OUTPUT);
}
void loop() {
digitalWrite(trigPin, LOW);
digitalWrite(echoPin, LOW);
delayMicroseconds(2);
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
unsigned long duration = pulseIn(echoPin, HIGH);
float distance = ((float)(340 * duration) / 10000) / 2;
Serial.print(distance);
Serial.println("cm");
if(distance < 7.5){
digitalWrite(yellow_led, HIGH);
delay(500);
digitalWrite(yellow_led, LOW);
delay(500);
digitalWrite(red_led, HIGH);
delay(3000);
digitalWrite(red_led, LOW);
delay(500);
}
else{
digitalWrite(green_led, HIGH);
delay(1500);
digitalWrite(green_led, LOW);
delay(500);
}
delay(200);
}
