#include "main.h"

/**
 * A callback function for LLEMU's center button.
 *
 * When this callback is fired, it will toggle line 2 of the LCD text between
 * "I was pressed!" and nothing.
 */
std::string autoNames[] 
= {"Skills", "Far Side", "Far Side Mirrored", "Close Side", "Close Side Mirrored"};
int SelectedAuton = 0;

void on_center_button() {
	static bool pressed = false;
	pressed = !pressed;
	if (pressed) {
		pros::lcd::set_text(2, autoNames[SelectedAuton]);
		if(SelectedAuton < 5) SelectedAuton++;
		else SelectedAuton--;
	} 
}



/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */
void initialize() {
	pros::lcd::initialize();
	pros::lcd::set_text(1, "nightcord at 25");

	

	// Tare Position //
	lift.tare_position(); // Set ABS lift position to ZERO
	setLift(0);
	intake.tare_position(); // Set ABS lift position to ZERO
	// Calibrate //
	inertial.reset(true);
	while(inertial.is_calibrating()){
		pros::delay(100);
	}
	

	// Set Motor Brakes to ____
	// Drivetrain: COAST
	left_motor1.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
	left_motor2.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
	left_motor3.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
	right_motor1.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
	right_motor2.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
	right_motor3.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
	// Intake:
	intake.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
	// Lift:
	lift.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);

	// Clear arm
	setClearArm(2);

	// Delay
	pros::delay(100);
}


/**
 * Runs after initialize(), and before autonomous when connected to the Field
 * Management System or the VEX Competition Switch. This is intended for
 * competition-specific initialization routines, such as an autonomous selector
 * on the LCD.
 *
 * This task will exit when the robot is enabled and autonomous or opcontrol
 * starts.
 */
void competition_initialize() { 
	// auton sel
	pros::lcd::register_btn1_cb(on_center_button);

	
}