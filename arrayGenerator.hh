#ifndef ARRAYGENERATOR
#define ARRAYGENERATOR
#include <iostream>

class Array {
private:
    int* arr;
    int arrSize;
public:
    Array() {arr = NULL; arrSize = 0;}
    Array(int size);
    ~Array() {delete arr;}
    int size() {return arrSize;}
    void makeSortArr(int size, float percOfSorted);
    void makeInvArr(int size);
    void display();
};

class Array2D {
private:
    Array* arr2D;
    int arr2Dsize;
public:
    Array2D() {arr2D = NULL; arr2Dsize = 0;}
    Array2D(int size);
    ~Array2D() {delete arr2D;}
    int size() {return arr2Dsize;}
};

#endif