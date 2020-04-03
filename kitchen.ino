#include <ESP8266WiFi.h>
#include "DHT.h"
DHT dht;
const int gasPin = A0;//mq6 sensor

void setup() {
  Serial.begin(9600);
  Serial.println();
  Serial.println("Status\tHumidity (%)\tTemperature (C)");
  dht.setup(D1);  /* D1 is the pin where data pin of dht is connected.*/
  pinMode(gasPin, INPUT);
}

void loop() {
  //getting temperature and humidity from DHT11
  float humidity = dht.getHumidity();/* Get humidity value */
  float temperature = dht.getTemperature();/* Get temperature value */
  //getting reading from MQ6 gas sensor.
  int readingGas = digitalRead(gasPin); 

  //now printing the values
  Serial.println("Reading from gas sensor is");
  Serial.println(readingGas);
  Serial.print("\t");//tab space
  Serial.print(humidity, 1);
  Serial.print("\t\t");
  Serial.print(temperature, 1);
  Serial.print("\t\t");


}
