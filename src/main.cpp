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
// IntakeLeft           motor         3               
// IntakeRight          motor         8               
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"

using namespace vex;

void moveForward() {
if(Controller1.Axis3.position()>0) {
  Drivetrain.drive(forward);
  Drivetrain.setDriveVelocity(50, percent);
  }

else if(Controller1.Axis3.position()<0) {
  Drivetrain.drive(forward);
  Drivetrain.setDriveVelocity(-50, percent);
  }
else
Drivetrain.stop();
}

void turnRobot() {
  if(Controller1.Axis1.position()>0) {
  Drivetrain.turn(right);
}
if(Controller1.Axis1.position()<0) {
  Drivetrain.turn(left);
}
}

double intakeSpeedPercent = 10.0;
double leftIntakeSpeedPercent = 10.0;
double rightIntakeSpeedPercent = 24.0 / 30 * leftIntakeSpeedPercent;

void turnonIntake() {
  IntakeLeft.setVelocity(intakeSpeedPercent, percent);
  IntakeLeft.spin(forward);
  IntakeRight.setVelocity(intakeSpeedPercent, percent);
  IntakeRight.spin(reverse);
}

void turnonIntakeReverse() {
  IntakeLeft.setVelocity(-leftIntakeSpeedPercent, percent);
  IntakeLeft.spin(forward);
  IntakeRight.setVelocity(-leftIntakeSpeedPercent, percent);
  IntakeRight.spin(reverse);
}

void turnoffIntake() {
  IntakeLeft.stop();
  IntakeRight.stop();
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

Controller1.Axis1.changed(turnRobot);

Controller1.ButtonUp.pressed(turnonIntake);
Controller1.ButtonUp.released(turnoffIntake);
Controller1.ButtonDown.pressed(turnonIntakeReverse);
Controller1.ButtonDown.released(turnoffIntake);
}
