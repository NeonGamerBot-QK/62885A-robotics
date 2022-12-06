#include "Puncher.h"
#include "main.h"

void initPuncher() {}

void runPuncher(pros::Motor mtr) {
  mtr = 127;
  pros::delay(2000);
  mtr.brake();
}