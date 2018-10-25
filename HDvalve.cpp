/*
HDvalve.cpp - Library to operate with valves
Created by Tomat7, October 2017, 2018.
*/

#include "Arduino.h"
#include "HDvalve.h"

Valve::Valve(int pin)
{
	pin_ = pin;
	pinMode(pin_, OUTPUT);
	Flow = false;
	msOpen_ = 0;
	msClose_ = 65535;
	Clicks = 0;
}

void Valve::init()
{
	//msOpen_ = 0;
	//msClose_ = 65535;
	Serial.print(F(LIBVERSION));
	Serial.println(pin_);
}

void Valve::control()
{
	if ((msOpen_ < 1) || (msClose_ > MAX_TIME)) // не щёлкать совсем!!
	{
		Flow = false; // выключаем
		setState_();
	}
	else if  (msOpen_ > MAX_TIME)				// открываем полностью и не щелкаем !!
	{
		Flow = true;	// ** СЛИВ!! ** 
		setState_();
		#ifdef DEBUG2
		Serial.println("drain! ");
		#endif
	} 
	else
	{
		unsigned long msPassed = millis() - lastMillis_;
		// выясняем не настал ли момент сменить состояние клапана
		if ((Flow) && (msPassed >= msOpen_))
		{
			Flow = false; // выключаем
			setState_();
			#ifdef DEBUG1
			lastON = msPassed;
			#endif
			#ifdef DEBUG3
			Serial.print("on: ");
			Serial.println(msPassed);
			#endif
		}
		else if ((!Flow) && (msPassed >= msClose_))
		{
			Flow = true; // включаем
			setState_();
			Clicks++;
			#ifdef DEBUG1
			lastOFF = msPassed;
			#endif
			#ifdef DEBUG3
			Serial.print("off: ");
			Serial.println(msPassed);
			#endif
		}
	}
	return;
}


void Valve::setTime(uint16_t OffTime)
{
	msClose_ = OffTime;
}

void Valve::setTime(uint16_t OffTime, uint16_t OnTime)
{
	msOpen_ = OnTime;
	msClose_ = OffTime;
}

void Valve::setState_()
{
	digitalWrite(pin_, Flow); // реализуем новое состояние
	lastMillis_ = millis(); // запоминаем момент времени
}



