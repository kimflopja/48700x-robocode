#include "main.h"

/**
* The LATCH.
*/


void setLatch(Latch latchState){
  switch (latchState){
    case extended:
      latch_piston.retract(); // EXTENDS
    case retracted:
      latch_piston.extend(); // RETRACTS
  }
}

void latch_func(){
    if(controller_master.get_digital(pros::E_CONTROLLER_DIGITAL_A)) {
      setLatch(extended);
    }
    if(controller_master.get_digital(pros::E_CONTROLLER_DIGITAL_B)) {
      setLatch(retracted);
    }
}