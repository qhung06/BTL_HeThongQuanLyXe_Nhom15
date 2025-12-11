#include "vehicle.h"

vehicle::vehicle()
{
	plate = "";
	timein = Time();
}

vehicle::vehicle(string p, Time in, Time out)
{
	plate = p;
	timein = in;
	timeout = out;
}
void vehicle::setPlate(string p)
{
	plate = p;
}

void vehicle::setin(int x, int y, int a ,int b, int c)
{
	timein.setTime(x, y,a,b,c);
}

void vehicle::setout(int x, int y, int a, int b, int c)
{
	timeout.setTime(x, y,a,b,c);
}

string vehicle::getplate() const
{
	return plate;
}

Time vehicle::getin() const 
{
	return timein;
}

Time vehicle::getout() const
{
	return timeout;
}
