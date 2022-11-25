
#include "Header.h"

// 1 bubll ============================
void BubbleSort(int a[], int n);
void countBubbleSort(int arr[], int n, long long& countCmp);



// 2 counting ============================
void CountingSort();//

// 3 flash ============================
void flashSort(int a[], int n);
void countFlashSort(int a[], int n, long long& c);

// 4 heap ============================
void heapify(int a[], int n, int i);
void HeapSort(int a[], int n);
void countHeapSort(); //

// 5 insert ============================
void InsertionSort(int a[], int n);
void countInsertionSort(int a[], int n, long long& c);


// 6 merge ============================
void MergeSort();

// 7 quick ============================
int partition(int a[], int low, int high);
void QuickSort(int a[], int low, int high);

// 8 radix ============================
int getMax(int a[], int n);
void countSort(int a[], int n, int exp);
void RadixSort(int a[], int n);
// count radix sort


// 9 selection ============================
int findIndexofLargest(int a[], int size);
int countFindIndexofLargest(int a[], int size, long long& countCmp);
void SelectionSort(int a[], int n);
void countSelectionSort(int a[], int n, long long& countCmp);

// 10 shaker ============================
void shakerSort(int a[], int n);
void countShakerSort(int a[], int n, long long& c);

// 11 shell ============================
void shellSort(int a[], int n);
void countShellSort(int a[], int n, long long& c);

// print 
void print_array(int a[], int n);
