/*
	HDvalve.h - Library to control valves.
	Created by Tomat7, October 2017, 2018.
*/
#ifndef HDvalve_h
#define HDvalve_h

#include "Arduino.h"

#ifdef LIBVERSION
#undef LIBVERSION
#endif
#define LIBVERSION "HDvalve_v20181025 on pin "

	
#define MAX_TIME 60000
//#define DEBUG1
//#define DEBUG2
//#define DEBUG3
//#define DEBUG5
//#define USE_PORTB_ONLY

class Valve 
{
public:
	// максимальное время открытия 255 мсек *** в новых версиях смотреть и править #define MAX_TIME 60000
	// если надо больше - ниже и в .cpp нужно byte заменить на uint16_t *** уже заменено
	Valve(int pin);
	void init(); 			
	void control();						// функция для регулярного вызова (чем чаще - тем лучше), она открывает/закрывает клапан
	void setTime(uint16_t OffTime);		// задаём временные интервалы в миллисекундах!
	void setTime(uint16_t OffTime, uint16_t OnTime);
	void printConfig();
	
	boolean Flow;    		// признак клапан открыт (HIGH = TRUE = открыт)
	unsigned int Clicks;
	
	#ifdef DEBUG1
	uint16_t lastON;	
	uint16_t lastOFF;
	#endif
/*
	*** типа так и не понадобилось ***
	void setRate(int mlPerHour, int mlPer1000Click);	// задаёт скорость отбора - не сделано !! 
	// mlPerHour: желаемая скорость отбора [мл/час]
	// mlPer1000Click: миллилитров-за-тысячу-кликов-клапана [мл/клик * 1000]
	// это расчетно-экспериментальная величина (коэффициент) для каждого клапана
	// полученная для определенного OnTime при "фиксированной" высоте подвеса клапана.
	// OnTime при которой получена/расчитана эта величина задается отдельно.
*/
	
private:
	int pin_;					// номер управл€ющего пина 
	unsigned long lastMillis_;	// последний момент смены состо€ни€
	uint16_t msOpen_; 			// время в открытом состоянии в миллисекундах (если надо больше *** 255 мсек - uint16_t *** уже!)
	uint16_t msClose_; 			// время в закрытом состоянии в миллисекундах
	void setState_();
	//	bool _usePortD = false;
};
#endif
