#include "number.h"

int convertStringToNumber(char s[])
{
	int n = 0;
	for (int i = strlen(s) - 1; i >= 0; i--)
	{
		n += (int)(s[i] - '0') * pow(10, strlen(s) - 1 - i);
	}
	return n;
}

bool checkStringNumber(char s[])
{
	for (int i = 0; i < strlen(s); i++)
	{
		if (s[i] - '0' > 9 || s[i] - '0' < 0)
		{
			return 0;
		}
	}
	return 1;
}