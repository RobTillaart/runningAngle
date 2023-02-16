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
  float  wrap(float angle);

  //  -180 ..180  or  0..360
  void setMode0() { _mode = 0; };  //  -180..180
  void setMode1() { _mode = 1; };  //     0..360

private:
  enum     AngleType _type;
  float    _average = 0;
  float    _weight;
  bool     _reset;
  uint16_t _mode = 0;
};


//  -- END OF FILE --

