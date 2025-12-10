#include "motorbike.h"

double motorbike::calculateFee() 
{
    if (timeout.toHours() == 0) 
        return -1;
    Time diff = timeout - timein;
    return diff.toHours() * 5000;
}
