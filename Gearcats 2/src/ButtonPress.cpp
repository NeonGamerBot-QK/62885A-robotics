#include "main.h"
#include "other.h"
#include <iostream>

void ButtonAPress(pros::Motor left, pros::Motor right, pros::Motor middle) {
  middle.move(127);
  left.move(127);
  right.move(127);
}
void ButtonBPress(pros::ADIDigitalOut piston) {
  piston.set_value(true);
  pros::delay(1000);
  piston.set_value(false);
}
// // void development(bool isDevelopment, bool isProd) {
// //     isDevelopment = true;
// //     isProd = false;
// // }
// // void production(bool isDevelopment, bool isProd) {
// //     isDevelopment = false;
// //     isProd = true;
// // }
// // void clear(bool isDevelopment, bool isProd) {
// //     isDevelopment = false;
// //     isProd = false;
// // }
// // void LCDButtonPress(int num, bool isDevelopment, bool isProd) {
// //  pros::lcd::print(6, "%d y", num);
// //     switch (num)
// //     {
// //     case LCD_BTN_CENTER:
// //     clear(isDevelopment, isProd);
// //         break;
// //     case LCD_BTN_RIGHT:
// // production(isDevelopment,isProd);
// //     break;
// //      case LCD_BTN_LEFT:
// //     development(isDevelopment,isProd);
// //      break;
// //     default:
// //         break;
// //     }
// // }