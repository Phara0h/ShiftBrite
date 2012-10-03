/*
 ShiftBrite.cpp - A easy arduino ShiftBrite library that works!
 Copyright (c) 2012 Jt Whissel.  All right reserved.
 
 This library is free software; you can redistribute it and/or
 modify it under the terms of the GNU Lesser General Public
 License as published by the Free Software Foundation; either
 version 2.1 of the License, or (at your option) any later version.
 
 This library is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 Lesser General Public License for more details.
 
 You should have received a copy of the GNU Lesser General Public
 License along with this library; if not, write to the Free Software
 Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
 */

#include "Arduino.h"
#include "ShiftBrite.h"
ShiftBrite::ShiftBrite(int dp, int lp, int ep, int cp)
{

  datapin = dp;
  latchpin = lp;
  enablepin = ep;
  clockpin = cp;

  pinMode(datapin,OUTPUT);
  pinMode(latchpin,OUTPUT);
  pinMode(enablepin,OUTPUT);
  pinMode(clockpin,OUTPUT);

  digitalWrite(latchpin, LOW);
  digitalWrite(enablepin, LOW);
}

void ShiftBrite::sendColor(long r, long g, long b)
{
  long packet = 0;
  long c = 00;
  
  r = (r*4);
  g = (g*4);
  b = (b*4);
  if(r > 1023)
  {
    r = 1023;
  }
  if(g > 1023)
  {
    g = 1023;
  }
  if(b > 1023)
  {
    b = 1023;
  }
  packet = (packet << 2) | (c & 3); //3 =  binary 11
  //dhex(packet);
  packet = (packet << 10) | (b & 1023);
  //dhex(packet);  
  packet = (packet << 10) | (r & 1023);
  //dhex(packet);
  packet = (packet << 10) | (g & 1023);
  //dhex(packet);
  long  s1 = 0xFF000000;
  long  s2 = 0xFF0000;
  long  s3 = 0xFF00;
  long  s4 = 0xFF;

  shiftOut(datapin, clockpin, MSBFIRST, (s1 & packet) >> 24);
  shiftOut(datapin, clockpin, MSBFIRST, (s2 & packet) >> 16);
  shiftOut(datapin, clockpin, MSBFIRST, (s3 & packet) >> 8);
  shiftOut(datapin, clockpin, MSBFIRST, (s4 & packet)); 
  delayMicroseconds(5);
  latch();
}

void ShiftBrite::latch()
{
  digitalWrite(latchpin, HIGH);
  delayMicroseconds(5);
  digitalWrite(latchpin, LOW);
}