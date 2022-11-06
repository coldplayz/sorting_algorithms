#include "sort.h"

listint_t *list_tail(listint_t *list);
void swap_nodes(listint_t *first, listint_t *second);
void swap_reference(listint_t **first, listint_t **second);


/**
 * cocktail_sort_list - implements cocktail shaker sort for doubly-linked lists
 * @list: address of the head of list to sort.
 */
void cocktail_sort_list(listint_t **list)
{
	int swapped = 0;
	listint_t *first, *second, *second_bkup, *left_stop, *right_stop;

	if (!list || *list == NULL || (*list)->next == NULL)
	{
		return;
	}

	left_stop = *list;
	right_stop = list_tail(*list);
	for (first = left_stop;; first = left_stop)
	{
		/* printf("In %d\n", 1); */
		for (second = first->next; second != right_stop->next; second = second->next)
		{
			/* printf("In %da\n", 1); */
			if (second->n < first->n)
			{
				/* printf("In %da(i)\n", 1); */
				/* Swap values, removing 'first' first */
				if (first == *list)
					*list = second;
				swap_nodes(first, second);
				print_list(*list);
				swap_reference(&first, &second);
				swapped = 1;
				if (second == left_stop)
					left_stop = first; /* @second to replace @first */
				if (first == right_stop)
					right_stop = second;
			}
			second_bkup = second; /* in-case @second becomes NULL */
			first = first->next;
		}
		if (!swapped)
			return; /* no swap in last loop; list fully sorted */
		right_stop = right_stop->prev;
		second = second_bkup;
		for (first = first->prev; first != left_stop->prev; first = first->prev)
		{
			/* printf("In %db\n", 1); */
			if (first->n > second->n)
			{
				if (first == *list)
					*list = second; /* update list head */
				swap_nodes(first, second);
				print_list(*list);
				swap_reference(&first, &second);
				swapped = 1;
				if (second == left_stop)
					left_stop = first; /* the only clash that can happen in this loop */
			}
			second = second->prev;
		}
		left_stop = left_stop->next;
		if (!swapped || left_stop->prev == right_stop || left_stop == right_stop)
		{
			printf("sw: %d\tlsp: %p\trs: %p\tls: %p\n", swapped, (void *)left_stop->prev, (void *)right_stop, (void *)left_stop);
			return;
		}
		swapped = 0; /* restore default */
	}
}





/**
 * list_tail - returns the tail of a linked list.
 * @list: the head pointer of the list to return the tail of.
 *
 * Return: the tail of @list.
 */
listint_t *list_tail(listint_t *list)
{
	listint_t *tail;

	if (!list)
	{
		return (NULL);
	}

	tail = list;
	while (tail->next)
	{
		tail = tail->next;
	}

	return (tail);
}



/**
 * swap_nodes - swaps adjacent nodes of a doubly-linked list.
 * @first: left node.
 * @second: right node.
 */
void swap_nodes(listint_t *first, listint_t *second)
{
	second->prev = first->prev;
	if (first->prev != NULL)
	{
		first->prev->next = second;
	}
	first->prev = second;
	first->next = second->next;
	second->next = first;
	if (first->next != NULL)
	{
		first->next->prev = first;
	}
}


/**
 * swap_reference - updates reference to adjacent nodes after swapping.
 * @first: address of the reference 'first' in cocktail_sort_list().
 * @second: address of the reference 'second' in cocktail_sort_list().
 */
void swap_reference(listint_t **first, listint_t **second)
{
	listint_t *tmp;

	tmp = *first;
	*first = *second;
	*second = tmp;
}



/**
 * update_lstop - updates the left_stop in cocktail_sort_list().
 * @lstop: pointer representing the left_stop address to update.
 * @second: pointer to update @lstop with.
 */
/* void update_lstop(listint_t *lstop, listint_t *second)
{
}
*/
