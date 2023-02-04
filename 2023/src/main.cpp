#include "main.h"
#include "Functions.h"
#include "Roller.h"
#include "config.cpp"
#include "flywheel.h"
#include "intake.h"
// Motor definitions
pros::Motor left_mtr2(DRIVETRIAN_DL, true);
pros::Motor left_mtr(DRIVETRIAN_DR, true);
pros::Motor right_mtr(DRIVETRIAN_UR);
pros::Motor right_mtr2(DRIVETRIAN_UL);
pros::Motor intakeMotor(INTAKE_MOTOR);
pros::Motor puncher(PUNCHER_PORT);
pros::Motor roller(ROLLER_MOTOR);
pros::Motor endgame(ENDGAME_PORT);
/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */
void initialize() {
  pros::lcd::initialize();
  pros::lcd::set_text(1, "[i] Init");
  // pros::lcd::register_btn1_cb(on_center_button);
}

/**
 * Runs while the robot is in the disabled state of Field Management System or
 * the VEX Competition Switch, following either autonomous or opcontrol. When
 * the robot is enabled, this task will exit.
 */
void disabled() { pros::lcd::set_text(1, "[i] Disabled"); }

/**
 * Runs after initialize(), and before autonomous when connected to the Field
 * Management System or the VEX Competition Switch. This is intended for
 * competition-specific initialization routines, such as an autonomous selector
 * on the LCD.
 *
 * This task will exit when the robot is enabled and autonomous or opcontrol
 * starts.
 */
void competition_initialize() { pros::lcd::set_text(1, "[i] Comp Init"); }

/**
 * Runs the user autonomous code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the autonomous
 * mode. Alternatively, this function may be called in initialize or opcontrol
 * for non-competition testing purposes.
 *
 * If the robot is disabled or communications is lost, the autonomous task
 * will be stopped. Re-enabling the robot will restart the task, not re-start it
 * from where it left off.
 */
void DriveForwardFor(int time) {
  left_mtr = 127;
  right_mtr = 127;
  pros::delay(time);
  left_mtr.brake();
  right_mtr.brake();
}
void BrakeDrivetrain() {
  left_mtr2.brake();
  right_mtr2.brake();
  left_mtr.brake();
  right_mtr.brake();
}
// * true = right
// * false = left
void Turn(bool direction) {
  if (direction) {
    left_mtr2 = 127;
    right_mtr2 = 127;
  } else {
    left_mtr2 = -127;
    right_mtr2 = -127;
  }
  pros::delay(1000);
  left_mtr2.brake();
  right_mtr2.brake();
}
void autonomous() {
  pros::lcd::set_text(1, "[i] autonomous");
  DriveForwardFor(2000);
  Turn(true);
}

/**
 * * Runs the operator control code. This function will be started in its own
 * task with the default priority and stack size whenever the robot is enabled
 * via the Field Management System or the VEX Competition Switch in the operator
 * control mode.
 *
 * If no competition control is connected, this function will run immediately
 * following initialize().
 *
 * If the robot is disabled or communications is lost, the
 * operator control task will be stopped. Re-enabling the robot will restart the
 * task, not resume it from where it left off.
 */
void opcontrol() {
  pros::Controller master(pros::E_CONTROLLER_MASTER);

  pros::lcd::set_text(1, "[i] op control");

  while (true) {
    int left = master.get_analog(ANALOG_LEFT_Y);
    int right = master.get_analog(ANALOG_RIGHT_Y);

    left_mtr = -left;
    left_mtr2 = left;
    right_mtr2 = right;
    right_mtr = -right;
    // Handle Button
    ButtonsPressHandle(master, intakeMotor, puncher, roller);

    // if (master.get_digital(pros::E_CONTROLLER_DIGITAL_A)) {
    //   IntakeMove(intakeMotor, intakeMotor2, intakeMotor3);
    // } else {
    //   IntakeStop(intakeMotor, intakeMotor2, intakeMotor3);
    // }
    // if (master.get_digital(pros::E_CONTROLLER_DIGITAL_R1)) {
    //   RollerMove(roller, false);
    // } else {
    //   RollerStopp(roller);
    // }
    // if (master.get_digital(pros::E_CONTROLLER_DIGITAL_L1)) {
    //   RollerMove(roller, true);
    // } else {
    //   RollerStopp(roller);
    // }
    pros::delay(20);
  }
}
