#include "car.h"

double car::calculateFee()
{
    if (timeout.toHours() == 0) 
        return -1;
    Time diff = timeout - timein;
    return diff.toHours() * 10000;
}

