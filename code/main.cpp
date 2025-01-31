#include <iostream>
#include <ctime>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <iomanip>
#include "card.h"
#include "ArrayTemplate.h"
using namespace std;



int main(){
    setlocale(LC_ALL, "");
    srand(time(0));
    
    Card* object = nullptr;
    int menu = 1;
    int PIN = 0, oldPIN = 0;
    double cash = 0;
    
    while (menu) {
        if (object == nullptr) {
            cout<<"1. Create a standard card.\n2. Create a VIP card.\n";
            cin>>menu;
            if (menu == 1) {
                object = new Card();
                object->showInfo();
            }
            else if(menu == 2){
                object = new Card("Yehor Kovalenko");
                object->showInfo();
            }
            else{
                cout<<"Error:(.\n";
            }
        }
        else{
            cout<<"1. Show info.\n2. Diposit money.\n3. Withdraw money.\n4. Change PIN.\n";
            cin>>menu;
            switch (menu) {
                case 1:
                    cout<<"Enter PIN: ";
                    cin>>PIN;
                    if (PIN == object->getPIN()) {
                        object->showInfo();
                    }
                    break;
                case 2:
                    cout<<"Enter cash: ";
                    cin>>cash;
                    object->depositCash(cash);
                    cout<<"Now you have "<<object->getCash()<<endl;
                    break;
                case 3:
                    cout<<"Enter cash: ";
                    cin>>cash;
                    cout<<"Enter PIN: ";
                    cin>>PIN;
                    object->withdrawCash(cash, PIN);
                    cout<<"Now you have "<<object->getCash()<<endl;
                    break;
                    break;
                case 4:
                    cout<<"Enter PIN: ";
                    cin>>PIN;
                    if (PIN == object->getPIN()) {
                        oldPIN = PIN;
                        cout<<"Enter new PIN: ";
                        cin>>PIN;
                        object->setPIN(oldPIN, PIN);
                        cout<<"Your new PIN is "<<object->getPIN()<<endl;
                    }
                    break;
                default:
                    break;
            }
        }
    }
    
    delete object;
    return 0;
}
