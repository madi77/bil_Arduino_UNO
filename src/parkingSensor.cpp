/*
Ultrasonic Distance Sensor - HC-SR04
by codedByMadi.NET  2020-12-29
*/

#include <Arduino.h>

const int trigPin = 10;
const int echoPin = 11;

float duration, distance;

void setupParkingSensor(int buzzePin)
{
    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT);
    pinMode(buzzePin, OUTPUT);
}

void parkingSensor(int buzzePin)
{
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);

    duration = pulseIn(echoPin, HIGH);
    distance = (duration * .0343) / 2;

    if (distance < 12 && distance > 8)
    {
        digitalWrite(buzzePin, HIGH);
        delay(300);
        digitalWrite(buzzePin, LOW);
        delay(300);
    }
    if (distance < 8 && distance > 5)
    {
        digitalWrite(buzzePin, HIGH);
        delay(150);
        digitalWrite(buzzePin, LOW);
        delay(150);
    }
    if (distance < 5)
    {
        digitalWrite(buzzePin, HIGH);
        delay(15);
    }
}
