#include "Flywheel.h"
#include "main.h"

void initFlywheel() {}

void runFlywheel(pros::Motor mtr) {
  mtr = 127;
  pros::delay(2000);
  mtr.brake();
}