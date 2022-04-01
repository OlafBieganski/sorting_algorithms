#include "arrayGenerator.hh"

using namespace std;

Array::Array(int size){
    // alokujemy tablice odp rozmiaru
    int* arr1 = new int[size];
    arr = arr1;
    arrSize = size;
    // domyslnie wypelniamy zerami
    for(int i = 0; i < size; i++){
        arr[i] = 0;
    }
}

// wypelnij tablice iloscia size elementow z ktorch perOfSorted poczatkowych jest posortowanych
// percOfSorted = <0;100>
void Array::makeSortArr(int size, float percOfSorted){

    // sprawdzamy czy wlasciwy paramter 
    if(percOfSorted > 100 || percOfSorted < 0){
        cout << "BLAD: Parametr percOfSorted z poza zakresu <0;100>" << endl;
    }
    else{
        // jezeli wczesniej jako arr alokowano tablice
        //if(arr != NULL) delete arr; powodowało błąd podwojne usuniecie danych?

        // alokujemy tablice odp rozmiaru
        int* arr1 = new int[size];

        // wyliczamy ilosc posortowanych elem
        int sorted = size * (percOfSorted/100);
        // generujemy precyzyjny seed dla rand()
        struct timeval t1;
        gettimeofday(&t1, NULL);
        srand(t1.tv_usec * t1.tv_sec);

        int sum = 0;
        // pierwsza czesc posortowane
        for(int i = 0; i < sorted; i++){
            sum += rand() % 100;
            arr1[i] = sum;
        }
        // druga losowe
        for(int i = sorted; i < size; i++)
            arr1[i] = rand() - (RAND_MAX/2);

        // przepisujemy odp wartosci do obiektu
        arr = arr1;
        arrSize = size;
    }
}

void Array::makeInvArr(int size){
    // jezeli wczesniej jako arr alokowano tablice
    //if(arr != NULL) delete arr;
    // alokujemy tablice odp rozmiaru
    int* arr1 = new int[size];
    // generujemy precyzyjny seed dla rand()
    struct timeval t1;
    gettimeofday(&t1, NULL);
    srand(t1.tv_usec * t1.tv_sec);
    int sum = 0;
    for(int i = size-1; i >= 0; i--){
        // zapełniamy losowymi liczbami rosnąco zaczynajc od tylu tab
        sum += rand() % 100;
        arr1[i] = sum;
    }
    // przepisujemy odp wartosci do obiektu
    arr = arr1;
    arrSize = size;
}

void Array::display(){
    if(arr != NULL){
        for(int i = 0; i < arrSize; i++)
            cout << "tab[" << i << "] = " << arr[i] << endl;
    }
    else cout << "Tablica jest pusta" << endl;
}

// sprawdza poprawnosc posortowania tablicy
// order==true rosnaco, order==false malejaco
// zwraca true jesli poprawnie posortowana, false jesli zle
bool Array::isSorted(bool order){
    if(order == true){
        for(int i = 0; i < arrSize-1; i++){
            if(arr[i] > arr[i+1]) return false;
        }
    }
    else{
        for(int i = 0; i < arrSize-1; i++){
            if(arr[i+1] > arr[i]) return false;
        }
    }
    return true;
}

void Array::mergeSrt(){
    mergeSort(arr, 0, arrSize-1);
}

void Array::quickSrt(){
    quicksort(arr, 0, arrSize-1);
}

void Array::introSrt(){

}

// quantity = ilosc tablic, elemSize = elementow w jedej tablicy
Array2D::Array2D(int quantity, int elemSize){
    // tworzymy odpowiednia ilosc tablic
    Array* arrays = new Array[quantity];
    //
    for(int i = 0; i < quantity; i++){
        arrays[i] = Array(elemSize);
    }
    arr2Dsize = quantity;
    arr2D = arrays;
}

void Array2D::fillArr2D(float percOfSorted, bool descOrder){
    if(descOrder == true){
        for(int i = 0; i < arr2Dsize; i++){
            arr2D[i].makeInvArr(arr2D[0].size());
        }
    }
    else{
        for(int i = 0; i < arr2Dsize; i++){
            arr2D[i].makeSortArr(arr2D[0].size(), percOfSorted);
        }
    }
}

double Array2D::sort(sortType name){
    // Start measuring time
    struct timespec begin, end; 
    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &begin);

    switch (name)
    {
    case MERGE:
        for(int i = 0; i < arr2Dsize; i++)
            arr2D[i].mergeSrt();
        break;
    case QUICK:
        for(int i = 0; i < arr2Dsize; i++)
            arr2D[i].quickSrt();
        break;
    case INTROSPECTIVE:
        for(int i = 0; i < arr2Dsize; i++)
            arr2D[i].introSrt();
        break;
    default:
        LOG("Error");
        break;
    }

    // Stop measuring time and calculate the elapsed time
    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &end);
    long seconds = end.tv_sec - begin.tv_sec;
    long nanoseconds = end.tv_nsec - begin.tv_nsec;
    double elapsed = seconds + nanoseconds*1e-9;
    return elapsed;
}

// zwraca true jesli posortowana, false jesli nie
bool Array2D::isSorted(bool descOrder){
    for(int i = 0; i < arr2Dsize; i++){
        if(arr2D[i].isSorted(!descOrder) == false)
            return false;
    }
    return true;
}

void Array2D::display(){
    for(int i = 0; i < arr2Dsize; i++){
        cout << "Tablica nr " << i << ":" << endl;
        arr2D[i].display();
    }
}