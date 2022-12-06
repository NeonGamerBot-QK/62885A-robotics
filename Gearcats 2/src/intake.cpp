#include "intake.h"
#include "main.h"

void initIntake() {}
void moveIntake(pros::Motor mtr) { mtr = 127; }
void stopIntake(pros::Motor mtr) { mtr.brake(); }