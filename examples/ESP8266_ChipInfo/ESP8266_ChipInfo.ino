#include <Arduino.h>
#include <chip_information.h>

void setup()
{
  Serial.begin(115200);
  delay(500);
  chip_information_ESP8266();
}

void loop()
{
  delay(1000);
}