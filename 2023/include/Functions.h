#include "Roller.h"
#include "flywheel.h"
#include "intake.h"
#include "main.h"
void ButtonACb(pros::Controller master, pros::Motor intakeMotor,
               pros::Motor intakeMotor2, pros::Motor intakeMotor3);
void ButtonR1press(pros::Controller master, pros::Motor roller);
void ButtonL1press(pros::Controller master, pros::Motor roller);
void ButtonsPressHandle(pros::Controller master, pros::Motor intakeMotor,
                        pros::Motor intakeMotor2, pros::Motor intakeMotor3,
                        pros::Motor roller);