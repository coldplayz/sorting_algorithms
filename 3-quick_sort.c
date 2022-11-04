#include "sort.h"


void lomuto_sort(int *array, size_t size, int *low_a, int *high_a);


/**
 * quick_sort - implements Quick Sort using the Lamuto partitioning scheme.
 * @array: the array to sort.
 * @size: the number of integers in @array.
 */
void quick_sort(int *array, size_t size)
{
	int *low_a, *high_a;

	if (size < 2)
	{
		return;
	}

	low_a = array + 0; /* start of array */
	high_a = array + (size - 1); /* end of array */

	lomuto_sort(array, size, low_a, high_a);
}




/**
 * lomuto_sort - implements Lamuto partitioning and sort.
 * @array: array of integers being sorted.
 * @size: size of @array.
 * @low_a: start address of the (sub-)array to partition and sort.
 * @high_a: last address of the (sub-)array to partition and sort.
 */
void lomuto_sort(int *array, size_t size, int *low_a, int *high_a)
{
	int pivot_v, cmp_v, *pivot_a, *cmp_a, tmp_v;

	if (low_a == high_a)
		return; /* only one address in sub-array */
	pivot_a = high_a;
	pivot_v = *pivot_a;
	cmp_a = low_a;
	cmp_v = *cmp_a;

	for (; cmp_a != pivot_a;)
	{/* Set partitioning point */
		if (pivot_v < cmp_v)
		{/* First swap of pivot_a value with left-adjacent value, which may == cmp */
			tmp_v = *(pivot_a - 1);
			*(pivot_a - 1) = pivot_v;
			*pivot_a = tmp_v;
			pivot_a = pivot_a - 1; /* update pivot address */
			print_array(array, size);
			if (pivot_a == cmp_a)
				break; /* partition point reached; cmp_a was left-adjacent to pivot_a */
			/* Safe to perform second swap */
			tmp_v = cmp_v;
			*(cmp_a) = *(pivot_a + 1);
			cmp_v = *cmp_a;
			*(pivot_a + 1) = tmp_v;
			print_array(array, size);
		}
		else
		{/* Move comparison address forward */
			cmp_a = cmp_a + 1;
			cmp_v = *cmp_a;
		}
	}
	/* Partition and recurse */
	if (pivot_a != low_a)
		lomuto_sort(array, size, low_a, pivot_a - 1); /* >= one item on the left */
	if (pivot_a != high_a)
		lomuto_sort(array, size, pivot_a + 1, high_a); /* >= one item on the right */
}
