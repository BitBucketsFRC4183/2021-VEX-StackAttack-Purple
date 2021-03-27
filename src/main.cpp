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

<<<<<<< Updated upstream
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


=======
void driveRobot() {
  if (Controller1.Axis1.position() == 0) {
    Drivetrain.stop();
  }

  if (Controller1.Axis1.position() > 0) {
    Drivetrain.drive(forward);
  } else {
    Drivetrain.drive(reverse);
  }
}

void turnRobot() {
  if(Controller1.Axis2.position() > 0) {
    Drivetrain.turn(right);
  }

    if (Controller1.Axis2.position() < 0) {
    Drivetrain.turn(left);
  }
}

void testAuton() {
  //I made this assuming that the bot is facing south at the middle of home
  Drivetrain.driveFor(forward, 24, inches);
  Drivetrain.turnFor(left, 90, degrees);
  Drivetrain.driveFor(forward, 48, inches);
  Drivetrain.turnFor(left, 90, degrees);
  Drivetrain.driveFor(forward, 24, inches);
  Drivetrain.turnFor(left, 90, degrees);
  Drivetrain.driveFor(forward, 48, inches);
}

int main() {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();
  
  Drivetrain.setTurnVelocity(50, percent);
  Drivetrain.setDriveVelocity(50, percent);

  Controller1.Axis1.changed(driveRobot);
  Controller1.Axis2.changed(turnRobot);
>>>>>>> Stashed changes
}

