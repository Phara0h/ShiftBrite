/*
 A example of lighting up each led on the ShiftBrite
 using the ShiftBrite Lib.
 
 ShiftBrite Constructor is (datapin,latchpin,enablepin,clockpin)
 
 the only function you have to use now is sendColor(red,blue,green);
 
 red = 0 - 255
 blue = 0 - 255
 green = 0 - 255
 
 Created by Jt whissel
*/

#include <ShiftBrite.h>

int datapin = 5;
int latchpin = 6;
int enablepin = 10;
int clockpin = 11;

ShiftBrite shift(datapin,latchpin,enablepin,clockpin); //construct

void setup()
{
  //add your setup here.
}

void loop()
{
  //Test Red
  shift.sendColor(255,0,0);
  delay(300);
  
  //Test Green
  shift.sendColor(0,255,0);
  delay(300);
  
  //Test Blue
  shift.sendColor(0,0,255);
  delay(300);
}
