#include <Emotion.h> //special character library
#include <LiquidCrystal_I2C.h> //I2C LCD library
#include "DHT.h" //Temperature and humidity sensor library
//The above library must be downloaded before execution


#define DHTPIN 2 //Temperature and humidity sensor data pin
#define DHTTYPE DHT11 //Temperature and humidity sensor sensor type

int red_led = 5;
int green_led = 6;
int blue_led = 7;
int light_sensor = A0;
LiquidCrystal_I2C lcd(0x27, 16, 2);
DHT dht(DHTPIN, DHTTYPE);
void setup() {
Serial.begin(9600); // Serial monitor settings
lcd.begin(); // start lcd module
lcd.clear();
dht.begin(); // Start the temperature and humidity sensor module
pinMode(light_sensor, INPUT); // Ambient sensor pin setting
pinMode(red_led, OUTPUT); // 3-color LED pin setting
pinMode(green_led, OUTPUT);
pinMode(blue_led, OUTPUT);
}
void loop() {
// Realization of night street light function using the value of the illuminance sensor
int cds = analogRead(light_sensor);
Serial.println(cds);
// Measure and store temperature and humidity values
float humid = dht.readHumidity();
float temp = dht.readTemperature();
// Store temperature and humidity values ​​as integers
int int_humid = (int)humid;
int int_temp = (int)temp;
if(cds > 500){ // Turn on the street lights when it gets dark
setColor(255, 255, 255);
}
else{
setColor(0, 0, 0); // Street lamp dream when the surroundings are bright
}
// The measured temperature and humidity values ​​are output to the LCD.
// Humidity output
lcd.setCursor(0,0);
lcd.print( "H : " );
lcd.setCursor(6,0);
lcd.print(int_humid);
lcd.setCursor(9,0);
lcd.print( " %% " );
// temperature output
lcd.setCursor(0,1);
lcd.print( "T : " );
lcd.setCursor(6,1);
lcd.print(int_temp);
lcd.setCursor(9,1);
lcd.print( " ‘C " );
delay(1000);
}
void setColor(int red, int green, int blue){
analogWrite(red_led, red);
analogWrite(green_led, green);
analogWrite(blue_led, blue);
}