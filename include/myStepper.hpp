/*
28BYJ-48 stepper motor and ULN2003
by codedByMadi.NET  2020-12-28
*/

int read_Joystick_VRY_Val();

void mySteppMover_Stop();

void mySteppMover_Forward(int joystick_VRY_Val);

void mySteppMover_Backward(int joystick_VRY_Val);