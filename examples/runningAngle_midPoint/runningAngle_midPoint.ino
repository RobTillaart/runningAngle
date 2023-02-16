//
//    FILE: runningAngle_midPoint.ino
//  AUTHOR: Rob Tillaart
// PURPOSE: demo setMidPoint


#include "runningAngle.h"

runningAngle head0(runningAngle::DEGREES);
runningAngle head90(runningAngle::DEGREES);
runningAngle head180(runningAngle::DEGREES);
runningAngle head270(runningAngle::DEGREES);

void setup()
{
  Serial.begin(115200);
  Serial.println(__FILE__);
  Serial.println();

  head0.reset();
  head90.reset();
  head180.reset();
  head270.reset();

  head0.setMidPoint(0);
  head90.setMidPoint(90);
  head180.setMidPoint(180);
  head270.setMidPoint(270);
  for (int32_t a = 0; a < 720; a += 23)
  {
    float avg0   = head0.add(a);
    float avg90  = head90.add(a);
    float avg180 = head180.add(a);
    float avg270 = head270.add(a);
    Serial.print(a);
    Serial.print("\t\t");
    Serial.print(avg0);
    Serial.print("\t\t");
    Serial.print(avg90);
    Serial.print("\t\t");
    Serial.print(avg180);
    Serial.print("\t\t");
    Serial.print(avg270);
    Serial.println();
  }
  Serial.println();

  Serial.println("done...");
}


void loop()
{
}


//  -- END OF FILE --
