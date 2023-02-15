
#include "main.h"
void IntakeMove(pros::Motor mtr) { mtr = 327; }
void IntakeReverse(pros::Motor mtr) { mtr = -327; }
void IntakeStop(pros::Motor mtr) { mtr.brake(); }