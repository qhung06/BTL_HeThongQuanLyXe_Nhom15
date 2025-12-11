#pragma once
#include "Time.h"
#include <string>
using namespace std;
class vehicle :public Time
{
protected:
    string plate;
    Time timein;
    Time timeout;
public:
    vehicle();
    vehicle(string plate, Time timein, Time timeout);
    void setPlate(string p);
    void setin(int x, int y, int a, int b, int c);
    void setout(int x, int y, int a, int b, int c);
    string getplate() const;
    Time getin() const;
    Time getout() const;
    virtual double calculateFee() = 0;
};