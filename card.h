#ifndef card_h
#define card_h
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <iomanip>
using namespace std;

struct Computer{
    char name[50] = "undefined";
    float frequency = 1.2;
    int RAM = 4;
    bool DVD_ROM = false;
    float price = 5000;
    
    void showInfo(){
        cout<<"Name: "<<name<<".\n";
        cout<<"Frequency: "<<frequency<<".\n";
        cout<<"RAM: "<<RAM<<".\n";
        cout<<"DVD ROM: "<<DVD_ROM<<".\n";
        cout<<"Price: "<<price<<".\n";
    }
};

#endif
