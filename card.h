#pragma once
#include <iostream>
#include <cstring>
using namespace std;

class Card {
    char* name;
    unsigned long num;
    char date[6];
    int PIN;
    double cash;
    
public:
    Card(){
        name = new char[10]{"undefined"};
        num = rand()%(99999 - 10000 + 1) + 10000;
        strcpy(date, "01.34");
        PIN = rand()%(9999 - 1000 + 1) + 1000;
        cash = 0;
        cout<<"Standard card: "<<num<<endl;
    }
    
    Card(const char* name){
        this->name = new char[strlen(name)+1];
        strcpy(this->name, name);
        num = rand()%(99999 - 10000 + 1) + 10000;
        strcpy(date, "01.34");
        PIN = rand()%(9999 - 1000 + 1) + 1000;
        cash = 0;
        cout<<"VIP card: "<<num<<endl;
    }
    ~Card(){
        delete[] name;
        cout<<"Card "<<num<<" is closed.\n";
    }
    
    const char* getName(){return name;}
    unsigned long getNum(){return num;}
    const char* getDate(){return date;}
    int getPIN(){return PIN;}
    double getCash(){return cash;}
    
    void setPIN(int oldPIN, int newPIN){
        if (oldPIN == PIN) {
            PIN = newPIN;
        }
        else{
            cout<<"Don't try to change this card's PIN if you're not the owner.\n";
        }
    }
    
    void dipositCash(double cash){
        this->cash += cash;
    }
    void dwithdrawCash(double cash, int PIN){
        if (PIN == this->PIN) {
            if (this->cash - cash >= 0) {
                this->cash -= cash;
            }
            else{
                cout<<"You're broke.\n";
            }
        }
        else{
            cout<<"Wrong PIN.\n";
        }
    }
    
    void showInfo(){
        cout<<"Name: "<<name<<",\n"
        <<"Card's num: "<<num<<",\n"
        <<"Expire date: "<<date<<",\n"
        <<"PIN: "<<PIN<<",\n"
        <<"Cash: "<<cash<<".\n";
    }
};
