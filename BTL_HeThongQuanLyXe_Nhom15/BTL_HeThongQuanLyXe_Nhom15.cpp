#include <iostream>
#include <fstream>
#include <string>
#include "parkinglot.h"
#include "car.h"
#include "motorbike.h"
#include <sstream>
#include <cstdio> 
using namespace std;

vehicle* createVehicleFromLine(string line)
{
    string plate, type;
    Time timein;
    stringstream ss(line);
    ss >> plate >> type >> timein;
    vehicle* v = nullptr;
    if (type == "CAR")
        v = new car();
    else
        if (type == "MOTORBIKE")
            v = new motorbike();
    if (v != nullptr)
    {
        v->setPlate(plate);
        v->setin(timein.gethour(), timein.getmin(), timein.getday(), timein.getmonth(), timein.getyear());
    }
    return v;
}

void Themxe(parkinglot lot1)
{
    ofstream outfile;
    outfile.open("DanhSachXeHienCo.txt", ios::app);
    string plate;
    Time in;
    vehicle* xe;
    char x;
    do
    {
        cout << "1.Xe may" << endl;
        cout << "2.O to" << endl;
        cout << "0.Quay lai" << endl;
        cin >> x;
        switch (x)
        {
        case '1':
            xe = new motorbike;
            cout << "Nhap bien so: ";
            cin.ignore();
            getline(cin, plate);
			outfile<<endl << plate << " MOTORBIKE ";
            cout << "Nhap thoi gian vao: ";
            cin >> in;
            outfile << in.gethour() << " " << in.getmin() << " " << in.getday() << " " << in.getmonth() << " " << in.getyear() << endl;
            xe->setPlate(plate);
            xe->setin(in.gethour(), in.getmin(), in.getday(), in.getmonth(), in.getyear());
            lot1.checkin(xe);
            continue;
        case '2':
            xe = new car;
            cout << "Nhap bien so: ";
            cin.ignore();
            getline(cin, plate);
            outfile<<endl << plate << " MOTORBIKE ";
            cout << "Nhap thoi gian vao: ";
            cin >> in;
			outfile << in.gethour()<<" "<<in.getmin()<<" "<< in.getday()<<" "<<in.getmonth()<<" "<< in.getyear() << endl;
            xe->setPlate(plate);
            xe->setin(in.gethour(), in.getmin(), in.getday(), in.getmonth(), in.getyear());
            lot1.checkin(xe);

            continue;
        default:
            continue;
        }
    } while (x!='0');
    outfile.close();

}

void Xuatxe(parkinglot lot1)
{
    ifstream file1;
    ofstream file2;
    string plate,plate1;
    Time out,in;
    cout << "Nhap bien so xe: ";
    cin.ignore();
    getline(cin, plate);
    cout << "Nhap thoi gian checkout (gio phut ngay thang nam): ";
    cin >>out;
    lot1.checkout(plate,out);
    
}



int main() 
{
    parkinglot lot;
    ifstream infile("DanhSachXeHienCo.txt");
    string line;
    while (getline(infile, line)) 
    {
        vehicle* v = createVehicleFromLine(line);
        lot.checkin(v);
    }
    char choice;
    do
    {
        cout << "---------MENU-----------" << endl;
        cout << "1.Them xe" << endl;
        cout << "2.Xuat xe" << endl;
        cout << "3.Danh sach xe dang gui" << endl;
        cout << "0.Ket thuc" << endl;
        cin >> choice;
        switch (choice)
        {
        case '1':
            Themxe(lot);
            continue;
        case '2':
            Xuatxe(lot);
            continue;
        case '3':
            lot.hienthixeTrongBai();
            do
            {
                cout << "0. Quay lai"<<endl;
                cin >> choice;
                switch (choice)
                {
                default:
                    continue;
                }
            } while (choice != '0');
            continue;
        case'0':
            return 0;
        }

    } while (1);
  
    return 0;
}
