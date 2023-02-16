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
  _midPoint = DEFAULT_MIDPOINT;
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
  if (_midPoint == 0) return _average;
  return getAverage();
}


//  experimental
//  faster but does not return average.
// void runningAngle::fastAdd(float angle)
// {
  // if (_reset)
  // {
    // _average = wrap(angle);
    // _reset   = false;
  // }
  // else
  // {
    // _average = wrap(_average + _weight * wrap(angle - _average));
  // }
// }


float runningAngle::getAverage()
{
  //  default short cut.
  if (_midPoint == 0) return _average;

  float avg = _average;
  if (_type == DEGREES)
  {
    while (avg <  _midPoint - 180) avg += 360;
    while (avg >= _midPoint + 180) avg -= 360;
  }
  else if (_type == RADIANS)
  {
    while (avg <  _midPoint - PI) avg += TWO_PI;
    while (avg >= _midPoint + PI) avg -= TWO_PI;
  }
  else  //  GRADIANS
  {
    while (avg <  _midPoint - 200) avg += 400;
    while (avg >= _midPoint + 200) avg -= 400;
  }
  return avg;
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


void runningAngle::setMidPoint(float midPoint)
{
  _midPoint = midPoint;
}


float runningAngle::getMidPoint()
{
  return _midPoint;
}


//  -- END OF FILE --

