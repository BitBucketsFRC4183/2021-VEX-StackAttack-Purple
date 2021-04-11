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
// Drivetrain           drivetrain    1, 10
// Controller1          controller
// IntakeLeft           motor         3
// IntakeRight          motor         8
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"

using namespace vex;

double driveSpeed = 37.5;

void moveForward() {
  if (Controller1.Axis3.position() > 0) {
    Drivetrain.drive(forward);
    Drivetrain.setDriveVelocity(driveSpeed, percent);
  }

  else if (Controller1.Axis3.position() < 0) {
    Drivetrain.drive(forward);
    Drivetrain.setDriveVelocity(-(driveSpeed), percent);
  }

  else {
    Drivetrain.stop();
  }
}

void turnRobot() {
  if (Controller1.Axis1.position() > 0) {
    Drivetrain.turn(right);
  }

  else if (Controller1.Axis1.position() < 0) {
    Drivetrain.turn(left);
  }

  else
    Drivetrain.stop();
}

double leftIntakeSpeedPercent = 10.0;
double rightIntakeSpeedPercent = 24.0 / 30 * leftIntakeSpeedPercent;

void turnonIntake() {
  IntakeLeft.setVelocity(leftIntakeSpeedPercent, percent);
  IntakeLeft.spin(forward);
  IntakeRight.setVelocity(rightIntakeSpeedPercent, percent);
  IntakeRight.spin(reverse);
}

void turnonIntakeReverse() {
  IntakeLeft.setVelocity(-leftIntakeSpeedPercent, percent);
  IntakeLeft.spin(forward);
  IntakeRight.setVelocity(-rightIntakeSpeedPercent, percent);
  IntakeRight.spin(reverse);
}

void turnoffIntake() {
  IntakeLeft.stop();
  IntakeRight.stop();
}

//intake buttons
double leftPosition = 0;
double rightPosition = 0;
double leftIntakeDegreeIncrement = 30;
double rightIntakeDegreeIncrement = 24;

void IntakeUp() {
  leftPosition += leftIntakeDegreeIncrement;
  rightPosition -= rightIntakeDegreeIncrement;
  IntakeLeft.spinToPosition(leftPosition, degrees, false);
  IntakeRight.spinToPosition(rightPosition, degrees, false);
}

void IntakeDown() {
  leftPosition -= leftIntakeDegreeIncrement;
  rightPosition += rightIntakeDegreeIncrement;
  IntakeLeft.spinToPosition(leftPosition, degrees, false);
  IntakeRight.spinToPosition(rightPosition, degrees, false);
}

//nudge intake
void nudgeLeftIntake() {
  IntakeLeft.spinToPosition(IntakeLeft.position(degrees) + 10, degrees);
}

void nudgeRightIntake() {
  IntakeRight.spinToPosition(IntakeRight.position(degrees) + 10, degrees);
}

double rotateMultiplier = 1.05;

void testAuton() {
  // I made this assuming that the bot is facing south at the middle of home
  Drivetrain.driveFor(forward, 26, inches);
  Drivetrain.turnFor(left, 90 * rotateMultiplier, degrees);
  Drivetrain.driveFor(forward, 28, inches);
  Drivetrain.turnFor(left, 90 * rotateMultiplier, degrees);
  Drivetrain.driveFor(forward, 22, inches);
  Drivetrain.turnFor(left, 90 * rotateMultiplier, degrees);
  Drivetrain.driveFor(forward, 48, inches);
}

int main() {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();

  testAuton();
  Drivetrain.setTurnVelocity(50, percent);

  Drivetrain.setDriveVelocity(50, percent);

  Controller1.Axis1.changed(turnRobot);
  Controller1.Axis3.changed(moveForward);

  Controller1.ButtonUp.pressed(turnonIntake);
  Controller1.ButtonUp.released(turnoffIntake);
  Controller1.ButtonDown.pressed(turnonIntakeReverse);
  Controller1.ButtonDown.released(turnoffIntake);

  Controller1.ButtonY.pressed(nudgeLeftIntake);
  Controller1.ButtonA.pressed(nudgeRightIntake);

  IntakeLeft.setStopping(brake);
  IntakeRight.setStopping(brake);
  Controller1.ButtonX.pressed(IntakeUp);
  Controller1.ButtonB.pressed(IntakeDown);
}
