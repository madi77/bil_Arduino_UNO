/*
Working with Light Dependent Resistor (LDR)
by codedByMadi.NET  2020-12-29
*/

#include <Arduino.h>
#define LEDBEAMHEADLIGHT 13

int sensorPinLDR = A2; // select the input pin for LDR

int sensorValue = 0; // variable to store the value coming from the sensor

void setupAutoBeamHeadlight()
{
  pinMode(LEDBEAMHEADLIGHT, OUTPUT); // select the input pin for LDR
}
void autoBeamHeadlight()
{
  sensorValue = analogRead(sensorPinLDR); // read the value from the sensor LDR
  if (sensorValue < 500)
  {
    digitalWrite(LEDBEAMHEADLIGHT, HIGH);
    //delay(2);
  }
  else
  {
    digitalWrite(LEDBEAMHEADLIGHT, LOW);
    //delay(1);
  }
}