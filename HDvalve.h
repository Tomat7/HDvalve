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
	// ������������ ����� �������� 255 ���� *** � ����� ������� �������� � ������� #define MAX_TIME 60000
	// ���� ���� ������ - ���� � � .cpp ����� byte �������� �� uint16_t *** ��� ��������
	Valve(int pin);
	void init(); 			
	void control();						// ������� ��� ����������� ������ (��� ���� - ��� �����), ��� ���������/��������� ������
	void setTime(uint16_t OffTime);		// ������ ��������� ��������� � �������������!
	void setTime(uint16_t OffTime, uint16_t OnTime);
	void printConfig();
	
	boolean Flow;    		// ������� ������ ������ (HIGH = TRUE = ������)
	unsigned int Clicks;
	
	#ifdef DEBUG1
	uint16_t lastON;	
	uint16_t lastOFF;
	#endif
/*
	*** ���� ��� � �� ������������ ***
	void setRate(int mlPerHour, int mlPer1000Click);	// ������ �������� ������ - �� ������� !! 
	// mlPerHour: �������� �������� ������ [��/���]
	// mlPer1000Click: �����������-��-������-������-������� [��/���� * 1000]
	// ��� ��������-����������������� �������� (�����������) ��� ������� �������
	// ���������� ��� ������������� OnTime ��� "�������������" ������ ������� �������.
	// OnTime ��� ������� ��������/��������� ��� �������� �������� ��������.
*/
	
private:
	int pin_;					// ����� ������������ ���� 
	unsigned long lastMillis_;	// ��������� ������ ����� ���������
	uint16_t msOpen_; 			// ����� � �������� ��������� � ������������� (���� ���� ������ *** 255 ���� - uint16_t *** ���!)
	uint16_t msClose_; 			// ����� � �������� ��������� � �������������
	void setState_();
	//	bool _usePortD = false;
};
#endif
