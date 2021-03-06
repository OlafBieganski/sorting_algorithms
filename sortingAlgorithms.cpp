#include <iostream>
#include "sortingAlgorithms.hh"

using namespace std;

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
    int pivot = arr[(start + end)/2];
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

void heapSort(int *arr, int size){

    for(int i = size/2-1; i >= 0; i--)
        heapify(arr, i, size);

    for(int i = size-1; i > 0; i--){
        swap(arr, 0, i);
        heapify(arr, 0, i);
    }
}

void heapify(int *arr, int i, int size){
    int top = i;
    int left = 2*i+1;
    int right = 2*i+2;

    if(left < size && arr[left] > arr[top])
        top = left;

    if(right < size && arr[right] > arr[top])
        top = right;

    if(top != i){
        swap(arr, i, top);
        heapify(arr, top, size);
    }
}

void InsertionSort(int* arr, int size) {

    int tmp, j;

    for(int i=1; i<size; i++)
    {
        //wstawienie elementu w odpowiednie miejsce
        tmp = arr[i]; //ten element będzie wstawiony w odpowiednie miejsce
        j = i-1;
        
        //przesuwanie elementów większych od pom
        while(j>=0 && arr[j]>tmp) 
        {
            arr[j+1] = arr[j]; //przesuwanie elementów
            --j;
        }
        arr[j+1] = tmp; //wstawienie pom w odpowiednie miejsce
    } 
}



void IntroSort(int* data, int count) {
	int partitionSize = partition(data, 0, count - 1);

	if (partitionSize < 16){
		InsertionSort(data, count);
	}
	else if (partitionSize >(2 * log(count))){
		heapSort(data, count);
	}
	else{
		quicksort(data, 0, count - 1);
	}
}