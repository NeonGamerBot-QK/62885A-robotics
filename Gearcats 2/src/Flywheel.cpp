#include "main.h"
#include "Flywheel.h"
void initFlywheel() {}


void runFlywheel(pros::Motor mtr) {
mtr = 127;
pros::delay(2000);
mtr.brake();
}