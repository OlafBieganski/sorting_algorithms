#ifndef SORTINGALGORITHMS
#define SORTINGALGORITHMS
#include <cmath>

void mergeSort(int *arr, int low, int high);
void merge(int *arr, int low, int mid, int high);

int partition(int arr[], int start, int end);
void quicksort(int arr[], int start, int end);

void heapSort(int *arr, int size);
void heapify(int *arr, int i, int size);

void introsort(int *data, int size);
void sort(int *arr, int start, int end);


#endif