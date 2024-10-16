> [!WARNING]
> 🚧 This code is old and is no longer maintained.🚧
# 62885A's Vex Spin Up Code

Has the following amazing features

- X-Drive
- Intake System.
- Puncher.

Built using C++, PROS.

## File Structure

`src/` contains all our code, seprated by file.  
`include/` contains the PROs library.  
`firmware/` contains the PROs static library.

### `src/main.cpp`

The main section which is initiated by the robot which handles autonomous, driving functions and all button functions.

### `src/Puncher.cpp`

Contains the functions to run the puncher within the robot.

### `src/Roller.cpp`

Contains the functions to run the Roller within the robot.

### `src/Functions.cpp`

Contains all the button functions for the robot which also includes all of the Roller, Puncher and intake functions.

### `src/intake.cpp`

Contains the code related to the intake motors and functions.

### `src/config.cpp`

Contains all the configuration for ports.
