#pragma once
#include "vehicle.h"
class car : public vehicle
{
	void enter() override;
	double calculateFee() override;

};

