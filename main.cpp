#include <iostream>
#include "./sortingAlgorithms.hh"
#include "arrayGenerator.hh"

#define LOG(x) std::cout << x << std::endl

using namespace std;

int main(int argc, char ** argv){

Array2D arr(100, 1000000);
arr.fillArr2D(50, false);
//arr.display();
cout << "Array is sorted = " << arr.isSorted(true) << endl;
cout << "Time of sorting = " << arr.sort(MERGE) << endl;
//arr.display();
cout << "Array is sorted = " << arr.isSorted(false) << endl;

return 0;
}

