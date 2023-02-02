
#include "main.h"
void PuncherMove(pros::Motor mtr, bool reverse) {
  if (reverse) {
    mtr = -127;
  } else {
    mtr = 127;
  }
}
void PuncherStopp(pros::Motor mtr) { mtr.brake(); }