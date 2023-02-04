#include "Puncher.h"
#include "Roller.h"
#include "config.cpp"
#include "flywheel.h"
#include "intake.h"
#include "main.h"

void ButtonACb(pros::Controller master, pros::Motor intakeMotor) {
  if (master.get_digital(pros::E_CONTROLLER_DIGITAL_A)) {
    IntakeMove(intakeMotor);
  } else {
    IntakeStop(intakeMotor);
  }
}
void ButtonBCb(pros::Controller master, pros::Motor intakeMotor) {
  if (master.get_digital(pros::E_CONTROLLER_DIGITAL_B)) {
    IntakeReverse(intakeMotor);
  } else {
    IntakeStop(intakeMotor);
  }
}
void ButtonXpress(pros::Controller master, pros::Motor roller) {
  if (master.get_digital(pros::E_CONTROLLER_DIGITAL_X)) {
    PuncherMove(roller, false);
  } else {
    PuncherStopp(roller);
  }
}
void ButtonR1press(pros::Controller master, pros::Motor roller) {
  if (master.get_digital(pros::E_CONTROLLER_DIGITAL_R1)) {
    RollerMove(roller, false);
  } else {
    RollerStopp(roller);
  }
}
void ButtonL1press(pros::Controller master, pros::Motor roller) {
  if (master.get_digital(pros::E_CONTROLLER_DIGITAL_L1)) {
    RollerMove(roller, true);
  } else {
    RollerStopp(roller);
  }
}
void ButtonYpress(pros::Controller master, pros::Motor mtr) {
  if (master.get_digital(pros::E_CONTROLLER_DIGITAL_Y)) {
    mtr = 127;
    pros::delay(200);
    mtr.brake();
  } else {
    mtr.brake();
  }
}
void ButtonsPressHandle(pros::Controller master, pros::Motor intakeMotor,
                        pros::Motor puncher, pros::Motor roller,
                        pros::Motor endgame) {
  if (master.get_digital(pros::E_CONTROLLER_DIGITAL_A) &&
      master.get_digital(pros::E_CONTROLLER_DIGITAL_B)) {
  }

  ButtonACb(master, intakeMotor);
  ButtonBCb(master, intakeMotor);
  ButtonYpress(master, endgame);
  ButtonR1press(master, roller);
  ButtonL1press(master, roller);
  ButtonXpress(master, puncher);
}
