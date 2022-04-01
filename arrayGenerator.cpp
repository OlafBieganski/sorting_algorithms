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
        if(arr != NULL) delete arr;

        // alokujemy tablice odp rozmiaru
        int* arr1 = new int[size];

        // wyliczamy ilosc posortowanych elem
        int sorted = size * (percOfSorted/100);
        srand((unsigned)time(0));
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
    if(arr != NULL) delete arr;
    // alokujemy tablice odp rozmiaru
    int* arr1 = new int[size];
    srand((unsigned)time(0));
    int sum = 0;
    for(int i = size; i > 0; i--){
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