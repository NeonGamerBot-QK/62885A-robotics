/**
 * @note read the README.md and for bugs that should not exist read BUGS.md
 */

//@ignore this error its werid
#include "main.h"
#include "Puncher.h"
#include "config.h"
#include "intake.h"
#include "other.h"
#include "pros/adi.h"
#include "pros/adi.hpp"
#include "pros/misc.h"
#include "pros/rtos.hpp"
pros::Motor Puncher(PUNCHER_PORT, true);
// Intake motors
pros::Motor Intake1(INTAKE_PORT1, true);
pros::Motor Intake2(INTAKE_PORT2, true);
pros::Motor Intake3(INTAKE_PORT3, true);
// Controller
pros::Controller master(pros::E_CONTROLLER_MASTER);
pros::ADIDigitalOut Piston(PISTON_PORT);

pros::Motor left_mtr1(DRIVE_TRAIN_WHEEL_1_PORT);
pros::Motor left_mtr2(DRIVE_TRAIN_WHEEL_2_PORT);
pros::Motor right_mtr1(DRIVE_TRAIN_WHEEL_3_PORT, true);
pros::Motor right_mtr2(DRIVE_TRAIN_WHEEL_4_PORT, true);
pros::Motor middle_mtr(DRIVE_TRAIN_WHEEL_5_PORT);
bool isDevelopment = false;
bool isProd = false;

// utils
double mapValue(double value, double istart, double istop, double ostart,
                double ostop) {
  return ostart + (ostop - ostart) * ((value - istart) / istop - istart);
}
/**
 * * A callback function for LLEMU's center button.
 *
 * * When this callback is fired, it will toggle line 2 of the LCD text between
 * * "I was pressed!" and nothing.
 */
void on_center_button() {
  static bool pressed = false;
  pressed = !pressed;
  if (pressed) {
    pros::lcd::set_text(2, "I was pressed!");
  } else {
    pros::lcd::clear_line(2);
  }
}
/**
 * * Runs initialization code. This occurs as soon as the program is started.
 *
 * * All other competition modes are blocked by initialize; it is recommended
 * ! to keep execution time for this mode under a few seconds.
 */
void initialize() {
  pros::lcd::initialize();
  // pros::lcd::set_background_color(COLOR_GOLD);
  pros::lcd::print(4, "disabled = false");
  pros::lcd::print(1, "battery temp:  %d, battery \% %d",
                   pros::battery::get_temperature(),
                   pros::battery::get_voltage());

  // //  pros::lcd::register_btn1_cb(on_center_button);
}

/**
 * Runs while the robot is in the disabled state of Field Management System or
 * the VEX Competition Switch, following either autonomous or opcontrol. When
 * the robot is enabled, this task will exit.
 */
void disabled() { pros::lcd::print(4, "Disabled = true"); }

/**
 * Runs after initialize(), and before autonomous when connected to the Field
 * Management System or the VEX Competition Switch. This is intended for
 * competition-specific initialization routines, such as an autonomous selector
 * on the LCD.
 *
 * This task will exit when the robot is enabled and autonomous or opcontrol
 * starts.
 */
void competition_initialize() { pros::lcd::print(3, "Competition init"); }

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
void autonomous() {
  /**
   * @ref {https://content.vexrobotics.com/images/CompetitionV2/SpinUpField.jpg}
   * @note Example img of field used for this code.
   * * URL https://content.vexrobotics.com/images/CompetitionV2/SpinUpField.jpg
   */
}

/**
 * Runs the operator control code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the operator
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

  while (true) {

    pros::lcd::print(2, "%d center = %d", pros::lcd::read_buttons(),
                     LCD_BTN_CENTER);
    int left = master.get_analog(ANALOG_LEFT_Y);
    int right = master.get_analog(ANALOG_RIGHT_Y);
    // Move the drivetrain

    // left_mtr.move_velocity

    if (master.get_digital(pros::E_CONTROLLER_DIGITAL_A)) {
      // Toggle pneumatics or other similar actions
      runPuncher(Puncher);
    } else {
      Puncher.brake();
    }
    if (master.get_digital(pros::E_CONTROLLER_DIGITAL_B)) {
      ButtonBPress(Piston);
    } else {
      Piston.set_value(true);
    }
    if (master.get_digital(pros::E_CONTROLLER_DIGITAL_X)) {
      autonomous();
    }
    if (master.get_digital(pros::E_CONTROLLER_DIGITAL_R2)) {
      moveIntake(Intake1, Intake2, Intake3);
    } else {
      stopIntake(Intake1, Intake2, Intake3);
    }
    pros::delay(20);
  }
}
