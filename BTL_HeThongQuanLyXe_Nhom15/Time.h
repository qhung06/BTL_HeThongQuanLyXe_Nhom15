#pragma once
#include <iostream>
using namespace std;
class Time

{
	int d, m, y, h, min;
public:
	Time();
	Time(int h, int min, int d, int m, int y);
	void setTime(int h, int min, int d, int m, int y);
	void setTime(int h, int min);
	Time operator-(Time t);
	friend ostream& operator<<(ostream& os, const Time& t);
	friend istream& operator>>(istream& is, Time& t);
	int toHours();
	int gethour();
	int getmin();
	int getday();
	int getmonth();
	int getyear();

};

