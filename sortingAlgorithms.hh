#ifndef SORTINGALGORITHMS
#define SORTINGALGORITHMS

void mergeSort(int *arr, int low, int high);
void merge(int *arr, int low, int mid, int high);

int partition(int arr[], int start, int end);
void quicksort(int arr[], int start, int end);

#endif