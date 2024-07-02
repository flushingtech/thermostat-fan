#include <dht11.h>

// Do not wire a resistor between the power pin for the temp sensor
#define DHT11PIN 7 // Digital pin 7 for the sensor signal
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

  // You can adjust the temperature to test but the idea
  // is to have the fan turn on when the temp hits certain threshold
  if (temperature > 25) {
    digitalWrite(CONTROL_PIN, HIGH); // Turn ON the transistor
  } else {
    digitalWrite(CONTROL_PIN, LOW); // Turn OFF the transistor
  }

  delay(2000);
}