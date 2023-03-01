
#include "main.h"
void PuncherMove(pros::Motor mtr, bool reverse) {
  if (reverse) {
    mtr = -327;
  } else {
    mtr = 327;
  }
}
void PuncherStopp(pros::Motor mtr) { mtr.brake(); }