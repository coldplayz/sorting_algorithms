#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
    int array[] = {19, 48, 99, 71, 13, 52, 96, 73, 86, 7};
	/* int array[] = {918, 1783, 1183, 707, 297, 1146, 658, 110, 1837, 505, 20, 853, 1759, 703, 1508, 926, 1107, 1863, 1776, 1424, 386, 1989, 788, 1755, 1407, 1868, 304, 9, 1027, 33, 1676, 408, 569, 1276, 744, 789, 199, 1287, 786, 1353, 1512, 1751, 1346, 1513, 340, 44, 787, 858, 54, 273, 1738, 1697, 29, 244, 85, 347, 902, 971, 1480, 1336, 325, 920, 1227, 785, 1551, 1087, 1474, 1949, 32, 1196, 1865, 539, 749, 1314, 1896, 1797, 324, 1073, 1001, 1954, 778, 99, 1600, 1373, 1405, 1413, 734, 896, 932, 1619, 1666, 1091, 1998, 356, 372, 1282, 877, 330, 1553, 1531, 517}; */
	/* int array[] = {3, 2}; */
    size_t n = sizeof(array) / sizeof(array[0]);

    print_array(array, n);
    printf("\n");
    merge_sort(array, n);
    printf("\n");
    print_array(array, n);
    return (0);
}
