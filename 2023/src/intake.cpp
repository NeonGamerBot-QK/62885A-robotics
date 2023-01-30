
#include "main.h"
void IntakeMove(pros::Motor mtr, pros::Motor mtr2, pros::Motor mtr3) {
  mtr = 127;
  mtr3 = 127;
  mtr2 = -127;
}
void IntakeStop(pros::Motor mtr, pros::Motor mtr2, pros::Motor mtr3) {
  mtr.brake();
  mtr2.brake();
  mtr3.brake();
}