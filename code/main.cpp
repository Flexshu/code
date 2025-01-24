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
    
    Computer* arr = new Computer[5]{{"HP", 2.4, 8, false, 20000}, {"Acer", 3.2, 16, true, 60000}, {"HP 2.0", 1.4, 8, false, 15000}, {"Dell", 3.4, 32, true, 75000}, {"Asus", 2.6, 16, true, 35000}};
    for (int i=0; i<5; i++) {
        arr[i].showInfo();
    }
    
    return 0;
}
