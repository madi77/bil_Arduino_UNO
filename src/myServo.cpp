/*
SG90 Mini Gear Micro Servo
by codedByMadi.NET  2020-12-27
*/

#include <Arduino.h>
#include <Servo.h>

int joystickSwichStatus = 0;

const int joystick_VRX = A1, servoPin = 9, joystickSwich = 8;
Servo myservo;        // create servo object to control a servo
int joystick_VRX_Val; // variable to read the value from the analog pin

void setupMyServo(int buzzePin)
{
    pinMode(joystick_VRX, INPUT);         // sets the analog pin A1 as input
    pinMode(joystickSwich, INPUT_PULLUP); // sets the digital pin 8 as input with pullup resistor
    pinMode(servoPin, OUTPUT);            // sets the digital pin 9 as output
    pinMode(buzzePin, OUTPUT);            // sets the digital pin 3 as output

    myservo.attach(servoPin); // attaches the servo on pin 9 to the servo object
}

void myServoMover()
{
    joystick_VRX_Val = analogRead(joystick_VRX);               // reads the value of the joystick_VRX (value between 0 and 1023)
    joystick_VRX_Val = map(joystick_VRX_Val, 0, 1023, 0, 180); // scale it to use it with the servo (value between 0 and 180)
    myservo.write(joystick_VRX_Val);
    Serial.println(joystick_VRX_Val);
}

void joystick_Swich_Buzzer(int buzzePin)
{
    // reads the value of the joystickSwich and swapping 0 to 1 and 1 to 0
    joystickSwichStatus = (!digitalRead(joystickSwich));

    // activate buzzer if joystickSwichStatus = 1
    digitalWrite(buzzePin, HIGH);

    if (joystickSwichStatus == 0)
    {
        digitalWrite(buzzePin, LOW);
    }

    joystickSwichStatus = (!digitalRead(joystickSwich));
}