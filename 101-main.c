#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * create_listint - Creates a doubly linked list from an array of integers
 *
 * @array: Array to convert to a doubly linked list
 * @size: Size of the array
 *
 * Return: Pointer to the first element of the created list. NULL on failure
 */
listint_t *create_listint(const int *array, size_t size)
{
    listint_t *list;
    listint_t *node;
    int *tmp;

    list = NULL;
    while (size--)
    {
        node = malloc(sizeof(*node));
        if (!node)
            return (NULL);
        tmp = (int *)&node->n;
        *tmp = array[size];
        node->next = list;
        node->prev = NULL;
        list = node;
        if (list->next)
            list->next->prev = list;
    }
    return (list);
}

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
    listint_t *list;
    /* int array[] = {19, 48, 99, 71, 13, 52, 96, 73, 86, 7}; */
    int array[] = {918, 1783, 1183, 707, 297, 1146, 658, 110, 1837, 505, 20, 853, 1759, 703, 1508, 926, 1107, 1863, 1776, 1424, 386, 1989, 788, 1755, 1407, 1868, 304, 9, 1027, 33, 1676, 408, 569, 1276, 744, 789, 199, 1287, 786, 1353, 1512, 1751, 1346, 1513, 340, 44, 787, 858, 54, 273, 1738, 1697, 29, 244, 85, 347, 902, 971, 1480, 1336, 325, 920, 1227, 785, 1551, 1087, 1474, 1949, 32, 1196, 1865, 539, 749, 1314, 1896, 1797, 324, 1073, 1001, 1954, 778, 99, 1600, 1373, 1405, 1413, 734, 896, 932, 1619, 1666, 1091, 1998, 356, 372, 1282, 877, 330, 1553, 1531, 517};
    size_t n = sizeof(array) / sizeof(array[0]);

    list = create_listint(array, n);
    if (!list)
        return (1);
    print_list(list);
    printf("\n");
    cocktail_sort_list(&list);
    printf("\n");
    print_list(list);
    return (0);
}
