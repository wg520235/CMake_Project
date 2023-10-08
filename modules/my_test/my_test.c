#include <stdio.h>


int a_add_b(int a, int b, int *c)
{
	*c = a + b;
	return *c;
}

int a_minus_b(int a, int b, int *c)
{
	*c = a - b;
	return *c;
}

