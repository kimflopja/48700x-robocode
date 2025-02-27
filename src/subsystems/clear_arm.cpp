#include "main.h"

bool buttonRegistered = false;
int armState = 2;

/**
* The SWITCHBLADE.
*/
void setClearArm(int armState){
    switch (armState) {
        case 0: // initial press
            switchBlade1.extend();
            switchBlade2.retract(); // 
            break;
        case 1: // intake off, arm out
            switchBlade1.extend();
            switchBlade2.extend();
            intake.brake();
            break;
        case 2: // intake on, arm in
            switchBlade1.retract();
            switchBlade2.retract();
            break;
    }
}

void clear_arm(){
    if(controller_master.get_digital(pros::E_CONTROLLER_DIGITAL_X) && !buttonRegistered) { // Up
        if(armState == 1) armState = 2;
        else if(armState == 0) armState = 1;
        else if (armState == 2) armState = 1;
        buttonRegistered = true;
  } else if(!controller_master.get_digital(pros::E_CONTROLLER_DIGITAL_X)) buttonRegistered = false;

  setClearArm(armState);
  pros::delay(50); // Delay

}

