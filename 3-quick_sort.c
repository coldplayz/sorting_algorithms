#include "sort.h"
#include <stdio.h>


/**
 * swap - Swaps two integers
 * @a: First integer
 * @b: Second integer
 * Return: Nothing
 */
void swap(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * partition - Divides an array into two sub arrays at
 * pivot point such numbers to the left of pivot are
 * <= pivot while those to the right are > pivot
 *
 * @array: Array to be partitioned
 * @lo: Lower boundary of array
 * @hi: Upper boundary of array
 * Return: Index to the pivot value
 */
int partition(int *array, int lo, int hi)
{
	int i, j, pivot, size;

	size = hi + 1;

	/*Applying the lamuto technique of setting*/
	/*the upper bound value as pivot*/
	pivot = array[hi];

	/*Keeps boundary of last index <= pivot*/
	i = lo;

	for (j = lo; j < hi; j++)
	{
		if (array[j] <= pivot)
		{
			swap(&array[i], &array[j]);
			print_array(array, size);
			i++;
		}
	}
	swap(&array[i], &array[hi]);
	print_array(array, size);
	return (i);
}

/**
 * quick_sort_ - Sorts an array using quick sort algorithm
 * this version of quick sort takes 3 arguments
 *
 * @array: Array to be sorted
 * @lo: Lower boundary of array
 * @hi: Upper boundary of array
 * Return: Nothing
 */
void quick_sort_(int *array, int lo, int hi)
{
	int pivot;

	if (lo < hi)
	{
		pivot = partition(array, lo, hi);
		quick_sort_(array, lo, pivot - 1);
		quick_sort_(array, pivot + 1, hi);
	}
}
/**
 * quick_sort - Sorts an array using quick sort algorithm
 * this version of quick sorted uses 2 arguments
 *
 * @array: Array to be sorted
 * @size: Size of the array
 * Return: Nothing
 */
void quick_sort(int *array, size_t size)
{
	quick_sort_(array, 0, size - 1);
}
