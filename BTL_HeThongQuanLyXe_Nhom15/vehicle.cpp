#include "vehicle.h"

vehicle::vehicle()
{
	plate = "";
}

void vehicle::setPlate(string p)
{
	plate = p;
}

void vehicle::setin(float x, float y, float a ,float b, float c)
{
	timein.setTime(x, y,a,b,c);
}

void vehicle::setout(float x, float y, float a, float b, float c)
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
