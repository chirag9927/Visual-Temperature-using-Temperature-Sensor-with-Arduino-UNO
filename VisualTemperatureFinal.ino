#include <OneWire.h>
#include <DallasTemperature.h>
int greenLedPin = 9;
int blueLedPin = 8;
int redLedPin = 10;

int temp_sensor = 4;

float temperature = 0;
int lowerLimit = 20;
int higherLimit = 30;
OneWire oneWirePin(temp_sensor);
DallasTemperature sensors(&oneWirePin);
void setup(void){
  Serial.begin(9600);
  
  //Setup the LEDS to act as outputs
  pinMode(redLedPin,OUTPUT);
  pinMode(greenLedPin,OUTPUT);
  pinMode(blueLedPin,OUTPUT);
  
  sensors.begin();
}
void loop(){
  Serial.print("Requesting Temperatures from sensors: ");
  sensors.requestTemperatures(); 
  Serial.println("DONE");
  
  temperature = sensors.getTempCByIndex(0);
  digitalWrite(redLedPin, LOW);
  digitalWrite(greenLedPin, LOW);
  digitalWrite(blueLedPin, LOW);
  
  Serial.print("Temperature is ");
  Serial.print(temperature);
  //Setup the LEDS to act as outputs
if(temperature <= lowerLimit){ 
    Serial.println(", Blue LED is Activated"); 
    digitalWrite(blueLedPin, HIGH); } 
else if(temperature > lowerLimit && temperature < higherLimit){ 
    Serial.println(", Green LED is Activated"); 
    digitalWrite(greenLedPin, HIGH);
} 
else if(temperature >= higherLimit){
    Serial.println(", Red LED is Activated");
    digitalWrite(redLedPin, HIGH);
}
delay(500);
}
