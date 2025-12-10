#pragma once
#include "vehicle.h"
class parkingslot
{
	vehicle* xe;
	int id;
public:
	parkingslot();
	parkingslot(int id);
	bool ktra() const;
	int getid() const;
	vehicle* getxe() const;
	void park(vehicle* v);
	vehicle* leave(Time timeout);
};

