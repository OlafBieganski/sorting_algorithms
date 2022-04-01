#include <iostream>
#include "sortingAlgorithms.hh"

using namespace std;

void mergeSort(int *arr, int low, int high);
void merge(int *arr, int low, int mid, int high);

// funkcja dzieli tablice na dwie części, następnie scala
void mergeSort(int *arr, int low, int high){
    int mid;
    //sprawdzamy czy jest co dzielic
    if(low < high){
        mid = (low + high)/2;
        mergeSort(arr, low, mid);
        mergeSort(arr, mid+1, high);

        merge(arr, low, mid, high);
    }
}

// funkcja scala dwie polowki w jedna posortowana calosc
void merge(int *arr, int low, int mid, int high){
    // odcinki tablic low/mid mid+1/high sa juz posortowane
    int i = low;
    int k = 0;
    int j = mid + 1;
    int temp[high-low+1];

    while(i <= mid && j <= high){
        if(arr[i] < arr[j]){
            temp[k] = arr[i];
            k++;
            i++;
        }
        else{
            temp[k] = arr[j];
            k++;
            j++;
        }
    }

    while(i <= mid){
        temp[k] = arr[i];
        k++;
        i++;
    }

    while(j <= high){
        temp[k] = arr[j];
        k++;
        j++;
    }

    for(i = low; i <= high; i++){
        arr[i] = temp[i-low];
    }
}

// funkcja zamienia miejscami w tablicy elementy o indeksie a i b
void swap(int *arr, int a, int b){
    int tmp = arr[a];
    arr[a] = arr[b];
    arr[b] = tmp;
}

int partition(int arr[], int start, int end){
    // ustawaimy pivot na pierwszy element 
    int pivot = arr[start];
    // indeksy na start i koniec
    int i = start, j = end;

    while(1){
        while(arr[j] > pivot) j--;
        while(arr[i] < pivot) i++;
        if(i < j){
            swap(arr,i,j);
            i++;
            j--;
        }
        else{
            return j;
        }
    }
}

void quicksort(int arr[], int start, int end){
    int j;
    if(start < end){
        j = partition(arr, start, end);
        quicksort(arr, start, j);
        quicksort(arr, j+1, end);
    }
}