#include "sort.h"


//1     buble=========================================

void BubbleSort(int a[], int n)
{
	int i, j;
	for (i = 0; i < n - 1; i++)
		for (j = 0; j < n - i - 1; j++)
			if (a[j] > a[j + 1])
				swap(a[j], a[j + 1]);
}
void countBubbleSort(int arr[], int n, long long &countCmp)
{
	int i, j;
	for (i = 0; ++countCmp, i < n - 1; i++)
		for (j = 0; ++countCmp, j < n - i - 1; j++)
			if (++countCmp && arr[j] > arr[j + 1])
				swap(arr[j], arr[j + 1]);
}

//2     counting =====================================
void CountingSort()
{
	cout<<"notfound";
}
//3     flash ========================================
void flashSort(int a[], int n) 
{
	int minVal = a[0], maxIdx = 0;
	int buckets = int(0.45 * n);
	int* l = new int[buckets];
	for (size_t i = 0; i < buckets; i++)
	{
		l[i] = 0;
	}
	for (size_t i = 1; i < n; i++)
	{
		if (a[i] < minVal) minVal = a[i];
		if (a[i] > a[maxIdx]) maxIdx = i;
	}
	if (a[maxIdx] == minVal) {
		delete[]l;
		return;
	}
	double c1 = (double)(buckets - 1) / (a[maxIdx] - minVal);
	for (size_t i = 0; i < n; i++)
	{
		int bucketIdx = int(c1 * (a[i] - minVal));
		l[bucketIdx]++;
	}
	for (size_t i = 1; i < buckets; i++)
	{
		l[i] += l[i - 1];
	}
	swap(a[maxIdx], a[0]);
	int nmove = 0;
	int j = 0;
	int k = buckets - 1;
	int flash;
	while (nmove < n - 1)
	{
		while (j > l[k] - 1)
		{
			j++;
			k = int(c1 * (a[j] - minVal));
		}
		flash = a[j];
		if (k < 0) break;
		while (j != l[k])
		{
			k = int(c1 * (flash - minVal));
			--l[k];
			swap(flash, a[l[k]]);
			++nmove;
		}
	}
	delete[]l;
	InsertionSort(a, n);
}

void countFlashSort(int a[], int n, long long& c) 
{
	int minVal = a[0], maxIdx = 0;
	int buckets = int(0.45 * n);
	int* l = new int[buckets];
	for (size_t i = 0; ++c, i < buckets; i++)
	{
		l[i] = 0;
	}
	for (size_t i = 1; ++c, i < n; i++)
	{
		if (++c && a[i] < minVal) minVal = a[i];
		if (++c && a[i] > a[maxIdx]) maxIdx = i;
	}
	if (++c && a[maxIdx] == minVal) {
		delete[]l;
		return;
	}
	double c1 = (double)(buckets - 1) / (a[maxIdx] - minVal);
	for (size_t i = 0; ++c, i < n; i++)
	{
		int bucketIdx = int(c1 * (a[i] - minVal));
		l[bucketIdx]++;
	}
	for (size_t i = 1; ++c, i < buckets; i++)
	{
		l[i] += l[i - 1];
	}
	swap(a[maxIdx], a[0]);
	int nmove = 0;
	int j = 0;
	int k = buckets - 1;
	int flash;
	while (++c && nmove < n - 1)
	{
		while (++c && j > l[k] - 1)
		{
			j++;
			k = int(c1 * (a[j] - minVal));
		}
		flash = a[j];
		if (++c && k < 0) break;
		while (++c && j != l[k])
		{
			k = int(c1 * (flash - minVal));
			--l[k];
			swap(flash, a[l[k]]);
			++nmove;
		}
	}
	delete[]l;
	countInsertionSort(a, n, c);
}

//4     heap =========================================
void heapify(int a[], int n, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < n && a[left] > a[largest])
        largest = left;
    if (right < n && a[right] > a[largest])
        largest = right;
    if (largest != i) {
        swap(a[i], a[largest]);
        heapify(a, n, largest);
    }
}
void HeapSort(int a[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(a, n, i);
    for (int i = n - 1; i >= 0; i--) {
        swap(a[0], a[i]);
        heapify(a, i, 0);
    }
}
void countHeapSort(){
	cout<<"nofound";
}
//5     insert =======================================
void InsertionSort(int a[], int n)
{
	for (int i = 1; i < n; i++)
	{
		int k = i - 1;
		int key = a[i];
		while (a[k] > key && k >= 0)
		{
			a[k + 1] = a[k];
			k--;
		}
		a[k + 1] = key;
	}
}

void countInsertionSort(int a[], int n, long long& c)
{
	for (int i = 1; ++c, i < n; i++)
	{
		int k = i - 1;
		int key = a[i];
		while ((++c && a[k] > key) && (++c && k >= 0))
		{
			a[k + 1] = a[k];
			k--;
		}
		a[k + 1] = key;
	}
}
//5     merge ========================================
void MergeSort()
{
	cout<<"notfound";
}
//7     quick ========================================
int partition(int a[], int low, int high)
{
    int pivot = a[high]; // pivot
    int i = (low- 1); // Index of smaller element and indicates
  
    for (int j = low; j <= high - 1; j++) {
        // If current element is smaller than the pivot
        if (a[j] < pivot) {
            i++; // increment index of smaller element
            swap(a[i], a[j]);
        }
    }
    swap(a[i + 1], a[high]);
    return (i + 1);
}
  
void QuickSort(int a[], int low, int high)
{
    if (low < high) {
     
        int pi = partition(a, low, high);
        QuickSort(a, low, pi - 1);
        QuickSort(a, pi + 1, high);
    }
}



//8     radix ========================================
int getMax(int a[], int n)
{
	int mx = a[0];
	for (int i = 1; i < n; i++)
		if (a[i] > mx)
			mx = a[i];
	return mx;
}

void countSort(int a[], int n, int exp)
{
	int *output = new int [n]; // output aay
	int i, count[10] = { 0 };

	for (i = 0; i < n; i++)
		count[(a[i] / exp) % 10]++;
	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];

	for (i = n - 1; i >= 0; i--) {
		output[count[(a[i] / exp) % 10] - 1] = a[i];
		count[(a[i] / exp) % 10]--;
	}
	for (i = 0; i < n; i++)
		a[i] = output[i];
}
void RadixSort(int a[], int n)
{
	int m = getMax(a, n);

	for (int exp = 1; m / exp > 0; exp *= 10)
		countSort(a, n, exp);
}
//9     selection ====================================
int findIndexofLargest(int a[], int size)
{
	int largest = 0;
	for (int i = 0; i <= size; i++)
	{
		if (a[i] > a[largest])
		{
			largest = i;
		}
	}
	return largest;
}

int countFindIndexofLargest(int a[], int size, long long&countCmp)
{
	int largest = 0;
	for (int i = 0;++countCmp, i <= size; i++)
	{
		if (++countCmp && a[i] > a[largest])
		{
			largest = i;
		}
	}
	return largest;
}

void SelectionSort(int a[], int n)
{
    int i, j, min_idx;
 
    for (i = 0; i < n-1; i++)
    {
        min_idx = i;
        for (j = i+1; j < n; j++)
        if (a[j] < a[min_idx])
            min_idx = j;

        if(min_idx!=i)
            swap(a[min_idx], a[i]);
    }
}
void countSelectionSort(int a[], int n, long long&countCmp)
{
	for (int i = n - 1; ++countCmp, i > 0; i--)
	{
		int largest = findIndexofLargest(a, i);
		swap(a[largest], a[i]);
	}
}
//10    sharker ======================================

void shakerSort(int a[], int n)
{
	int l = 0, r = n - 1, k = 0;
	bool sw = 0;
	for (size_t i = l; i <= r; i++)
	{
		sw = 0;
		for (size_t j = l; j < r; j++)
		{
			if (a[j] > a[j + 1])
			{
				sw = 1;
				swap(a[j], a[j + 1]);
				k = j;
			}
		}
		if (!sw) return;
		r = k;
		sw = 0;
		for (size_t j = r; j > l; j--)
		{
			if (a[j] < a[j - 1])
			{
				sw = 1;
				swap(a[j], a[j - 1]);
				k = j;
			}
		}
		if (!sw) return;
		l = k;
	}
}
void countShakerSort(int a[], int n, long long& c)
{
	int l = 0, r = n - 1, k = 0;
	bool sw = 0;
	for (size_t i = l; ++c, i <= r; i++)
	{
		sw = 0;
		for (size_t j = l; ++c, j < r; j++)
		{
			if (++c && a[j] > a[j + 1])
			{
				sw = 1;
				swap(a[j], a[j + 1]);
				k = j;
			}
		}
		if (++c && !sw) return;
		r = k;
		sw = 0;
		for (size_t j = r; ++c, j > l; j--)
		{
			if (++c && a[j] < a[j - 1])
			{
				sw = 1;
				swap(a[j], a[j - 1]);
				k = j;
			}
		}
		if (++c && !sw) return;
		l = k;
	}
}

//11    shell ========================================
void shellSort(int a[], int n)
{
	for (size_t gap = n / 2; gap > 0; gap /= 2)
	{
		for (size_t i = gap; i < n; i++)
		{
			int temp = a[i];
			int j = i;
			for (; j >= gap && a[j - gap] > temp; j -= gap)
			{
				a[j] = a[j - gap];
			}
			a[j] = temp;
		}

	}
}

void countShellSort(int a[], int n, long long& c)
{
	for (size_t gap = n / 2; ++c, gap > 0; gap /= 2)
	{
		for (size_t i = gap; ++c, i < n; i++)
		{
			int temp = a[i];
			int j = i;
			for (; c += 2, j >= gap && a[j - gap] > temp; j -= gap)
			{
				a[j] = a[j - gap];
			}
			a[j] = temp;
		}
	}
}

//print aay
void print_array( int a[], int n){
    for( int i=0;i<n; i++){
        cout<<a[i]<<" ";
    }
}
