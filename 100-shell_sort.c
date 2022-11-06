#include "sort.h"

void sort_stream(
		int *start_a, int *curr_stream, int *array, size_t size, int gap);

/**
 * shell_sort - implements Shell Sort algorithm with the Knuth sequence of gaps
 * @array: the array of integers to sort.
 * @size: number of items in @array.
 */
void shell_sort(int *array, size_t size)
{
	int i, k, *start_a, gaps[] = {4, 1, 0};
	size_t j;

	if (size < 2 || !array)
	{
		return;
	}

	/* Iterate through array of gaps */
	for (i = 0; gaps[i]; i++)
	{
		/* Iterate for as many sub-arrays as there would be */
		for (k = 0; k < gaps[i]; k++)
		{
			/* Produce and sort the stream */
			for (j = 0; j < size; j = j + gaps[i])
			{
				if (j == 0)
				{
					start_a = array + k;
					j = k; /* reset to the index of the first element of the current array */
					continue; /* stream-sorting to start from next stream index */
				}
				sort_stream(start_a, array + j, array, size, gaps[i]);
			}
		}
		print_array(array, size);
	}
}






/**
 * sort_stream - implements insertion sort for a stream of inputs.
 * @start_a: address of first element of stream's array.
 * @curr_stream: address of current array item being streamed in.
 * @array: array to sort.
 * @size: size of @array.
 * @gap: integer representing the
 * current gap between elements in a streaming array.
 */
void sort_stream(
		int *start_a, int *curr_stream, int *array, size_t size, int gap)
{
	int tmp_v, *prev_stream;

	(void)size;
	(void)array;
	prev_stream = curr_stream - gap; /* initialize prev_stream */
	for (; curr_stream != start_a;)
	{
		if (*curr_stream > *prev_stream)
		{
			return;
		}
		/* Swap, pushing values forward */
		tmp_v = *curr_stream;
		*curr_stream = *prev_stream;
		*prev_stream = tmp_v;
		/* Update addresses */
		curr_stream = curr_stream - gap;
		if (curr_stream == start_a)
		{
			/* Start of array; return to avoid assigning illegal address to prev_str */
			return;
		}
		prev_stream = prev_stream - gap;
	}
}
