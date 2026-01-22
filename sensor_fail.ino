#include <DHT.h>

#define DHTPIN 2
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);
int LED = 3;

bool lastState = LOW;

void setup() {
  Serial.begin(9600);
  pinMode(LED, OUTPUT);
  dht.begin();
}

void loop() {
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  bool currentState;
  if (isnan(t) || isnan(h)) {
    Serial.println("DHT11 read error");
    currentState = LOW;
  } else {
    currentState = HIGH;
    Serial.print("Temperature: ");
    Serial.print(t);
    Serial.print(" C  Humidity: ");
    Serial.print(h);
    Serial.println(" %");
  }
  if(currentState == HIGH && lastState == LOW){
    digitalWrite(LED, HIGH);
    lastState = HIGH;
  }
  else if(currentState == LOW && lastState == HIGH){
    lastState = LOW;
    digitalWrite(LED, LOW);
  }
  delay(2000); 
}
