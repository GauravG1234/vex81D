#pragma config(Sensor, in1,    LeftPoteniometer, sensorPotentiometer)
#pragma config(Sensor, in3,    LightSensor,    sensorReflection)
#pragma config(Sensor, in8,    RightPoteniometer, sensorPotentiometer)
#pragma config(Sensor, dgtl1,  LeftEncoder,    sensorQuadEncoder)
#pragma config(Sensor, dgtl9,  RightEncoder,   sensorQuadEncoder)
#pragma config(Sensor, dgtl11, FrontSonar,     sensorSONAR_inch)
#pragma config(Motor,  port1,           RightSideBack, tmotorServoContinuousRotation, openLoop, reversed)
#pragma config(Motor,  port2,           RightSideFront, tmotorServoContinuousRotation, openLoop)
#pragma config(Motor,  port3,           RightArm,      tmotorServoContinuousRotation, openLoop)
#pragma config(Motor,  port4,           IntakeSystem,  tmotorServoContinuousRotation, openLoop)
#pragma config(Motor,  port8,           LeftArm,       tmotorServoContinuousRotation, openLoop, reversed)
#pragma config(Motor,  port9,           LeftSideFront, tmotorServoContinuousRotation, openLoop, reversed)
#pragma config(Motor,  port10,          LeftSideBack,  tmotorServoContinuousRotation, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#pragma platform(VEX)




//Competition Control and Duration Settings
#pragma competitionControl(Competition)
#pragma autonomousDuration(15)
#pragma userControlDuration(120)




#include "Vex_Competition_Includes.c"   //Main competition background code...do not modify!








////////////////////////////////////////////////////////////
int wheels_deadband = 15;
int fullspeed       = 127;
int halfspeed       = 63;
int halfsecond      = 500;
int onesecond       = 1000;
int twoseconds      = 2000;
int threeseconds    = 3000;
int fiveseconds     = 5000;
int tenseconds      = 10000;
int stopped         = 0;
int pressed         = 1;
int robot_rotate    = 0, robot_fwd_rev = 0, robot_translate = 0;
int RightEncoderCounts = SensorValue[RightEncoder];
int LeftEncoderCounts = SensorValue[LeftEncoder];
int oneturn = 90;
int LeftPoteniometerLimit_32 = 1768, RightPoteniometerLimit_32    = 2925;
int LeftPoteniometerLimit_20 = 2240, RightPoteniometerLimit_20 = 2150;
int LeftPoteniometerLimit_10 = 2835, RightPoteniometerLimit_10  = 1600;
int LeftPoteniometerLimit_0  = 3310, RightPoteniometerLimit_0    = 1330;
int LeftPoteniometerDesired  = 0, RightPoteniometerDesired    = 0;
int armdeadband = 200;
////////////////////////////////////////////////////////////




//Define tasks
void stopWheels()
{
    motor[LeftSideFront]  = stopped;
    motor[LeftSideBack]   = stopped;
    motor[RightSideFront] = stopped;
    motor[RightSideBack]  = stopped;
}




void stopArms()
{
    motor[RightArm] = stopped;
    motor[LeftArm]  = stopped;
}




void moveForward(int speed)
{
    motor[LeftSideFront]  = speed;
    motor[LeftSideBack]   = speed;
    motor[RightSideFront] = speed;
    motor[RightSideBack]  = speed;
}




void moveForwardTimed(int t, int speed)
{
    moveForward(speed);
    wait1Msec(t);
    stopWheels();
}




void moveBack(int speed)
{
    motor[LeftSideFront]  = speed;
    motor[LeftSideBack]   = speed;
    motor[RightSideFront] = speed;
    motor[RightSideBack]  = speed;
}




void moveBackTimed(int t, int speed)
{
    moveBack(speed);
    wait1Msec(t);
    stopWheels();
}




void moveLeft(int speed)
{
    motor[LeftSideFront]  = -speed;
    motor[LeftSideBack]   = speed;
    motor[RightSideFront] = speed;
    motor[RightSideBack]  = -speed;
}




void moveLeftTimed(int t, int speed)
{
    moveLeft(speed);
    wait1Msec(t);
    stopWheels();
}




void moveRight(int speed)
{
    motor[LeftSideFront]  = -speed;
    motor[LeftSideBack]   = speed;
    motor[RightSideFront] = speed;
    motor[RightSideBack]  = -speed;
}




void moveRightTimed(int t, int speed)
{
    moveRight(speed);
    wait1Msec(t);
    stopWheels();
}




void turnRight()
{
    motor[LeftSideFront]  = fullspeed;
    motor[LeftSideBack]   = fullspeed;
    motor[RightSideFront] = -fullspeed;
    motor[RightSideBack]  = -fullspeed;
}




void turnRightTimed(int t)
{
    turnRight();
    wait1Msec(t);
    stopWheels();
}




void turnLeft()
{
    motor[LeftSideFront]  = -fullspeed;
    motor[LeftSideBack]   = -fullspeed;
    motor[RightSideFront] = fullspeed;
    motor[RightSideBack]  = fullspeed;
}




void turnLeftTimed(int t)
{
    turnLeft();
    wait1Msec(t);
    stopWheels();
}




void raiseArms()
{
    motor[LeftArm]  = fullspeed;
    motor[RightArm] = fullspeed;
}




void raiseArmsTimed(int t)
{
    raiseArms();
    wait1Msec(t);
    stopArms();
}




void lowerArms()
{
    motor[LeftArm]  = -fullspeed;
    motor[RightArm] = -fullspeed;
}




void lowerArmsTimed(int t)
{
    lowerArms();
    wait1Msec(t);
    stopArms();
}
void IntakeSystemIn()
{
    motor[IntakeSystem] = fullspeed;
}
void IntakeSystemOut()
{
    motor[IntakeSystem] = -fullspeed;
}
void IntakeSystemStop()
{
    motor[IntakeSystem] = stopped;
}
void IntakeSystemInTimed(int t)
{
    IntakeSystemIn();
    wait1Msec(t);
    IntakeSystemStop();
}
void IntakeSystemOutTimed(int t)
{
    IntakeSystemOut();
    wait1Msec(t);
    IntakeSystemStop();
}




void moveForwardDistance(int dist)
{
	  //Assuming that "dist" is going to be figured out later
    //"dist" would be the encoder counts until it stops moving; we can make "onefoot" variables etc. later.
	  while(RightEncoderCounts <= dist)
	  {
	  	moveForward(fullspeed);
	  }
	  stopWheels();
}




void moveBackDistance(int dist)
{
	  //Assuming that "dist" is going to be figured out later
    //"dist" would be the encoder counts until it stops moving; we can make "onefoot" variables etc. later.
	  while(RightEncoderCounts <= dist)
	  {
	  	moveBack(fullspeed);
	  }
	  stopWheels();
}




void turnRightAmount(int amount)
{
	  //Assuming that "amount" is going to be figured out later
    //"amount" would be the left encoder counts until it stops moving
	  while(LeftEncoderCounts <= amount)
	  {
	  	turnRight();
	  }
}




void turnLeftAmount(int amount)
{
	  //Assuming that "amount" is going to be figured out later
    //"amount" would be the right encoder counts until it stops moving
	  while(RightEncoderCounts <= amount)
	  {
	  	turnLeft();
	  }
}
//////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                              //
//                          Pre-Autonomous Functions                                            //
//                                                                                              //
// You may want to perform some actions before the competition starts. Do them in the           //
// following function.                                                                          //
//                                                                                              //
//////////////////////////////////////////////////////////////////////////////////////////////////




void pre_auton()
{
  // All activities that occur before the competition starts
  // Example: clearing encoders, setting servo positions, ...
SensorValue[RightEncoder] = 0;
SensorValue[LeftEncoder] = 0;
RightEncoderCounts = 0;
LeftEncoderCounts = 0;
}




//////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                          //                                       
//                                 Autonomous Task                                          //
//                                                                                          //                                        
// This task is used to control your robot during the autonomous phase of a VEX Competition.//
// You must modify the code to add your own robot specific commands here.                   //
//                                                                                          //
////////////////////////////////////////////////////////////////////////////////////////////// 








task autonomous()
{
    bool inRedDeadZone       = false;
    bool inRedMidZone        = false;
    bool inBlueDeadZone      = false;
    bool inBlueMidZone       = false;
    bool isindeadzone        = false;
    bool isred               = false;
    bool isblue              = false;
    bool isinmiddlezone      = false;




//Finding the position and setting it to true


 /*
    if (SensorValue[FrontSonar] > 3 && SensorValue[FrontSonar] < 12)
    {
        isindeadzone = true;
    }
    else if (SensorValue[FrontSonar] > 12) 
    {
            isinmiddlezone = true;
    }
    if (SensorValue[LightSensor] == 1)
    {
        isblue = true;
    }
    else if (SensorValue[LightSensor] == 0)
    {
        isred = true;
    }
    */




    /*
    if (isindeadzone && isred)
    {
        inRedDeadZone = true;
    }
    else if (isindeadzone && isblue)
    {
        inBlueDeadZone = true;
    }
    else if (isinmiddlezone && isred)
    {
        inRedMidZone = true;
    }
    else if (isinmiddlezone && isblue)
    {
        inBlueMidZone = true;
    }
    */




  if (inRedDeadZone)
  {
    //ROBOT DIRECTION: FORWARD
    moveRightTimed(onesecond, fullspeed);
    moveForwardTimed(onesecond, fullspeed);
    moveLeftTimed(twoseconds, fullspeed);
    moveRightTimed(onesecond, fullspeed);
    moveForwardTimed(onesecond, fullspeed);
    moveLeftTimed(twoseconds, fullspeed);
    moveRightTimed(onesecond, fullspeed);
    turnLeftTimed(onesecond);
  }
  else if (inRedMidZone)
  {
    //ROBOT DIRECTION: FORWARD
    moveForwardTimed(threeseconds, fullspeed);
    moveLeftTimed(halfsecond, fullspeed);
    turnRightTimed(onesecond);
    moveForwardTimed(threeseconds, fullspeed);
    wait1Msec(onesecond);
    moveBackTimed(fiveseconds, fullspeed);
  }
  else if (inBlueMidZone)
  {
    //ROBOT DIRECTION: FORWARD
    moveForwardTimed(threeseconds, fullspeed);
    moveRightTimed(halfsecond, fullspeed);
    turnLeftTimed(onesecond);
    moveForwardTimed(threeseconds, fullspeed);
    wait1Msec(onesecond);
    moveBackTimed(fiveseconds, fullspeed);
  }
  else if (inBlueDeadZone)
  {
    //ROBOT DIRECTION: FORWARD
    moveLeftTimed(onesecond, fullspeed);
    moveForwardTimed(onesecond, fullspeed);
    moveRightTimed(threeseconds, fullspeed);
    moveLeftTimed(twoseconds, fullspeed);
    moveForwardTimed(onesecond, fullspeed);
    moveRightTimed(threeseconds, fullspeed);
    moveLeftTimed(twoseconds, fullspeed);
    turnRightTimed(onesecond);
  }
  else
  {
    //THIS IS ERROR AUTONOMOUS.  THIS ONLY HAPPENS IF THE ROBOT ISN'T FACING THE RIGHT WAY OR CAN'T DETECT WHERE IT IS
    /*
    moveForwardTimed(onesecond, fullspeed);
    moveBackTimed(onesecond,fullspeed);
    moveForwardTimed(onesecond, fullspeed);
    moveBackTimed(onesecond,fullspeed);
    moveForwardTimed(onesecond, fullspeed);
    moveBackTimed(onesecond,fullspeed);
    moveForwardTimed(onesecond, fullspeed);
    moveBackTimed(onesecond,fullspeed);
    moveForwardTimed(onesecond, fullspeed);
    moveBackTimed(onesecond,fullspeed);
    moveForwardTimed(onesecond, fullspeed);
    moveBackTimed(onesecond,fullspeed);
    moveForwardTimed(onesecond, fullspeed);
    moveBackTimed(onesecond,fullspeed);
    */
  }

      // ARM AUTOMATIC SYSTEM
    }//END AUTONOMOUS




//////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////User Control Task///////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////
// This task is used to control your robot during the user control phase of a VEX Competition.////////
// You must modify the code to add your own robot specific commands here./////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////




task usercontrol()
{
  // Loop Forever
  while (true)
  {
      if (vexRT[Btn8D] == pressed)
      {
      	untilPotentiometerGreaterThan(3300, LeftPoteniometer);
      }
      else if (vexRT[Btn8U] == pressed)
      {
      	untilPotentiometerGreaterThan(1768, LeftPoteniometer);
      }
      else if (vexRT[Btn8R] == pressed)
      {
      	untilPotentiometerGreaterThan(2240, LeftPoteniometer);
      }
      else if(vexRT[Btn8L] == pressed)
      {
      	untilPotentiometerGreaterThan(2835, LeftPoteniometer);
      }
      
  
  //these are the arms controls (Call of Duty trigger button
    if(vexRT[Btn6U] == pressed)
    {
        raiseArms();
    }
    else if(vexRT[Btn6D] == pressed)
    {
        lowerArms();
    }
    else 
    {
    	stopArms();
    }
    // ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^  
		if(abs(vexRT[Ch3]) > wheels_deadband)
      robot_fwd_rev = vexRT[Ch3];
    else
      robot_fwd_rev = 0;
    //Create "deadzone" for robot_translate/Ch4
    if(abs(vexRT[Ch4]) > wheels_deadband)
      robot_translate = vexRT[Ch4];
    else
      robot_translate = 0;
    //Create "deadzone" for robot_rotate/Ch1
    if(abs(vexRT[Ch1]) > wheels_deadband)
      robot_rotate = vexRT[Ch1];
   else
      robot_rotate = 0;
    //Remote Control Commands
    motor[LeftSideFront]  = robot_fwd_rev + robot_translate + robot_rotate;
    motor[LeftSideBack]   = robot_fwd_rev - robot_translate + robot_rotate;




    motor[RightSideFront] = robot_fwd_rev - robot_translate - robot_rotate;
    motor[RightSideBack]  = robot_fwd_rev + robot_translate - robot_rotate;
  }
}
