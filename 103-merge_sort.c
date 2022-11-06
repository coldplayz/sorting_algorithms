#include "sort.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * merge_sort_ - function that recursively divides the array into
 * sorted sub-arrays and merges the sorted sub-arrays
 * @array: Array to be sorted
 * @lb: lower boundary of array
 * @ub: Upper boundary of array
 * Return: void
 */
void merge_sort_(int *array, int lb, int ub)
{
    int mid;

    if (lb < ub) /*Exit case: Array contains more than one element*/
    {
        mid = (lb + ub) / 2;
        merge_sort_(array, lb, mid);
        merge_sort_(array, mid + 1, ub);
        merge(array, lb, mid, ub);
    }
}

/**
 * merge - Merges the sorted sub-array
 * @array: Main array
 * @lb: Lower boundary of array
 * @mid: Mid index of array
 * @ub: Upper boundary of array
 * Return: void
 */
void merge(int *array, int lb, int mid, int ub)
{
	int *sorted_array, i = lb, j = mid + 1, k = lb;

	sorted_array = malloc(sizeof(int) * (ub + 1));
	if (sorted_array == NULL)
		return;
	printf("Merging...\n");
	printf("[left]: ");
	print_array(array, mid + 1);
	/*printf("[right]: ");*/
    while (i <= mid && j <= ub)
    {
        if (array[i] < array[j])
        {
            sorted_array[k] = array[i];
            i++;
        }
        else
        {
            sorted_array[k] = array[j];
            j++;
        }
        k++;
    }
    if (i > mid)
    {
        while (j <= ub)
        {
            sorted_array[k] = array[j];
            j++;
            k++;
        }
    }
    else
    {
        while ( i <= mid)
        {
            sorted_array[k] = array[i];
            i++;
            k++;
        }
    }
    for (k = lb; k <= ub; k++)
		array[k] = sorted_array[k];
	free(sorted_array);
}

/**
 * merge_sort - same as merge_sort_ but takes only two arguments
 *
 * @array: Array to be sorted
 * @size: Size of the array
 * @Return: Nothing
 */
void merge_sort(int *array, size_t size)
{
	int lb = 0, ub = size - 1;

	merge_sort_(array, lb, ub);
}
