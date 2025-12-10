#include "parkinglot.h"
#include <iostream>
using namespace std;

parkinglot::parkinglot() 
{
    slotcount = 100;
    ticketcount = 0;
    for (int i = 0; i < slotcount; i++)
        slots[i] = new parkingslot(i+1);
}

int parkinglot::timchotrong() 
{
    for (int i = 0; i < slotcount; i++)
        if (slots[i]->ktra())
            return i;
    return -1;
}

bool parkinglot::checkin(vehicle* v) 
{
    int idx = timchotrong();
    if (idx == -1) 
    {
        cout << "Full parking!\n";
        return false;
    }
    slots[idx]->park(v);
    tickets[ticketcount++] = new ticket(slots[idx]);
   // cout << "Vehicle " << v->getplate()<< " parked at slot " << slots[idx]->getid() << "\n";
    return true;
}

bool parkinglot::checkout(string plate, Time timeout) 
{
    for (int i = 0; i < slotcount; i++) 
    {
        vehicle* v = slots[i]->getxe();
        if (v && v->getplate() == plate) 
        {
            for (int j = 0; j < ticketcount; j++)                 // Tìm ticket
            {
                if (tickets[j]->getPlate() == plate)
                {
                    tickets[j]->closeTicket(timeout);
                    tickets[j]->print();
                    slots[i]->leave(timeout);
                    cout << "Vehicle " << plate << " checked out.\n";
                    return true;
                }
            }
        }
    }
    cout << "Vehicle not found!\n";
    return false;
}

void parkinglot::hienthixeTrongBai()
{
    cout << "\n========= DANH SACH XE DANG TRONG BAI =========\n";
    bool found = false;
    for (int i = 0; i < slotcount; i++)
    {
        if (slots[i]->getxe() != nullptr)
        {
            vehicle* v = slots[i]->getxe();
            cout << "Vi tri: " << slots[i]->getid();
            cout << " | Bien so: " << v->getplate();
            cout << " | Check-in: " << v->getin()<<endl;            
            found = true;
        }
    }
    if (!found)
    {
        cout << "Hien khong co xe nao trong bai!\n";
    }
}
