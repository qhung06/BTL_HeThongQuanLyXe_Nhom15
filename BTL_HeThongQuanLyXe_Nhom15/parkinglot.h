#pragma once
#include "parkingslot.h"
#include "car.h"
#include "motorbike.h"
#include "ticket.h"
#include <sstream>

class parkinglot 
{
    parkingslot* slots[100];
    ticket* tickets[100];
    int slotcount;
    int ticketcount;
public:
    parkinglot();
    int timchotrong();
    bool checkin(vehicle* v);
    bool checkout(string plate, Time timeout);
    void hienthixeTrongBai();
	void checkinput();
};