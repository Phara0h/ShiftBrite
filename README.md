ShiftBrite
==========

A easy arduino ShiftBrite library that works!

ShiftBrite Constructor is (datapin,latchpin,enablepin,clockpin)
 
the only function you have to use now is sendColor(red,blue,green);
 
 red = 0 - 255
 blue = 0 - 255
 green = 0 - 255
 
How to install
==========
 * Copy the full folder into your arduino/libraries folder.
 * Restart the IDE
 * Profit 
 
 
Example
========== 
include <ShiftBrite.h>

ShiftBrite shift(datapin,latchpin,enablepin,clockpin); //construct

void setup()
{
  //add your setup here.
}

void loop()
{
  //Test Red
  shift.sendColor(255,0,0);
}