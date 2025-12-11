#include "Time.h"
#include <iostream>
using namespace std;
Time::Time()
{
	d = 12;
	m = 10;
	y = 2025;
	h = 0;
	min = 0;
}

void Time::setTime(int h, int min, int d, int m, int y)
{
	this->h = h;
	this->min = min;
	this->d = d;
	this->m = m;
	this->y = y;
}

void Time::setTime(int h, int min)
{
	this->h = h;
	this->min = min;

}

int Time::gethour()
{
	return h;
}

int Time::getmin()
{
	return min;
}

int Time::getday()
{
	return d;
}

int Time::getmonth()
{
	return m;
}

int Time::getyear()
{
	return y;
}

int Time::toHours()
{
	float timex;
	int timey;
	timey = y * 365 * 24 + m * 30 * 24 + d * 24 + h + min / 60;
	timex = y * 365 * 24 + m * 30 * 24 + d * 24 + h + min / 60;
	if (timey != timex)
		return timey + 1;
	else
		return timey;

}

ostream& operator<<(ostream& os, const Time& t)
{
	os << t.h << ":" << t.min << " " << t.d << "/" << t.m << "/" << t.y;
	return os;
}

istream& operator>>(istream& is, Time& t)
{

	is >> t.h  >> t.min >> t.d  >> t.m  >> t.y;

	return is;
}




Time Time::operator-(Time t)
{
	Time kq;
	kq.min = min - t.min;
	kq.h = h - t.h;
	kq.d = d - t.d;
	kq.m = m - t.m;
	kq.y = y - t.y;
	return kq;
}
