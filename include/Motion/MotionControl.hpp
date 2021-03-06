#pragma once

/*#include <Configuration.hpp>*/
#include "Utils/Vector2f.h"
/*#include <Pid.hpp>*/

class OurRobot;

/**
 * @brief Handles computer-side motion control
 * @details It is responsible for most of what gets sent out in a RadioTx packet.
 * The MotionControl object is given an OurRobot at initialization and from then
 * on will set the values in that robot's RadioTx packet directly whenever run()
 * or stopped() is called.
 */
class MotionControl {
public:
	MotionControl(double *robot);
	
	/**
	 * Stops the robot.
	 * The robot will decelerate at max acceleration until it stops.
	 */
	void stopped();
	
	/**
	 * This runs PID control on the position and angle of the robot and
	 * sets values in the robot's radioTx packet.
	 */
	void run();
	

private:
	//	sets the target velocity in the robot's radio packet
	//	this method is used by both run() and stopped() and does the
	//	velocity and acceleration limiting and conversion to robot velocity "units"
	void _targetBodyVel(Vector2f targetVel);

	///	sets the target angle velocity in the robot's radio packet
	///	does velocity limiting and conversion to robot velocity "units"
	void _targetAngleVel(float angleVel);

	//OurRobot *_robot;

	//	these are tracked so we can limit robot acceleration
	Vector2f _lastVelCmd;	//	the last velocity (in m/s, not the radioTx value) command that we sent to the robot
	long _lastCmdTime;	//	the time in microseconds when the last velocity command was sent

	/*
	Pid _positionXController;
	Pid _positionYController;
	Pid _angleController;*/
	
	static double *_max_acceleration;
	static double *_max_velocity;

	static double *_path_jitter_compensation_factor;
};
