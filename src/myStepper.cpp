/*
28BYJ-48 stepper motor and ULN2003
by codedByMadi.NET  2020-12-28
*/

#include <Arduino.h>
#include <Stepper.h>

#define STEPS 32

// define stepper motor control pins
#define IN1 7
#define IN2 6
#define IN3 5
#define IN4 4

// initialize stepper library
Stepper stepper(STEPS, IN4, IN2, IN3, IN1);

// joystick VRY is connected to Arduino A0 like input.
const int joystick_VRY = A0;

int joystick_VRY_Val; // variable to read the value from the analog pin

int read_Joystick_VRY_Val()
{
    int joystick_VRY_Val = analogRead(joystick_VRY);
    return joystick_VRY_Val;
}

// if the joystic is in the middle ===> stop the motor
void mySteppMover_Stop()
{
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, LOW);
}

void mySteppMover_Forward(int joystick_VRY_Val)
{
    // map the speed between 5 and 500 rpm
    int speed_ = map(joystick_VRY_Val, 450, 0, 5, 500);

    // set motor speed
    stepper.setSpeed(speed_);

    // move the motor (5 step)
    stepper.step(5);

    joystick_VRY_Val = read_Joystick_VRY_Val();
}

void mySteppMover_Backward(int joystick_VRY_Val)
{

    // map the speed between 5 and 500 rpm
    int speed_ = map(joystick_VRY_Val, 550, 1023, 5, 500);

    // set motor speed
    stepper.setSpeed(speed_);

    // move the motor (2 step)
    stepper.step(-2);

    joystick_VRY_Val = read_Joystick_VRY_Val();
}