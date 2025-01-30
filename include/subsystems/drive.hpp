#pragma once

#include <bits/stdc++.h>
#include <stdio.h>
#include <string.h>

#include "api.h"

/*
*
* ///////////////// Movement Functions :3 ///////////////// 
* 
*/



//////           //////
/// Opcontrol usage ///
//////           //////



/*
* Set the motors to a value
*/
void setDrive(int leftJoystick, int rightJoystick);

/*
* Set the motors to a value for ARCADE
*/
void setArcadeDrive(int rotate, int drive);

/*
* Set the motors to a value (VOLTAGE)
*/
void setDriveVoltage(int leftMoveVoltage, int rightMoveVoltage);

/*
* Tank drive
*/
void tankDrive();

/*
* Arcade drive
*/
void arcadeDrive();



//////       //////
/// Auton usage ///
//////       //////



/*
* Drive auton
*/
void auton_drive(int goal, int speed);



/*
* Drive turn
*/
void auton_turn(int degrees, int speed);


/*
* Drive swing
*/
void auton_swing(int degrees, int units, int speed);

/*
* Drive PID algo
*/
void drivePID();





/*
*
* ///////////////// Telemetry Functions :3 ///////////////// 
* 
*/

/*
* sets the zero point of the motors to the current position
*/
void resetDriveEncoders();

/*
* Gets the avg drive pos
*/
double avgDriveEncoderValue();

/*
* Get left position
*/
double getLeftPosition();

/*
* Get left position
*/
double getRightPosition();

/*
* Reset PID
*/
void resetPID();