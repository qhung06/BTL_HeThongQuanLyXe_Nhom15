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
    void setin(float x, float y, float a, float b, float c);
    void setout(float x, float y, float a, float b, float c);
    string getplate() const;
    Time getin() const;
    Time getout() const;
	virtual void enter() = 0; 
    virtual double calculateFee() = 0;
};