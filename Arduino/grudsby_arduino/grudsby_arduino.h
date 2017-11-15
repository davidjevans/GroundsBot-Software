#ifndef GRUDSBY_ARDUINO_H
#define GRUDSBY_ARDUINO_H

#include <Arduino.h>
#include <ros.h>
#include <grudsby_lowlevel/ArduinoVel.h>
#include <grudsby_lowlevel/ArduinoResponse.h>
#include "grudsby_motor.h"

using namespace grudsby;

void velCallback(const grudsby_lowlevel::ArduinoVel& msg);


// void publishStatus();

void moveGrudsby();

int32_t prevLPos = -999;
int32_t prevRPos = -999;

bool autonomous;
bool kill;

//Right encoder gives negative values
Encoder rightEncoder(2, 4);
Encoder leftEncoder(3, 5);

Motor* leftMotor;
Motor* rightMotor;

ros::NodeHandle nh;
ros::Subscriber<grudsby_lowlevel::ArduinoVel> vel_sub("/arduino/vel", &velCallback);

std_msgs::Int32 lwheel_msg;
std_msgs::Int32 rwheel_msg;
ros::Publisher	lwheel_pub("lwheel", &lwheel_msg);
ros::Publisher 	rwheel_pub("rwheel", &rwheel_msg);

rc_control rc;

#endif