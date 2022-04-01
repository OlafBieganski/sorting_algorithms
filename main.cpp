#include <iostream>
#include "./sortingAlgorithms.hh"
#include "arrayGenerator.hh"

#define LOG(x) std::cout << x << std::endl

using namespace std;

int main(int argc, char ** argv){

Array2D arr(5, 10);
arr.fillArr2D(0, false);
arr.display();
cout << "Array is sorted = " << arr.isSorted(false) << endl;
cout << "Time of sorting = " << arr.sort(QUICK) << endl;
arr.display();
cout << "Array is sorted = " << arr.isSorted(false) << endl;

return 0;
}

