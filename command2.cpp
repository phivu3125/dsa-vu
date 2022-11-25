#include "command2.h"


void outputOrder2(char outPut[], double runtime, long long comp)
{
	if (strcmp(outPut, "-time") == 0)// check output
	{
		cout << "-------------------------------\n";
		cout << "Running time: " << runtime << endl;
	}
	else if (strcmp(outPut, "-comp") == 0)
	{
		cout << "-------------------------------\n";
		cout << "Comparisions: " << comp << endl;
	}
	else if (strcmp(outPut, "-both") == 0)
	{
		cout << "-------------------------------\n";
		cout << "Running time: " << runtime << endl;
		cout << "Comparisions: " << comp << endl;
	}
	else
	{
		cout << "Please check output 5th parameter input.\n";
	}
}

void checkInputOrder2(int*& a, int n, char inputOrder[], char outPut[])
{
	if (strcmp(inputOrder, "-rand") == 0)
	{
		GenerateData(a, n, 0);
		writingFile("input.txt", a, n);
		cout << "Input Order: randomized data\n";
	}
	else if (strcmp(inputOrder, "-sorted") == 0)
	{
		GenerateData(a, n, 1);
		writingFile("input.txt", a, n);
		cout << "Input Order: sorted data\n";
	}
	else if (strcmp(inputOrder, "-rev") == 0)
	{
		GenerateData(a, n, 2);
		writingFile("input.txt", a, n);
		cout << "Input Order:  reverse sorted data\n";
	}
	else if (strcmp(inputOrder, "-nsorted") == 0)
	{
		GenerateData(a, n, 3);
		writingFile("input.txt", a, n);
		cout << "Input Order: nearly sorted data\n";
	}
	else
	{
		cout << "Please check 4th parameter input.\n";
	}
}

bool checkInputSize2(int *&a, int & n,char inputSize[], char inputOrder[], char outPut[])
{
	if (checkStringNumber(inputSize) == 1)
	{
		n = convertStringToNumber(inputSize);
		a = new int[n];
		cout << "Input Size: " << n << endl;
		checkInputOrder2(a, n, inputOrder, outPut);
		return 1;
	}
	return 0;
}

void command2(char algorithm[], char inputSize[], char inputOrder[], char outPut[])
{
	int* a;
	int n = 0;
	cout << "Algorithm: " << nameOfAlgorithm(algorithm) << endl;
	if (checkInputSize2(a, n, inputSize, inputOrder, outPut) == 1)
	{
		double runtime;
		long long comp = 0;
		runAlgorithm(algorithm, runtime, comp, a, n);
		outputOrder2(outPut, runtime, comp);
		writingFile("output.txt", a, n);
	}
	delete[]a;
}