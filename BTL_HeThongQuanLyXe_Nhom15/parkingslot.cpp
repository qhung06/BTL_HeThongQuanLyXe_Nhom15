#include "parkingslot.h"

parkingslot::parkingslot() 
{
    id = 0;
}

parkingslot::parkingslot(int id) 
{
    this->id = id;
    xe = nullptr;
}

bool parkingslot::ktra() const
{
    return xe == nullptr; 
}

int parkingslot::getid() const
{
    return id; 
}

vehicle* parkingslot::getxe() const
{
    return xe;
}

void parkingslot::park(vehicle* v) 
{
    xe = v; 
}

vehicle* parkingslot::leave(Time timeout) 
{
    if (!xe) 
        return nullptr;
    xe->setout(timeout.gethour(), timeout.getmin(),  timeout.getday(),  timeout.getmonth(),  timeout.getyear());
    vehicle* temp = xe;
    xe = nullptr;
    return temp;
}
