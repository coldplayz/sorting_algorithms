#include "sort.h"
#include <stdio.h>

/*
 * insertion_sort_list - Sorts a doubly linked list of integers
 * in ascending order using insertion sort algorithm
 * 
 * @list: Address of head of dllist
 * Return: Nothing
 */
void insertion_sort_list(listint_t **list)
{
    listint_t *insertionPointer, *current, *tmp;

    insertionPointer = *list;
    current = *list;
    current = current->next;
    while (current!= NULL)
    {
        insertionPointer = *list;
        while(insertionPointer->next != current)
        {
            if (insertionPointer->n > current->n)
            {
                tmp = current->next;
                current->next = insertionPointer;
                current->next->prev = insertionPointer;
                current->prev = insertionPointer->prev;
                insertionPointer->next = tmp;
                insertionPointer->prev = current;
            }
            else
                insertionPointer = insertionPointer->next;
        }
        printf("%d\n", insertionPointer->n);
        current = current->next;
    }
}