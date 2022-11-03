#include "sort.h"


/**
 * selection_sort - implements the selection sort algorithm.
 * @array: array to sort.
 * @size: size of the @array.
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j;
	int tmp, min, min_idx;

	if (size < 2)
	{
		return;
	}

	for (i = 0; i < size - 1; i++)
	{
		min = array[i];
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < min)
			{
				/* Update minimum value, and its index in array */
				min = array[j];
				min_idx = j;
			}
		}
		/* Swap if current min is not same as first min */
		if (min != array[i])
		{
			tmp = array[min_idx];
			array[min_idx] = array[i];
			array[i] = tmp;
			print_array(array, size);
		}
	}
}
