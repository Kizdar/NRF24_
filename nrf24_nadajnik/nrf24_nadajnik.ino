/*
* Arduino Wireless Communication Tutorial
*     Example 1 - Transmitter Code
*                
* by Dejan Nedelkovski, www.HowToMechatronics.com
* 
* Library: TMRh20/RF24, https://github.com/tmrh20/RF24/
*/

#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
#include "DHT.h"

#define DHTPIN 3
#define DHTTYPE DHT11
 float data[10];
DHT dht(DHTPIN, DHTTYPE);
RF24 radio(9, 10); // CE, CSN

const byte address[6] = "00001";

void setup() {
  Serial.begin(9600);
  radio.begin();
  radio.openWritingPipe(address);
  radio.setPALevel(RF24_PA_MIN);
  radio.stopListening();
  dht.begin();
}

void loop() {
  
  float t = dht.readTemperature();
 

  data[1]=t;
  const char text[] = "Hello World";
  radio.write(&data, sizeof(data));
  delay(1000);
  Serial.println(t);
}
