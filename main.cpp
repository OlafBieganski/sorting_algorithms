#include <iostream>
#include "./sortingAlgorithms.hh"
#include <time.h>
#include "arrayGenerator.hh"

#define LOG(x) std::cout << x << std::endl

using namespace std;

int main(int argc, char ** argv){

    // Start measuring time
    struct timespec begin, end; 
    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &begin);



    // Stop measuring time and calculate the elapsed time
    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &end);
    long seconds = end.tv_sec - begin.tv_sec;
    long nanoseconds = end.tv_nsec - begin.tv_nsec;
    double elapsed = seconds + nanoseconds*1e-9;
    
    cout << "Całkowity czas: " << elapsed << endl;
 
return 0;
}

