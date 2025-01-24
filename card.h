#ifndef card_h
#define card_h
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <iomanip>
using namespace std;

struct Card{
    char name[30] = "undefined";
    unsigned long number = 0;
    double cash = 0;

    void createCard() {
        cout << "Input your name: ";
        cin.getline(name, 30);
        number = rand() * 1'000'000 + rand();
        cash = 1'000;
    }

    void showCard() {
        cout << "+++++++++++++++++++++++++++++\n";
        cout << "|\tClient: " << name << endl;
        cout << "|\tCard:   " << number << endl;
        cout << "|\tCash:   " << cash << " UAH" << endl;
        cout << "+++++++++++++++++++++++++++++\n";
    }
    
    void saveToBinFile(FILE* file){
        int nameLen = strlen(name) + 1;
        fwrite(&nameLen, sizeof(int), 1, file);
        fwrite(&name, sizeof(char), nameLen, file);
        fwrite(&number, sizeof(long), 1, file);
        fwrite(&cash, sizeof(double), 1, file);
    }
    
    void loadFromBinFile(FILE* file){
        int nameLen = 0;
        fread(&nameLen, sizeof(int), 1, file);
        fread(&name, sizeof(char), nameLen, file);
        fread(&number, sizeof(long), 1, file);
        fread(&cash, sizeof(double), 1, file);
    }
};

#endif /* card_h */
