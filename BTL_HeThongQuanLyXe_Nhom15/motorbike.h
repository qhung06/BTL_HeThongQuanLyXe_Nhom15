#pragma once
#include "vehicle.h"

class motorbike: public vehicle
{
	void enter() override;
	double calculateFee() override;
};

