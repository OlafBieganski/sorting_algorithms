#ifndef ARRAYGENERATOR
#define ARRAYGENERATOR
#include <iostream>
#include <time.h>
#include<sys/time.h>
#include "sortingAlgorithms.hh"

#define LOG(x) std::cout << x << std::endl

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
    bool isSorted(bool order);
    void mergeSrt();
    void quickSrt();
    void introSrt();
};

enum sortType {MERGE, QUICK, INTROSPECTIVE};

class Array2D {
private:
    Array* arr2D;
    int arr2Dsize;
public:
    Array2D() {arr2D = NULL; arr2Dsize = 0;}
    Array2D(int quantity, int elemSize);
    //~Array2D() {delete arr2D;} seg fault
    int size() {return arr2Dsize;}
    double sort(sortType name);
    bool isSorted(bool descOrder);
    void fillArr2D(float percOfSorted, bool descOrder);
    void display();
};

#endif