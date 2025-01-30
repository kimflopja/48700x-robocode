#pragma once

#include "api.h"

/*
* Controller
*/
extern pros::v5::Controller controller_master;


/*
* Drivetrain motors
*/

extern pros::Imu inertial;

extern pros::Motor left_motor1;
extern pros::Motor left_motor2;        
extern pros::Motor left_motor3;

extern pros::Motor right_motor1;
extern pros::Motor right_motor2;     
extern pros::Motor right_motor3;

extern pros::MotorGroup left_mg;
extern pros::MotorGroup right_mg;

/*
* Subsystem motors
*/

extern pros::Motor lift;     

extern pros::Motor intake;

/*
* Pneumatics
*/


extern pros::adi::Pneumatics clamp_piston;  // Clamp piston
extern pros::adi::Pneumatics latch_piston; // Latch
// Swithc
extern pros::adi::Pneumatics switchBlade1;
extern pros::adi::Pneumatics switchBlade2;



/*
* Sensors
*/




/*
* Misc, for enums and such
*/

extern int autonChosen;
extern int autonSel;

// Enum for the latch
enum Latch{
  extended,
  retracted,
};

// Enum for the clamp
enum Clamp {
  unclamp,
  clamp,
};

// int for auton selector
extern int SelectedAuton;