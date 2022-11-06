#include "sort.h"
#include <stdio.h>

/**
 * insertion_sort_list - Sorts a doubly linked list of integers
 * in ascending order using insertion sort algorithm
 *
 * @list: Address of head of dllist
 * Return: Nothing
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *insertionPointer, *current;

	insertionPointer = *list;
	current = *list;
	current = current->next;
	while (current != NULL)
	{
		insertionPointer = *list;
		while (insertionPointer->next != current)
		{
			if (insertionPointer->n > current->n)
			{
				insertionPointer->prev->next = current;
				insertionPointer->next = current->next;
				insertionPointer->prev = current;
				current->next->prev = insertionPointer;
				current->prev = insertionPointer->prev;
				current->next = insertionPointer;
			}
			else
				insertionPointer = insertionPointer->next;
		}
		print_list(*list);
		current = current->next;
	}
}
