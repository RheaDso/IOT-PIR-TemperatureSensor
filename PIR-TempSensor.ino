#include <OneWire.h>
#include <DallasTemperature.h>

// Data wire is conntec to the Arduino digital pin 4
#define ONE_WIRE_BUS 5

// Setup a oneWire instance to communicate with any OneWire devices
OneWire oneWire(ONE_WIRE_BUS);

// Pass our oneWire reference to Dallas Temperature sensor 
DallasTemperature temp(&oneWire);

int pirPin = 2;                 // PIR Out pin D4

void setup()
{
  // Start serial communication for debugging purposes
  Serial.begin(9600);
  // Start up the library
  temp.begin();
}

void loop()
{ 
  // Call sensors.requestTemperatures() to issue a global temperature and Requests to all devices on the bus
  temp.requestTemperatures(); 
  
  Serial.print("Celsius temperature: ");
  // Why "byIndex"? You can have more than one IC on the same bus. 0 refers to the first IC on the wire
  Serial.print(temp.getTempCByIndex(0)); 
  Serial.print(" - Fahrenheit temperature: ");
  Serial.println(temp.getTempFByIndex(0));
  delay(100); 
}

void setup1()
{     
 pinMode(pirPin, INPUT);     
 Serial.begin(9600);
}
void loop1()
{
  delay(100);
 if (digitalRead(pirPin) == HIGH)  // if motion detected
 {           
   Serial.println("got you!!!");
 }
 else {
   Serial.println("nope");
 }
}
