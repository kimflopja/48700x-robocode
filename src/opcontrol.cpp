#include "main.h"



/**
 * Runs while the robot is in the disabled state of Field Management System or
 * the VEX Competition Switch, following either autonomous or opcontrol. When
 * the robot is enabled, this task will exit.
 */
void disabled() {
	// ...
}



/**
 * OP control for Skills.
 */

void SkillsOpControl(){
	lift_funcL1(); // L1/L2 Lift
	clampPistonArrows(); // Arrows Clamp
}

/**
 * OP control for HTH.
 */


void HTHOpControl(){
	lift_funcArrows(); // Arrows Lift
	clampPistonL1(); // L1/L2 Clamp
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

	while (true) {
		pros::lcd::print(0, "%d %d %d", (pros::lcd::read_buttons() & LCD_BTN_LEFT) >> 2,
		                 (pros::lcd::read_buttons() & LCD_BTN_CENTER) >> 1,
		                 (pros::lcd::read_buttons() & LCD_BTN_RIGHT) >> 0);  // Prints status of the emulated screen LCDs

		// Arcade control scheme
		// int dir = controller_master.get_analog(ANALOG_LEFT_Y);    // Gets amount forward/backward from left joystick
		// int turn = controller_master.get_analog(ANALOG_RIGHT_X);  // Gets the turn left/right from right joystick
		
		tankDrive(); // Tank Drive
		HTHOpControl(); // HTH
		//SkillsOpControl(); // Skills

		clear_arm(); // Clear arm
		latch_func(); // Latch
		IntakeFunction(); // intake

		

		pros::delay(20);                               // Run for 20 ms then update
	}
}