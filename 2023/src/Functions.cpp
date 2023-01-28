#include "Roller.h"
#include "config.cpp"
#include "flywheel.h"
#include "intake.h"
#include "main.h"
void ButtonACb(pros::Controller master, pros::Motor intakeMotor,
               pros::Motor intakeMotor2, pros::Motor intakeMotor3) {
  if (master.get_digital(pros::E_CONTROLLER_DIGITAL_A)) {
    IntakeMove(intakeMotor, intakeMotor2, intakeMotor3);
  } else {
    IntakeStop(intakeMotor, intakeMotor2, intakeMotor3);
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
void ButtonsPressHandle(pros::Controller master, pros::Motor intakeMotor,
                        pros::Motor intakeMotor2, pros::Motor intakeMotor3,
                        pros::Motor roller) {
  ButtonACb(master, intakeMotor, intakeMotor2, intakeMotor3);
  ButtonR1press(master, roller);
  ButtonL1press(master, roller);
}
