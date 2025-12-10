#pragma once
#include "vehicle.h"
#include "parkingslot.h"
class ticket
{
    parkingslot* slot;
    Time timein;
    Time timeout;
    double fee;
    string type;
public:
    ticket(parkingslot* s);
    void closeTicket(Time outtime);
    void print();
    string getPlate();
};

