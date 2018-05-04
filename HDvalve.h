/*
HDvalve.h - Library to control valves.
Created by Tomat7, October 2017, 2018.
Released into the public domain.
*/
#ifndef HDvalve_h
#define HDvalve_h

#include "Arduino.h"

#define LIBVERSION "HDvalve_v20180325 on pin "
//#define DEBUG2
//#define DEBUG3
//#define DEBUG5
//#define USE_PORTB_ONLY

class Valve 
{
public:
	// ����������� ������� ��������� Valve � �������������� 
	// ����������-����� ������ � ���������
	// ������������ ����� �������� 255 ���� !! 
	// ���� ���� ������ - ���� � � .cpp ����� byte �������� �� int
	Valve(int pin);
	boolean Flow;    // ������� ������ ������ (HIGH = TRUE = ������)
	byte lastON;	
	unsigned int lastOFF;
	unsigned int Clicks;
	void control();			// ������� ��� ����������� ������ (��� ���� - ��� �����), ��� ���������/��������� ������
	void init(); 			
	void setTime(int OffTime);		// ������ ��������� ��������� � �������������!
	void setTime(int OffTime, byte OnTime);	
/*
 �� ������� !! *** ���� ��� � �� ������������
 void setRate(int mlPerHour, int mlPer1000Click); 
 ������ �������� ������ 
 mlPerHour: �������� �������� ������ [��/���]
 mlPer1000Click: �����������-��-������-������-������� [��/���� * 1000]
 ��� ��������-����������������� �������� (�����������) ��� ������� �������
 ���������� ��� ������������� OnTime ��� "�������������" ������ ������� �������.
 OnTime ��� ������� ��������/��������� ��� �������� �������� ��������.
*/

private:
	int pin_;					// ����� ������������ ���� 
	unsigned long lastMillis_; // ��������� ������ ����� ���������
	byte msOpen_; 				// ���� ���� ������ 255 ���� - int
	unsigned int msClose_; 				// ����� ����� � �������������
	void setState_();
//	bool _usePortD = false;
};
#endif
