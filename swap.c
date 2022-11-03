#include "sort.h"

/*
 * swap - swaps to integers
 * @: First integer
 * @: Second integer
 * Return: Nothing
 */
void swap(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}
