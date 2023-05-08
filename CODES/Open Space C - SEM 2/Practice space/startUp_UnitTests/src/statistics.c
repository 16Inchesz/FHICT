#include "statistics.h"

int find_maximum(int a, int b)
{
	uint8_t max;
	if (a>b) 
	{
		max=a;
	}
	else
	{
		max=b;
	}
	return max;
}
