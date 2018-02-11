/*
HDvalve.h - Library to control valves.
Created by Tomat7, October 2017.
Released into the public domain.
*/
#ifndef HDvalve_h
#define HDvalve_h

#include "Arduino.h"
//#include <EtherCard.h>

#define LIBVERSION "HDvalve_v20180120 on pin "
#define DEBUG5
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
	int lastOFF;
	unsigned int Clicks;
	void control();			// ������� ��� ����������� ������ - ��� � ��������� ��������
	void init(int OffTime, byte OnTime); // ������ ��������� ��������� � �������������!
	void setTime(int OffTime);		// ������ ��������� ��������� � �������������!
	//
	// void setTime(int OffTime, byte OnTime);	// ���� ��� � �� ������������
	//
	// void setRate(int mlPerHour, int mlPer1000Click); // ******* �� ������� !! *******
	// ������ �������� ������ 
	// mlPerHour: �������� �������� ������ [��/���]
	// mlPer1000Click: �����������-��-������-������-������� [��/���� * 1000]
	// ��� ��������-����������������� �������� (�����������) ��� ������� �������
	// ���������� ��� ������������� OnTime ��� "�������������" ������ ������� �������.
	// OnTime ��� ������� ��������/��������� ��� �������� �������� ��������.
private:
	int _pin;					// ����� ������������ ���� 
	unsigned long _lastMillis; // ��������� ������ ����� ���������
	byte _OnTime; 				// ���� ���� ������ 255 ���� - int
	int _OffTime; 				// ����� ����� � �������������
	void _setState();
//	bool _usePortD = false;
};
#endif
