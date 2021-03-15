/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       C:\Users\Sajo                                             */
/*    Created:      Wed Mar 10 2021                                           */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Drivetrain           drivetrain    1, 2            
// Controller1          controller                    
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"

using namespace vex;

void moveForward() {
if(Controller1.Axis3.position()>0) {
  Drivetrain.drive(forward);
  Drivetrain.setDriveVelocity(50, percent);
  }

if(Controller1.Axis3.position()<0) {
  Drivetrain.drive(forward);
  Drivetrain.setDriveVelocity(-50, percent);
  }

}

void turnRobot() {
  if(Controller1.Axis1.position()>0) {
  Drivetrain.turn(right);
}


if(Controller1.Axis1.position()<0) {
  Drivetrain.turn(left);
}
}
int main() {
  // Initializing Robot Configuration. DO NOT REMOVE!
vexcodeInit();

Drivetrain.setTurnVelocity(50, percent);

Drivetrain.setDriveVelocity(50, percent);

Controller1.Axis1.changed(turnRobot);


}
