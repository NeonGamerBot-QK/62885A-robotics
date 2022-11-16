/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       Saahil                                               */
/*    Created:      11/12/2022, 9:18:51 AM                                    */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/
#pragma region VEXcode Generated Robot Configuration
// Make sure all required headers are included.
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>


#include "vex.h"

using namespace vex;

// Brain should be defined by default
brain Brain;


// START V5 MACROS
#define waitUntil(condition)                                                   \
  do {                                                                         \
    wait(5, msec);                                                             \
  } while (!(condition))

#define repeat(iterations)                                                     \
  for (int iterator = 0; iterator < iterations; iterator++)
// END V5 MACROS


// Robot configuration code.
motor Motor2 = motor(PORT2, ratio18_1, false);
motor Motor3 = motor(PORT3, ratio18_1, false);
motor FlywheelMotor1 = motor(PORT4, ratio36_1, true);
motor FlywheelMotor2 = motor(PORT5, ratio18_1, true);
motor FlywheelMotor3 = motor(PORT7, ratio18_1, true);



#pragma endregion VEXcode Generated Robot Configuration

#include "vex.h"
// A global instance of competition
competition Competition;
controller Controller;
// The logging system
// void logInBrain(input string) {
// }
// define your global instances of motors and other devices here

/*---------------- -----------------------------------------------------------*/
/*                          Pre-Autonomous Functions                         */
/*                                                                           */
/*  You may want to perform some actions before the competition starts.      */
/*  Do them in the following function.  You must return from this function   */
/*  or the autonomous and usercontrol tasks will not be started.  This       */
/*  function is only called once after the V5 has been powered on and        */
/*  not every time that the robot is disabled.                               */
/*---------------------------------------------------------------------------*/

void pre_auton(void) {

  // All activities that occur before the competition starts
  // Example: clearing encoders, setting servo positions, ...

}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              Autonomous Task                              */
/*                                                                           */
/*  This task is used to control your robot during the autonomous phase of   */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

void autonomous(void) {
  // ..........................................................................
  // Insert autonomous user code here.
  // ..........................................................................

}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              User Control Task                            */
/*                                                                           */
/*  This task is used to control your robot during the user control phase of */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/
int timesPressed = 0;
void buttonPress(){
    timesPressed++;//add one to timesPressed
    // Controller.Screen.clearScreen();
    FlywheelMotor3.spin(forward, 60.0, volt);
    FlywheelMotor1.spin(reverse, 60.0, volt);
    FlywheelMotor2.spin(forward, 60.0, volt);

    Brain.Screen.print("Pressed A Button %i Times\n", timesPressed);//prints how many times Button A was pressed to the controller's screen
}
void stopA(void) {
  FlywheelMotor3.stop();
FlywheelMotor1.stop();
FlywheelMotor2.stop();
}
void testing() {
    FlywheelMotor3.spin(forward, 60.0, volt);
}
void usercontrol(void) {
  // User control code here, inside the loop
    Controller.ButtonA.pressed(buttonPress);
    Controller.ButtonA.released(stopA);
Controller.ButtonB.pressed(testing);
  while (1) {
    // This is the main execution loop for the user control program.
    // Each time through the loop your program should update motor + servo
    // values based on feedback from the joysticks.

    // ........................................................................
    // Insert user code here. This is where you use the joystick values to
    // update your motors, etc.
    // ........................................................................

    wait(20, msec); // Sleep the task for a short amount of time to
                    // prevent wasted resources.
  }
}

//
// Main will set up the competition functions and callbacks.
//
int main() {
    //  Brain.Screen.print("Hello");
  // Set up callbacks for autonomous and driver control periods.

  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);
Brain.Screen.print("Hi");
// Motor2.spin(forward, 60.0, volt);
Motor2.spin(forward, 5.0, volt);
Motor3.spin(reverse, 5.0, volt);
Brain.Screen.print(Motor2.temperature(celsius));
wait(4000, msec);
Motor2.stop();
 Motor3.stop();
// //  Drivetrain.setDriveVelocity(100, percent);
// //   Drivetrain.setTurnVelocity(20, percent);

// //   Drivetrain.driveFor(reverse, 50, mm);
// //   Drivetrain.turnFor(left, 45, degrees);
// //   Drivetrain.driveFor(forward, 3, inches);
// //   Drivetrain.stop();
  // Run the pre-autonomous function.
  pre_auton();

  // Prevent main from exiting with an infinite loop.
  while (true) {
    wait(100, msec);
  }
}
