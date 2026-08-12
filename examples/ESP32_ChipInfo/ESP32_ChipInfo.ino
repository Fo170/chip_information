#include <Arduino.h>
#include <chip_information.h>

void setup()
{
  Serial.begin(115200);
  delay(500);
  chip_information();
}

void loop()
{
  delay(1000);
}