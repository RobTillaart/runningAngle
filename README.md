# runningAngle

Arduino library to calculate the running average by means of low pass filtering

## Description

runningAngle is an class to calculate the running average of angles.
These angles typically come in a stream from a compass sensor or so.

This library relates to https://github.com/RobTillaart/AverageAngle, 
in fact this library is a spin off based on an issue raised by Edgar Bonet (kudo's)

## Interface

- **enum AngleType { DEGREES, RADIANS }** used to get type math right.
- **runningAngle(AngleType type = DEGREES)** constructor, default to DEGREES
- **float add(float angle)** adds value using a certain weight, except the first value after a reset is used as initial value. The **add()** function returns the new average.
- **void reset()** resets the internals and start over again.
- **float getAverage()** returns the current average value.
- **void setWeight(float weight)** sets the weight of the new added value. Value wil be constrained between 0.001 and 1.00
- **float getWeight()** returns the current set weight.
- **AngleType type()** returns DEGREEES or RADIANS.
- **float wrap(float angle)** wraps an angle to <-180..+180>  <-PI..PI> depending on the type set.

## Operation

See example
