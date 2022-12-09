/**
 * @note read the README.md and for bugs that should not exist read BUGS.md
 */

//@ignore this error its werid
#include "main.h"
#include "Puncher.h"
#include "intake.h"
#include "other.h"
#include "pros/adi.h"
#include "pros/adi.hpp"
#include "pros/rtos.hpp"

// * define the motor ports here
#define CONTROLLER_PORT 21
pros::Motor PUNCHER(10);
pros::Motor Intake(13);
pros::Controller master(pros::E_CONTROLLER_MASTER);
pros::ADIDigitalOut Piston('A');
#define BUTTON(x) if (master.get_digital_new_press(x))
#define HELD(x) if (master.get_digital(x))
pros::Motor left_mtr(1, true);
pros::Motor right_mtr(2);

bool isDevelopment = false;
bool isProd = false;

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
  moveIntake(Intake);
  left_mtr = 127;
  right_mtr = 127;
  pros::delay(1000);
  left_mtr.brake();
  right_mtr.brake();
  left_mtr = 120;
  pros::delay(200);
  left_mtr.brake();
  left_mtr = 127;
  right_mtr = 127;
  pros::delay(1500);
  left_mtr.brake();
  right_mtr.brake();
  left_mtr = 120;
  pros::delay(500);
  left_mtr.brake();
  left_mtr = 127;
  right_mtr = 127;
  pros::delay(1500);
  left_mtr.brake();
  right_mtr.brake();
  stopIntake(Intake);
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
    // LCDButtonPress(pros::lcd::read_buttons(), isDevelopment, isProd);
    // if(!isDevelopment && !isProd) {
    // // pros::delay(20);
    // 	return;
    // } else if (isProd && !isDevelopment) {
    left_mtr = left;
    right_mtr = right;
    if (master.get_digital(pros::E_CONTROLLER_DIGITAL_A)) {
      // Toggle pneumatics or other similar actions
      runPuncher(PUNCHER);
    } else {
    }
    if (master.get_digital(pros::E_CONTROLLER_DIGITAL_B)) {
      ButtonBPress(Piston);
    } else {
      Piston.set_value(true);
    }
    if (master.get_digital(pros::E_CONTROLLER_DIGITAL_X)) {
      autonomous();
    }
    // } else if(isDevelopment && !isProd) {
    // 	//dev code here
    // }
    pros::delay(20);
  }
}
