#include "command1.h"

void outputOrder1(char outPut[], double runtime, long long comp)
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

bool readingFile(int*& a, int &n, char fileInput[], char outPut[])
{
	FILE* f;

	f = fopen(fileInput, "rt");

	if (f == NULL)
	{
		cout << "File not exist\n";
		return 0;
	}
	else
	{
		cout << "Input file: " << fileInput << endl;
		fscanf(f, "%d\n", &n);

		a = new int[n];

		for (int i = 0; i < n; i++)
		{
			fscanf(f, "%d ", &a[i]);
		}
		fclose(f);
		cout << "Input size: " << n << endl;
	}
	return 1;
}


void command1(char algorithm[], char fileInput[], char outPut[])
{
	int* a;
	int n = 0;
	cout << "Algorithm: " << nameOfAlgorithm(algorithm) << endl;
	if (readingFile(a, n, fileInput, outPut) == 1)
	{
		double runtime;
		long long comp = 0;
		runAlgorithm(algorithm, runtime, comp, a, n);
		outputOrder1(outPut, runtime, comp);
		writingFile("output.txt", a, n);
	}
	delete[]a;
}