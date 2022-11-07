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
	/* int array[] = {114, 183, 44, 106, 166, 188, 164, 174, 118, 34, 8, 63, 46, 18, 71, 121, 113, 145, 115, 75, 111, 146, 98, 37, 29, 119, 125, 24, 41, 1, 56, 173, 73, 156, 35, 120, 181, 123, 40, 194, 152, 77, 70, 117, 198, 50, 5, 3, 4, 94, 1157, 597, 1895, 1247, 201, 142, 1899, 910, 1029, 515, 810, 1173, 101, 191, 92, 62, 802, 1986, 1037, 1076, 503, 858, 873, 452, 508, 1668, 22, 1078, 637, 1457, 1725, 145, 716, 346, 928, 1332, 1180, 542, 588, 1903, 464, 1006, 697, 1932, 21, 436, 453, 1309, 40, 684, 818, 1268, 1378, 857, 607, 13, 1261, 1942, 85, 1245, 1082, 1498, 1961, 1046, 674, 1805, 216, 646, 1113, 1302, 1460, 1575, 429, 1653, 1028, 868, 1673, 729, 1208, 833, 675, 761, 1214, 1271, 1737, 1499, 1095, 1427, 621, 1449, 1235, 80, 1732, 1767, 412, 1589, 771, 282, 1163, 864, 603, 1312, 711, 791, 95, 333, 427, 1600}; */
    size_t n = sizeof(array) / sizeof(array[0]);

    print_array(array, n);
    printf("\n");
    heap_sort(array, n);
    printf("\n");
    print_array(array, n);
    return (0);
}
