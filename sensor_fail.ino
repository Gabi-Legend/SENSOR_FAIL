#include <DHT.h>  //SENSOR LIBRARY

#define DHTPIN 2
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

int LED = 3;
bool lastState = LOW;

//TIMEOUT 
unsigned long lastGoodRead = 0;  
const unsigned long timeout = 10000; 

void setup() {
  Serial.begin(9600);
  pinMode(LED, OUTPUT);
  dht.begin();
}

void loop() {
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  bool currentState;
  //CHECK IF THE SENSOR IS WORKING PROPERLY
  if (isnan(t) || isnan(h)) {
    Serial.println("DHT11 read error");
    if (millis() - lastGoodRead > timeout) {
      currentState = LOW; 
    } else {
      currentState = lastState; 
    }
  } else {
    lastGoodRead = millis();
    currentState = HIGH;
    Serial.print("Temperature: ");
    Serial.print(t);
    Serial.print(" C  Humidity: ");
    Serial.print(h);
    Serial.println(" %");
  }

  if(currentState != lastState){
    digitalWrite(LED, currentState ? HIGH : LOW);
    lastState = currentState;
  }

  delay(2000); 
}
