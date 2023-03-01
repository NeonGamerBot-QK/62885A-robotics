
#include "main.h"
void RollerMove(pros::Motor mtr, bool reverse) {
  if (reverse) {
    mtr = -127;
  } else {
    mtr = 127;
  }
}
void RollerStopp(pros::Motor mtr) { mtr.brake(); }