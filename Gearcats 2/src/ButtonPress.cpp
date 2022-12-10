#include "main.h"
#include "other.h"

void ButtonAPress(pros::Motor left, pros::Motor right, pros::Motor middle) {}
void ButtonBPress(pros::ADIDigitalOut piston) { piston.set_value(false); }
