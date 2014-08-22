
#pragma once

#include <string> // for size_t

/// all distances in mm
/// all times in seconds
/// all weights in kilograms

// Number of identifiable robots on one team
const size_t Num_Shells = 16;

// Number of playing robots on one team
const size_t Robots_Per_Team = 6;

const float Ball_Diameter = 43;
const float Ball_Radius = Ball_Diameter/2.0f;
const float Ball_Mass = 0.048f;

const float Field_Length = 6050;
const float Field_Width = 4050;
const float Field_Border = 250;

const float Field_LineWidth = 10;

const float Field_GoalWidth = 700;
const float Field_GoalDepth = 180;
const float Field_GoalHeight = 160;

/** Distance of the penalty marker from the goal line */
const float Field_PenaltyDist = 750;
const float Field_PenaltyDiam = 10;

/** Radius of the goal arcs */
const float Field_ArcRadius = 800;

/** diameter of the center circle */
const float Field_CenterRadius = 500;
const float Field_CenterDiameter = Field_CenterRadius * 2.0f;

/** flat area for defence markings */
const float Field_GoalFlat = 350;

const float Floor_Length = Field_Length + 2.0 * Field_Border;
const float Floor_Width = Field_Width + 2.0 * Field_Border;

const float Robot_Diameter = 200;//NOT THE REAL ONE - TODO USE THE REAL RADIUS 20cm in Grsim
const float Robot_Radius = Robot_Diameter/2.0f;
const float Robot_Height = 150;
const float Robot_MouthWidth = 100;

/** constants for dot patterns */
const float Dots_Small_Offset = 0.035;
const float Dots_Large_Offset = 0.054772;
const float Dots_Radius = 0.02;

/// timestamp() returns the current time in microseconds.  Multiply by this constant to get to seconds.
const float TimestampToSecs = 1.0f / 1000000.0f;
const float SecsToTimestamp = 1.0f / TimestampToSecs;
