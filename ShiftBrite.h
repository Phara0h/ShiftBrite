/*
 ShiftBrite.h - A easy arduino ShiftBrite library that works!
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

#ifndef ShiftBrite_h
#define ShiftBrite_h
#include "Arduino.h"

class ShiftBrite
{
  private:
	int datapin; 
	int latchpin;
	int enablepin;
	int clockpin;
    void latch();
 public:
    ShiftBrite(int dp, int lp, int ep, int cp);
	void sendColor(long r, long g, long b);
};

#endif
