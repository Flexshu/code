#ifndef TicTacToeTemplate_h
#define TicTacToeTemplate_h
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <iomanip>
using namespace std;
#pragma once

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

struct Cell{
    char contant = ' ';
};

struct Board{
    int rows = 0;
    int cols = 0;
    int elToWin = 0;
    char playerSign = 'O';
    char enemySign = 'X';
    Cell **field = nullptr;
    
    void createMemory(){
        field = new Cell*[rows];
        for (int i=0; i<rows; i++){
            field[i] = new Cell[cols];
        }
    }
    
    void freeMemory(){
        for (int i=0; i<rows; i++){
            delete[] field[i];
        }
        delete[] field;
        field = nullptr;
        rows = 0;
        cols = 0;
    }
    
    void printBoard(){
        for (int i=0; i<cols; i++) {
            cout<<"------";
        }
        cout<<"-\n";
        for (int j=0; j<rows; j++) {
            for (int i=0; i<cols; i++){
                cout<<"| ";
                cout.width(3);
                cout<<" ";
                cout.width(1);
                cout<<" ";
            }
            cout<<"|\n";
            for (int i=0; i<cols; i++) {
                cout<<"| ";
                cout.width(3);
                if (field[j][i].contant != ' ') {
                    cout<<field[j][i].contant;
                    cout.width(1);
                    cout<<" ";
                }
                else{
                    cout<<j*cols+i+1;
                    cout.width(1);
                    cout<<" ";
                }
            }
            cout<<"|\n";
            for (int i=0; i<cols; i++){
                cout<<"| ";
                cout.width(3);
                cout<<" ";
                cout.width(1);
                cout<<" ";
            }
            cout<<"|\n";
            for (int i=0; i<cols; i++) {
                cout<<"------";
            }
            cout<<"-\n";
        }
    }
    
    void playerMove(){
        bool checker = true;
        int n = 0;
        while (checker) {
            cout<<"Choose a cell: ";
            cin>>n;
            n--;
            if (field[n/cols][n%cols].contant == ' ') {
                field[n/cols][n%cols].contant = playerSign;
                checker = false;
            }
        }
    }
    
    void enemyMove(){
        bool checker = true;
        int n = 0;
        while (checker) {
            n = rand()%(rows*cols)+1;
            n--;
            if (field[n/cols][n%cols].contant == ' ') {
                field[n/cols][n%cols].contant = enemySign;
                checker = false;
            }
        }
    }
    
    bool checkVictory(char symbol){
        bool result = false;
        for (int i=0; i<rows; i++) {
            for (int j=0; j<cols; j++) {
                result = true;
                for (int k=1; k<elToWin; k++) {
                    if (field[i][j].contant != field[i][j+k].contant or field[i][j].contant != symbol) {
                        result = false;
                        break;
                    }
                }
                if (result) {
                    return result;
                }
                result = true;
                for (int k=1; k<elToWin; k++) {
                    if (i+k<rows) {
                        if (field[i][j].contant != field[i+k][j].contant or field[i][j].contant != symbol) {
                            result = false;
                            break;
                        }
                    }
                    else{
                        result = false;
                    }
                }
                if (result) {
                    return result;
                }
                result = true;
                for (int k=1; k<elToWin; k++) {
                    if (i+k<rows) {
                        if (field[i][j].contant != field[i+k][j+k].contant or field[i][j].contant != symbol) {
                            result = false;
                            break;
                        }
                    }
                    else{
                        result = false;
                    }
                }
                if (result) {
                    return result;
                }
                result = true;
                for (int k=1; k<elToWin; k++) {
                    if (i+k<rows) {
                        if (field[i][j].contant != field[i+k][j-k].contant or field[i][j].contant != symbol) {
                            result = false;
                            break;
                        }
                    }
                    else{
                        result = false;
                    }
                }
                if (result) {
                    return result;
                }
            }
        }
        return result;
    }
    
    bool checkDraw(){
        bool result = true;
        for (int i=0; i<rows; i++) {
            for (int j=0; j<cols; j++) {
                if (field[i][j].contant == ' ') {
                    result = false;
                    return result;
                }
            }
        }
        return result;
    }
};

#endif
