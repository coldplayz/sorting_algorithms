#include "sort.h"

/*
 * bubble_sort - Sorts an array in ascending order
 * using the bubble sort algorithm
 * 
 * @array: Array to be sorted
 * @size: size of the array
 * Return: Nothing
 */
void bubble_sort(int *array, size_t size)
{
    size_t i, j;

    for (i = 0; i < size - 1; i++)
    {
        for (j = 0; j < size; j++)
        {
            if (array[j] > array[j + 1])
            {
                swap(&array[j], &array[j + 1]);
                print_array(array, size);
            }
        }
    }
}