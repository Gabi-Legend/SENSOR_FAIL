#include <DHT.h>

#define DHTPIN 2
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  dht.begin();
}

void loop() {
  float h = dht.readHumidity();
  float t = dht.readTemperature();

  if (isnan(t) || isnan(h)) {
    Serial.println("DHT11 read error");
  } else {
    Serial.print("Temperature: ");
    Serial.print(t);
    Serial.print(" C  Humidity: ");
    Serial.print(h);
    Serial.println(" %");
  }

  delay(2000); // OBLIGATORIU
}
