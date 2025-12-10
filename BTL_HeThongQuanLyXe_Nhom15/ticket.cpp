#include "ticket.h"
#include <iostream>
#include<fstream>

ticket::ticket(parkingslot* s) 
{
    slot = s;
    if (s != nullptr && s->getxe() != nullptr)
    timein = s->getxe()->getin();
    fee = 0;
}

void ticket::closeTicket(Time outtime) 
{
    timeout = outtime;
    slot->getxe()->setout(outtime.gethour(), outtime.getmin(), outtime.getday(), outtime.getmonth(), outtime.getyear());
    fee = slot->getxe()->calculateFee();
}

void ticket::print() 
{
    ofstream outfile;
    outfile.open("LuuTruVe.txt",ios::app);
    if (!outfile)
        cout << "mo tep bi loi!";
    else
    {
        outfile << "\n===== TICKET =====\n";
        outfile << "Plate: " << slot->getxe()->getplate() << "\n";
        outfile << "Slot : " << slot->getid() << "\n";
        outfile << "Time in : " << timein << "\n";
        outfile << "Time out: " << timeout << "\n";
        outfile << "Fee: " << fee << " VND\n";
        outfile << "==================\n";
    }
    outfile.close();
}

string ticket::getPlate() 
{
    return slot->getxe()->getplate(); 
}
