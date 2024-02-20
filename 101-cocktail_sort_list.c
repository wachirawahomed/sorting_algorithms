#include "sort.h"

/**
 * swap_nodes - Swaps two nodes in a doubly linked list
 * @list: Pointer to the doubly linked list
 * @a: Pointer to the first node
 * @b: Pointer to the second node
 */
void swap_nodes(listint_t **list, listint_t *a, listint_t *b)
{
	if (a->prev)
		a->prev->next = b;
	if (b->next)
		b->next->prev = a;
	if (a->next == b)
	{
		a->next = b->next;
		b->prev = a->prev;
		a->prev = b;
		b->next = a;
	}
	else
	{
		listint_t *temp = b->next;

		a->prev->next = b;
		b->next = a->next;
		a->next->prev = b;
		b->prev = a->prev;
		a->prev = temp->prev;
		b->prev->next = a;
		a->next = temp;
		temp->prev = a;
	}
	if (!b->prev)
		*list = b;
}

/**
 * cocktail_sort_list - Sorts a doubly linked list of integers in ascending
 * order using Cocktail Shaker sort algorithm
 * @list: Pointer to the doubly linked list
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *start = NULL, *end = NULL, *curr = NULL;
	int swapped;

	if (list == NULL || *list == NULL)
		return;

	do {
		swapped = 0;
		for (curr = start = (*list)->next; curr && curr->next != end;
				curr = curr->next)
		{
			if (curr->n > curr->next->n)
			{
				swap_nodes(list, curr, curr->next);
				print_list(*list);
				swapped = 1;
			}
		}
		end = curr;
		if (!swapped)
			break;
		swapped = 0;
		for (curr = end = end->prev; curr && curr->prev != start;
				curr = curr->prev)
		{
			if (curr->n < curr->prev->n)
			{
				swap_nodes(list, curr->prev, curr);
				print_list(*list);
				swapped = 1;
			}
		}
		start = curr;
	} while (swapped);
}
