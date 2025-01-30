#include "main.h"

// r2 (intake down)
// r1 (intake up)
// Hit button to have it run
// Top button run, bottom button run reverse. 
// Hit same button to stop it

bool buttonPressed = false; 
bool intakeMove = false;
bool intakeMoveRev = false;


void IntakeFunction(){
    if(controller_master.get_digital(pros::E_CONTROLLER_DIGITAL_R1) && !buttonPressed){
        buttonPressed = true;
        intakeMoveRev = !intakeMoveRev;
        intakeMove = false;
    }
    else if(!controller_master.get_digital(pros::E_CONTROLLER_DIGITAL_R1)){
        buttonPressed = false;
    }

    if(controller_master.get_digital(pros::E_CONTROLLER_DIGITAL_R2) && !buttonPressed){
        buttonPressed = true;
        intakeMove = !intakeMove;
        intakeMoveRev = false;
    }
    else if(!controller_master.get_digital(pros::E_CONTROLLER_DIGITAL_R1)) {
        buttonPressed = false;
    }


    if(intakeMove){
        intake.move(100); // Change THIS to change the speed.
    }
    else if(intakeMoveRev) {
        intake.move(-100); // And THIS to change the speed.
    }
    else intake.move(0); // Do NOT change this.
}