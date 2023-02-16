//
//    FILE: runningAngle.cpp
//  AUTHOR: Rob Tillaart
// VERSION: 0.2.0
// PURPOSE: Library to average angles by means of low pass filtering with wrapping.
//     URL: https://github.com/RobTillaart/runningAngle
// RELATED: https://github.com/RobTillaart/AverageAngle


#include "runningAngle.h"


runningAngle::runningAngle(const enum AngleType type)
{
  _type = type;
  reset();
}


void runningAngle::reset()
{
  _average  = 0;
  _weight   = DEFAULT_WEIGHT;
  _reset    = true;
}


float runningAngle::add(float angle)
{
  if (_reset)
  {
    _average = wrap(angle);
    _reset   = false;
  }
  else
  {
    _average = wrap(_average + _weight * wrap(angle - _average));
  }
  if (_mode == 0) return _average;
  return getAverage();
}



float runningAngle::getAverage()
{
  if (_mode == 0)       return _average;
  if (_average >= 0)    return _average;
  if (_type == DEGREES) return _average + 180;
  if (_type == RADIANS) return _average + PI;
  //  GRADIANS
  return _average + 200;
}


void runningAngle::setWeight(float w)
{
  _weight = constrain(w, 0.001, 1);
}


float runningAngle::getWeight()
{
  return _weight;
}


enum runningAngle::AngleType runningAngle::type()
{
  return _type;
}


float runningAngle::wrap(float angle)
{
  if (_type == DEGREES)
  {
    while (angle <  -180) angle += 360;
    while (angle >= +180) angle -= 360;
  }
  else if (_type == RADIANS)
  {
    while (angle <  -PI) angle += TWO_PI;
    while (angle >= +PI) angle -= TWO_PI;
  }
  else  //  GRADIANS
  {
    while (angle <  -200) angle += 400;
    while (angle >= +200) angle -= 400;
  }
  return angle;
}


//  -- END OF FILE --

