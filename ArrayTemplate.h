#ifndef ArrayTemplate_h
#define ArrayTemplate_h
#include <iomanip>
#include <iostream>
#include <ctime>
using namespace std;
#pragma once

template <typename MyType>
void randArray(MyType arr[], int size, int a = 1, int b = 10) {
    for (int i = 0; i < size; i++){
            arr[i] = rand() % (b - a + 1) + a;
    }
}

template <typename Type>
void printArray(Type arr[], int size){
    for (int i = 0; i < size; i++){
        std::cout<<arr[i]<<" ";
    }
    std::cout<<"\n";
}

template <typename T>
int indexMax(T arr[], int size){
    T max = arr[0];
    int index = 0;
    for (int i=1; i<size; i++){
        if (arr[i]>max){
            max=arr[i];
            index = i;
        }
    }
    return index;
}

template <typename T>
int indexMin(T arr[], int size){
    T max = arr[0];
    int index = 0;
    for (int i=1; i<size; i++){
        if (arr[i]<max){
            max=arr[i];
            index = i;
        }
    }
    return index;
}

template <typename T>
int sum(T arr[], int size){
    T sum = arr[0];
    for (int i=1; i<size; i++){
        sum += arr[i];
    }
    return sum;
}

template <typename T>
int search(T arr[], int size, T n = 0){
    int ind = -1;
    for (int i=0; i<size; i++){
        if (n == arr[i]){
            ind = i;
        }
    }
    return ind;
}

template <typename T>
T sumBetween(T arr[], int size, int a, int b){
    T sum = arr[0];
    if (a<0 || b>=size || b<a){
        return -1;
    }
    for (int i=1; i<size; i++){
        sum += arr[i];
    }
    return sum;
}

template <typename T>
void smoothArray(T arr[], int size){
    cout<<"The starting array: ";
    for (int i=0; i<size; i++){
        std::cout<<arr[i]<<" ";
    }
    cout<<".\n";
    for (int j=0; j<5; j++){
        cout<<"Smoothing "<<j+1<<": ";
        for (int i=0; i<size-1; i++){
            arr[i] = (arr[i]+arr[i+1])/2;
            cout<<arr[i]<<" ";
        }
        cout<<arr[size-1]<<".\n";
    }
}

template <typename T>
double averageMoreM(T arr[], int size, int m){
    double sum = 0;
    int amount = 0;
    for (int i=0; i<size; i++){
        if (arr[i] > m){
            sum += arr[i];
            amount++;
        }
    }
    return sum/amount;
}

template <typename T>
void equationRoot(T a, T b, T c){
    if (a == 0){
        std::cout<<"Equation: "<<b<<"x + "<<c<<" = 0.\nRoot: "<<-c/b<<".\n";
    }
    else{
        T d = b*b-4*a*c;
        if (d == 0){
            std::cout<<"Equation: "<<a<<"x^2 + "<<b<<"x + "<<c<<" = 0.\nRoot: "<<(-b+sqrt(d))/(2*a)<<".\n";
        }
        else if (d > 0){
            std::cout<<"Equation: "<<a<<"x^2 + "<<b<<"x + "<<c<<" = 0.\nRoots: "<<(-b+sqrt(d))/(2*a)<<" and "<<(-b-sqrt(d))/(2*a)<<".\n";
        }
        else{
            std::cout<<"Equation: "<<a<<"x^2 + "<<b<<"x + "<<c<<" = 0.\nRoots: no roots.\n";
        }
    }
}

template <typename T>
void addItemBack(T* &arr, int& size, T value){
    T* t = new T[size+1];
    for (int i=0; i<size; i++){
        t[i] = arr[i];
    }
    t[size] = value;
    size++;
    if (arr!=nullptr){
        delete[] arr;
    }
    arr = t;
}

template <typename T>
void addItemFront(T* &arr, int& size, T value){
    T* t = new T[size+1];
    t[0] = value;
    for (int i=0; i<size; i++){
        t[i+1] = arr[i];
    }
    size++;
    if (arr!=nullptr){
        delete[] arr;
    }
    arr = t;
}

template <typename T>
void deleteItem(T* &arr, int& size, int index){
    if (index<0||index>=size){
        return;
    }
    T* t = new T[size-1];
    for(int i=0; i<size; i++){
        if (i<index){
            t[i] = arr[i];
        }
        else{
            t[i] = arr[i+1];
        }
    }
    size--;
    if (arr!=nullptr){
        delete[] arr;
    }
    arr = t;
}

template <typename T>
int countIf(T *arr, int size, bool(*fP)(T)){
    int c = 0;
    for (int i=0; i<size; i++){
        if(fP(arr[i])) c++;
    }
    return c;
}

template <typename T>
T sumIf(T *arr, int size, bool(*fP)(T)){
    T sum = 0;
    for (int i=0; i<size; i++){
        if(fP(arr[i])) sum+=arr[i];
    }
    return sum;
}

template <typename T>
T findIf(T *arr, int size, bool(*fP)(T)){
    T f = 0;
    for (int i=0; i<size; i++){
        if(fP(arr[i])) f=i;
        break;
    }
    return f+1;
}

template <typename T>
void removeIf(T *&arr, int &size, bool(*fP)(T)){
    int c = countIf<T>(arr, size, fP);
    T *temp = new T[size - c];
    int j = 0;
    for (int i=0; i<size; i++){
        if(!fP(arr[i])){
            temp[j] = arr[i];
            j++;
        }
    }
    if (arr != nullptr) delete[] arr;
    size -= c;
    arr = temp;
}

template <typename T>
void replaceIf(T *arr, int size, bool(*fP)(T), T value){
    for (int i=0; i<size; i++){
        if(fP(arr[i])){
            arr[i] = value;
        }
    }
}

template <typename T>
void createMemory(T**& matr, int row, int col){
    matr = new T*[row];
    for (int i=0; i<row; i++){
        matr[i] = new T[col]{0};
    }
}

template <typename T>
void freeMemory(T**& matr, int& row, int& col){
    for (int i=0; i<row; i++){
        delete[] matr[i];
    }
    delete[] matr;
    matr = nullptr;
    row = 0;
    col = 0;
}

template <typename T>
void randArray(T**& matr, int row, int col, int a = 0, int b = 10){
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            matr[i][j] = rand()%(b - a +1 ) + a;
        }
    }
}

template <typename T>
void printArray(T**& matr, int row, int col){
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            std::cout<<matr[i][j]<<" ";
        }
        std::cout<<"\n";
    }
    std::cout<<"\n";
}

template <typename T>
void calcSumAndProduct(T**& matr, int row, int col, int k, T& sum, T& prod){
    if(k<0 || k>row){
        return;
    }
    sum = 0, prod = 1;
    for (int i=0; i<col; i++){
        sum += matr[k][i];
        prod *= matr[k][i];
    }
}

template <typename T>
void insertRow(T**& matr, int& row, int col, int k){
    T** created = new T*[row+1];
    for(int i=0; i<row+1; i++){
        if(i<k){
            created[i] = matr[i];
        }
        else if(i==k){
            created[i] = new T[col]{0};
        }
        else{
            created[i] = matr[i-1];
        }
    }
    delete[] matr;
    matr = created;
    row++;
}

template <typename T>
void insertTwoRows(T**& matr, int &row, int col, int index1, int index2){
    T** created = new T*[row+2];
    for(int i=0; i<row+2; i++){
        if(i<index1){
            created[i] = matr[i];
        }
        else if(i == index1 or i == index2){
            created[i] = new T[col]{0};
        }
        else if(i > index1 and i < index2){
            created[i] = matr[i-1];
        }
        else{
            created[i] = matr[i-2];
        }
    }
    delete[] matr;
    matr = created;
    row+=2;
}

template <typename T>
void insertCol(T**& matr, int row, int& col, int k){
    for(int j=0; j<row; j++){
        T* created = new T[col+1];
        for(int i=0; i<col+1; i++){
            if(i<k){
                created[i] = matr[j][i];
            }
            else if(i==k){
                created[i] = 0;
            }
            else{
                created[i] = matr[j][i-1];
            }
        }
        delete[] matr[j];
        matr[j] = created;
    }
    col++;
}

template <typename T>
void moveRowsUp(T**& matr, int row, int col){
    T *tempArr = matr[0];
    for (int i=0; i<row-1; i++) {
        matr[i] = matr[i+1];
    }
    matr[row-1] = tempArr;
}

void printTriangle(int row){
    int col = row/2+1;
    char **matr = nullptr;
    createMemory(matr, row, col);
    for (int i=0; i<row; i++) {
        if (i <= row/2) {
            for (int j=0; j<i+1; j++) {
                matr[i][j] = '*';
            }
        }
        else{
            for (int j=0; j<row-i; j++) {
                matr[i][j] = '*';
            }
        }
    }
    printArray(matr, row, col);
    freeMemory(matr, row, col);
}

void incTime(int& h, int& m, int& s, int t){
    int time = h * 3600 + m * 60 + s + t;
    h = (time / 3600) % 24;
    m = (time / 60) % 60;
    s = time % 60;
}

void invertDigits(int &k){
    int d = 1;
    int r = 0;
    int t = k;
    while (t / 10) {
        d++;
        t /= 10;
    }
    for (int i=0; i<d; i++) {
        r += k % 10 * pow(10, d - 1 - i);
        k /= 10;
    }
    k = r;
}

template <typename T>
void createSubArray(T*& aBegin, int& sSize, int iStart, int iEnd){
    int size = iEnd - iStart;
    T* aResult = new T[size];
    for (int i=0; i<size; i++) {
        aResult[i] = aBegin[i + iStart];
    }
    if(aBegin != nullptr){delete[] aBegin;}
    sSize = size;
    aBegin = aResult;
}

template <typename T>
void sortArrayIf(T *&arr, int size, bool(*fP)(T, T)){
    T t;
    for (int i=0; i<size-1; i++) {
        for (int j=0; j<size-i-1; j++) {
            if (fP(arr[j], arr[j+1])) {
                t = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = t;
            }
        }
    }
}

template <typename T>
int findLastIf(T *arr, int size, bool(*fP)(T)){
    int index = -1;
    for (int i=0; i<size; i++) {
        if (fP(arr[i])) {
            index = i;
        }
    }
    return index;
}

struct Student{
    char name[51] = "";
    int math = 0;
    int phys = 0;
    int info = 0;
    
    void showInfo(){
        std::cout<<"Name: "<<name<<std::endl;
        std::cout<<"Math: "<<math<<std::endl;
        std::cout<<"Phys: "<<phys<<std::endl;
        std::cout<<"Info: "<<info<<std::endl;
    }
};

struct Country{
    char name[51] = "";
    char worldPart[51] = "";
    int area = 0;
    int population = 0;
    
    void showInfo(){
        cout<<"Name: "<<name<<endl;
        cout<<"World part: "<<worldPart<<endl;
        cout<<"Area: "<<area<<endl;
        cout<<"Population: "<<population<<endl;
    }
    
    void showTable(){
        cout<<"|"<<setw(15)<<name
        <<"|"<<setw(10)<<worldPart
        <<"|"<<setw(6)<<area
        <<"|"<<setw(10)<<population
        <<"|"<<endl;
    }
};

struct Date {
    int day = 0;
    int month = 0;
    int year = 0;
    char str[50] = "";

    void fillDate() {
        cout << "Day -> ";
        cin >> day;
        cout << "Month -> ";
        cin >> month;
        cout << "Year -> ";
        cin >> year;
    }

    void printDate() {
        cout << day / 10 << day % 10 << "." << month / 10 << month % 10 << "." << year << endl;
    }

    const char* toString(const char* format = "%d %B %Y") {
        tm dateInfo = { 0, 0, 0, day, month - 1, year - 1900 };
        strftime(str, 50, format, &dateInfo);
        return str;
    }

    void getNowDate() {
        time_t seconds = time(NULL);
        tm *dateInfo = new tm{ 0 };
        dateInfo = localtime( &seconds);

        year = dateInfo->tm_year + 1900;
        month = dateInfo->tm_mon + 1;
        day = dateInfo->tm_mday;
        delete dateInfo;
    }

    void toNextDate() {
        tm *dateInfo = new tm { 0, 0, 0, day, month - 1, year - 1900 };
        time_t seconds = mktime(dateInfo);
        seconds += 3600 * 24; // + 1 day
        localtime(&seconds);

        year = dateInfo->tm_year + 1900;
        month = dateInfo->tm_mon + 1;
        day = dateInfo->tm_mday;
        delete dateInfo;
    }

    void toPrevDate() {
        tm *dateInfo = new tm { 0, 0, 0, day, month - 1, year - 1900 };
        time_t seconds = mktime(dateInfo);
        seconds -= 3600 * 24; // - 1 day
        localtime(&seconds);

        year = dateInfo->tm_year + 1900;
        month = dateInfo->tm_mon + 1;
        day = dateInfo->tm_mday;
        delete dateInfo;
    }

    void addDays(int d) {
        tm *dateInfo = new tm{ 0, 0, 0, day, month - 1, year - 1900 };
        time_t seconds = mktime(dateInfo);
        seconds += 3600 * 24 * d; // + d days
        localtime(&seconds);

        year = dateInfo->tm_year + 1900;
        month = dateInfo->tm_mon + 1;
        day = dateInfo->tm_mday;
        delete dateInfo;
    }

    void delDays(int d) {
        tm *dateInfo = new tm { 0, 0, 0, day, month - 1, year - 1900 };
        time_t seconds = mktime(dateInfo);
        seconds -= 3600 * 24 * d; // - d days
        localtime(&seconds);

        year = dateInfo->tm_year + 1900;
        month = dateInfo->tm_mon + 1;
        day = dateInfo->tm_mday;
    }
};

struct Violation{
    Date dateViol;
    char info[100] = "";
    float fine = 0;
    
    void fillViolation(){
        cout<<"Input date (dd mm yyyy): ";
        cin>>dateViol.day>>dateViol.month>>dateViol.year;
        cout<<"Input info: ";
        cin.ignore();
        cin.getline(info, 100);
        cout<<"Input fine: ";
        cin>>fine;
    }
    
    void printViolation(){
        cout<<"\t Date: "<<dateViol.toString()<<endl;
        cout<<"\t Info: "<<info<<endl;
        cout<<"\t Fine: "<<fine<<" UAH.\n";
    }
};

struct Driver{
    char name[100] = "";
    char carNum[20] = "";
    int sizeViol = 0;
    Violation* violArr = nullptr;
    
    void fillDriver(){
        cout<<"Input name: ";
        cin.getline(name, 100);
        cout<<"Input number: ";
        cin>>carNum;
        sizeViol = 1;
        violArr = new Violation[1];
        violArr[0].fillViolation();
    }
    
    void printDriver(){
        cout<<"Name: "<<name<<endl;
        cout<<"Car number: "<<carNum<<endl;
        cout<<"Violation amount: "<<sizeViol<<endl;
        for (int i=0; i<sizeViol; i++){
            cout<<"№"<<i+1<<endl;
            violArr[i].printViolation();
        }
    }
};

struct VideoFilm{
    char name[50] = "";
    char director[50] = "";
    char genre[50] = "";
    int rating = 0;
    int price = 0;
    
    void printFilm(){
        cout<<"Name: "<<name
        <<",\nDirector: "<<director
        <<",\nGenre: "<<genre
        <<",\nRating: "<<rating
        <<",\nPrice: "<<price<<"₴.\n\n";
    }
};

void sortVideoFilmsArray(VideoFilm *&arr, int size){
    VideoFilm t;
    for (int i=0; i<size-1; i++) {
        for (int j=0; j<size-i-1; j++) {
            if (arr[j].rating < arr[j+1].rating) {
                t = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = t;
            }
        }
    }
}

#endif
