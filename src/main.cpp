#include <Arduino.h>
#include <myServo.hpp>
#include <myStepper.hpp>
#include <autoBeamHeadlight.hpp>
#include <parkingSensor.hpp>

const int buzzePin = 3;

int main()
{

  init(); // needed for things like clocks, timers and uart

  setupMyServo(buzzePin);

  setupAutoBeamHeadlight();
  setupParkingSensor(buzzePin);

  while (1)
  {
    myServoMover();
    joystick_Swich_Buzzer(buzzePin);
    autoBeamHeadlight();
    parkingSensor(buzzePin);

    int val_VRY = read_Joystick_VRY_Val();

    if (val_VRY <= 450)
    {
      mySteppMover_Forward(val_VRY);
    }
    else if (val_VRY >= 550)
    {
      mySteppMover_Backward(val_VRY);
    }
    else
    {
      mySteppMover_Stop();
    }
  }
  return 0;
}
