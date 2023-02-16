#pragma once
//
//    FILE: runningAngle.h
//  AUTHOR: Rob Tillaart
// VERSION: 0.2.0
// PURPOSE: Library to average angles by means of low pass filtering with wrapping.
//     URL: https://github.com/RobTillaart/runningAngle
// RELATED: https://github.com/RobTillaart/AverageAngle


#include "Arduino.h"
#include "math.h"


#define RUNNING_ANGLE_LIB_VERSION     (F("0.2.0"))


const float DEFAULT_WEIGHT   = 0.80;
const float DEFAULT_MIDPOINT = 0;



class runningAngle
{
public:
  enum AngleType { DEGREES = 0, RADIANS = 1, GRADIANS = 2 };

  runningAngle(const enum AngleType type = DEGREES);

  //  first value added will not use the weight to set the initial value.
  float  add(float angle);  //  returns new average
  void   reset();
  float  getAverage();

  void   setWeight(float w = DEFAULT_WEIGHT);
  float  getWeight();
  enum   AngleType type();

  //  reformat angle to -180..+180 (degrees) or  -PI..PI (radians)
  //  since 0.2.0 wrap around set midpoint (default 0).
  float  wrap(float angle);

  //  experimental 0.2.0
  //  defines the midpoint of the scale
  //  e.g. 180 will give averages of    0..360
  //         0 will give averages of -180..180
  //        90 will give averages of  -90..270
  //  default = 0 (backwards compatible)
  void   setMidPoint(float midPoint = DEFAULT_MIDPOINT);  
  float  getMidPoint();

private:
  enum   AngleType _type;
  float  _average = 0;
  float  _weight;
  bool   _reset;
  float  _midPoint = 0;
};


//  -- END OF FILE --

