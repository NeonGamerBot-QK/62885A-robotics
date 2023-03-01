#include "Roller.h"
#include "flywheel.h"
#include "intake.h"
#include "main.h"
void ButtonACb(pros::Controller master, pros::Motor intakeMotor);
void ButtonBCb(pros::Controller master, pros::Motor intakeMotor);
void ButtonR1press(pros::Controller master, pros::Motor roller);
void ButtonL1press(pros::Controller master, pros::Motor roller);
void ButtonXpress(pros::Controller master, pros::Motor roller);
void ButtonYpress(pros::Controller master, pros::Motor roller);
void ButtonsPressHandle(pros::Controller master, pros::Motor intakeMotor,
                        pros::Motor puncher, pros::Motor roller,
                        pros::Motor endgame);