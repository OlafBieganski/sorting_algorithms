#include <iostream>
#include <fstream>
#include "./sortingAlgorithms.hh"
#include "arrayGenerator.hh"

#define LOG(x) std::cout << x << std::endl

using namespace std;

int main(int argc, char ** argv){

    float percents[] = {0, 25, 50, 75, 95, 99, 99.7};
    int numOfElems[] = {10000, 50000, 100000, 500000, 1000000};
    bool order[] = {0,0,0,0,0,0,0,1};
    sortType sort[] = {MERGE, QUICK, INTROSPECTIVE};
    string sortNames[] = {"Merge Sort", "Quick Sort", "Introspective Sort"};
    int sizePerc = sizeof(percents) / sizeof(percents[0]);
    int sizeElems = sizeof(numOfElems) / sizeof(numOfElems[0]);

    fstream File;
    string filename;
    LOG("Podaj nazwe dla pliku z czasem wykonywania algorytmow (.txt):");
    cin >> filename;
    File.open(filename, ios::out);
    if(!File.is_open()){
        LOG("Blad otwarcia pliku.");
        return 1;
    }

    for(int k = 0; k < 3; k++){
        File << sortNames[k] << '\n';
        for(int i = 0; i < sizePerc; i++){
            for(int j = 0; j < sizeElems; j++){
                Array2D arr(100, numOfElems[j]);
                arr.fillArr2D(percents[i], order[i]);
                //cout << "Array is sorted = " << arr.isSorted(order[i]) << endl;
                File << arr.sort(sort[k]) << '\t';
                cout << "Array is sorted = " << arr.isSorted(order[i]) << endl;
            }
            File << '\n';
        }
    }

    File.close();
    return 0;
}

