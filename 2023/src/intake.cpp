
#include "main.h"
void IntakeMove(pros::Motor mtr) { mtr = 127; }
void IntakeReverse(pros::Motor mtr) { mtr = -100; }
void IntakeStop(pros::Motor mtr) { mtr.brake(); }