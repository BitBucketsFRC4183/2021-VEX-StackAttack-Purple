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

int main() {
  // Initializing Robot Configuration. DO NOT REMOVE!
vexcodeInit();
void turnRobot() {

if(true) {CONTROLLER1.Axis1.position(positive)}
Drivetrain.turn(right);
Drivetrain.setTurnVelocity(50, percent);

if(true) {CONTROLLER1.Axis1.position(negative)};
Drivetrain.turn(left);dd
Drivetrain.setTurnVelocity(50, percent);
Controller1.Axis1.changed(turnRobot);

}
