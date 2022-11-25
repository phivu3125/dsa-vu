#include "showAlgorithm.h"

char* nameOfAlgorithm(char algorithm[])
{
	char* s = new char[50];
	if (strcmp(algorithm, "heap-sort") == 0)
	{
		s = strcpy(s, "Heap Sort");
		s[10] = '\0';
	}
	else if (strcmp(algorithm, "merge-sort") == 0)
	{
		s = strcpy(s, "Merge Sort");
		s[11] = '\0';
	}
	else if (strcmp(algorithm, "radix-sort") == 0)
	{
		s = strcpy(s, "Radix Sort");
		s[11] = '\0';
	}
	else if (strcmp(algorithm, "counting-sort") == 0)
	{
		s = strcpy(s, "Counting Sort");
		s[14] = '\0';
	}
	else if (strcmp(algorithm, "shaker-sort") == 0)
	{
		s = strcpy(s, "Shaker Sort");
		s[12] = '\0';
	}
	else if (strcmp(algorithm, "quick-sort") == 0)
	{
		s = strcpy(s, "Quick Sort");
		s[11] = '\0';
	}
	else if (strcmp(algorithm, "shell-sort") == 0)
	{
		s = strcpy(s, "Shell Sort");
		s[11] = '\0';
	}
	else if (strcmp(algorithm, "insertion-sort") == 0)
	{
		s = strcpy(s, "Insertion Sort");
		s[15] = '\0';
	}
	else if (strcmp(algorithm, "flash-sort") == 0)
	{
		s = strcpy(s, "Flash Sort");
		s[11] = '\0';
	}
	else if (strcmp(algorithm, "selection-sort") == 0)
	{
		s = strcpy(s, "Selection Sort");
		s[15] = '\0';
	}
	else if (strcmp(algorithm, "bubble-sort") == 0)
	{
		s = strcpy(s, "Bubble Sort");
		s[12] = '\0';
	}
	else
	{
		s = strcpy(s, "Please check 2th parameter input.");
		s[49] = '\0';
	}
	return s;
}
void runAlgorithm(char algorithm[], double& runtime, long long& comp, int*& a, int n)
{
	clock_t start, end;
	if (strcmp(algorithm, "heap-sort") == 0)
	{
		/*int* b = new int[n];
		copy(a, a + n, b);
		start = clock();
		HeapSort(a, n);
		end = clock();
		runtime = (double)(end - start) / (CLOCKS_PER_SEC);
		countHeapSort(b, n, comp);
		delete[]b;*/
	}
	else if (strcmp(algorithm, "merge-sort") == 0)
	{
		/*int* b = new int[n];
		copy(a, a + n, b);
		start = clock();
		mergeSort(a, 0, n - 1);
		end = clock();
		runtime = (double)(end - start) / (CLOCKS_PER_SEC);
		countMergeSort(b, 0, n - 1, comp);
		delete[]b;*/
	}
	else if (strcmp(algorithm, "radix-sort") == 0)
	{
		/*int* b = new int[n];
		copy(a, a + n, b);
		start = clock();
		radixSort(a, n, log10(getMax(a, n)) + 1);
		end = clock();
		runtime = (double)(end - start) / (CLOCKS_PER_SEC);
		countRadixSort(b, n, log10(getMax(a, n)) + 1, comp);
		delete[]b;*/
	}
	else if (strcmp(algorithm, "counting-sort") == 0)
	{
		/*int* b = new int[n];
		copy(a, a + n, b);
		start = clock();
		CountingSort(a, n, getMin(a, n), getMax(a, n));
		end = clock();
		runtime = (double)(end - start) / (CLOCKS_PER_SEC / 1000);
		countCountingSort(b, n, countGetMin(b, n, comp), countGetMax(b, n, comp), comp);
		delete[]b;*/
	}
	else if (strcmp(algorithm, "shaker-sort") == 0)
	{
		int* b = new int[n];
		copy(a, a + n, b);
		start = clock();
		shakerSort(a, n);
		end = clock();
		runtime = (double)(end - start) / (CLOCKS_PER_SEC);
		countShakerSort(b, n, comp);
		delete[]b;
	}
	else if (strcmp(algorithm, "quick-sort") == 0)
	{
		/*int* b = new int[n];
		copy(a, a + n, b);
		start = clock();
		quickSort(a, 0, n - 1);
		end = clock();
		runtime = (double)(end - start) / (CLOCKS_PER_SEC);
		countQuickSort(b, 0, n - 1, comp);
		delete[]b;*/
	}
	else if (strcmp(algorithm, "shell-sort") == 0)
	{
		int* b = new int[n];
		copy(a, a + n, b);
		start = clock();
		shellSort(a, n);
		end = clock();
		runtime = (double)(end - start) / (CLOCKS_PER_SEC);
		countShellSort(b, n, comp);
		delete[]b;
	}
	else if (strcmp(algorithm, "insertion-sort") == 0)
	{
		int* b = new int[n];
		copy(a, a + n, b);
		start = clock();
		InsertionSort(a, n);
		end = clock();
		runtime = (double)(end - start) / (CLOCKS_PER_SEC);
		countInsertionSort(b, n, comp);
		delete[]b;
	}
	else if (strcmp(algorithm, "flash-sort") == 0)
	{
		int* b = new int[n];
		copy(a, a + n, b);
		start = clock();
		flashSort(a, n);
		end = clock();
		runtime = (double)(end - start) / (CLOCKS_PER_SEC);
		countFlashSort(b, n, comp);
		delete[]b;
	}
	else if (strcmp(algorithm, "selection-sort") == 0)
	{
		int* b = new int[n];
		copy(a, a + n, b);
		start = clock();
		SelectionSort(a, n);
		end = clock();
		runtime = (double)(end - start) / (CLOCKS_PER_SEC);
		countSelectionSort(b, n, comp);
		delete[]b;
	}
	else if (strcmp(algorithm, "bubble-sort") == 0)
	{
		int* b = new int[n];
		copy(a, a + n, b);
		start = clock();
		BubbleSort(a, n);
		end = clock();
		runtime = (double)(end - start) / (CLOCKS_PER_SEC);
		countBubbleSort(b, n, comp);
		delete[]b;
	}
	else
	{
		cout << "Please check algorithm name agrument\n";
	}
}