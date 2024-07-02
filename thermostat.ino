#include <dht11.h>

#define DHT11PIN 7 // Analog pin A0
#define CONTROL_PIN 2 // Digital pin 2 for controlling the transistor

dht11 DHT11;

void setup() {
  Serial.begin(9600);
  pinMode(CONTROL_PIN, OUTPUT); // Set the control pin as an output
}

void loop() {
  Serial.println();

  int chk = DHT11.read(DHT11PIN);

  Serial.print("Humidity (%): ");
  Serial.println((float)DHT11.humidity, 2);
  float temperature = DHT11.temperature;
  Serial.print("Temperature (C): ");
  Serial.println(temperature);

  if (temperature > 20) {
    digitalWrite(CONTROL_PIN, HIGH); // Turn ON the transistor
  } else {
    digitalWrite(CONTROL_PIN, LOW); // Turn OFF the transistor
  }

  delay(2000);
}