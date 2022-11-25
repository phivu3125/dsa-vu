#include "Header.h"
int main(int argc, char* argv[])
{
	int* a;
	if (strcmp(argv[1], "-a") == 0)
	{
		cout << "ALGORITHM MODE\n";
		if (strcmp(argv[3] + strlen(argv[3]) - 4, ".txt") == 0)
		{
			command1(argv[2], argv[3], argv[4]);
		}
		else if (argc == 6)
		{
			command2(argv[2], argv[3], argv[4], argv[5]);
		}
	}
	return 0;
}
