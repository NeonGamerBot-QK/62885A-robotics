
#include "main.h"
void FlywheelMove(pros::Motor mtr, pros::Motor mtr2) {
  mtr = 127;
  mtr2 = 127;
}
void FlywheelStop(pros::Motor mtr, pros::Motor mtr2) {
  mtr.brake();
  mtr2.brake();
}