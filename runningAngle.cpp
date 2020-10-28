//
//    FILE: runningAngle.cpp
//  AUTHOR: Rob Tillaart
// VERSION: 0.1.0
// PURPOSE: Library to average angles by means of low pass filtering with wrapping.
//     URL: https://github.com/RobTillaart/runningAngle
//
// RELATED: https://github.com/RobTillaart/AverageAngle
//
// HISTORY:
// 0.1.0    2020-10-28 initial version (based on code of Edgar Bonet)

#include "runningAngle.h"

runningAngle::runningAngle(const enum AngleType type)
{
  _type = type;
  reset();
}

void runningAngle::reset()
{
  _average = 0;
  _weight = 0.80;
  _reset = true;
}

float runningAngle::add(float angle)
{
  if (_reset)
  {
    _average = angle;
    _reset = false;
  }
  else
  {
    _average = wrap(_average + _weight * wrap(angle - _average));
  }
  return _average;
}

float runningAngle::wrap(float angle)
{
  if (_type == DEGREES) angle *= DEG_TO_RAD;
  while (angle < -PI) angle += TWO_PI;
  while (angle >= PI) angle -= TWO_PI;
  if (_type == DEGREES) angle *= RAD_TO_DEG;

  return angle;
}

// -- END OF FILE --
