#pragma once
#include <iostream>
using namespace std;
class Time

{
	int d, m, y, h, min;
public:
	Time();
	void setTime(float h, float min, float d, float m, float y);
	void setTime(float h, float min);
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

