#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of integers in ascending
 * order using the Insertion sort algorithm
 * @list: Pointer to the pointer to the head of the list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *prev, *temp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	current = (*list)->next;
	while (current != NULL)
	{
		temp = current;
		prev = current->prev;

		while (prev != NULL && prev->n > temp->n)
		{
			if (prev->prev == NULL)
			{
				prev->next = temp->next;
				if (temp->next != NULL)
					temp->next->prev = prev;
				temp->next = prev;
				temp->prev = NULL;
				prev->prev = temp;
				*list = temp;
			}
			else
			{
				prev->next = temp->next;
				if (temp->next != NULL)
					temp->next->prev = prev;
				temp->next = prev;
				temp->prev = prev->prev;
				prev->prev->next = temp;
				prev->prev = temp;
			}
			prev = temp->prev;
			if (prev != NULL)
				prev->next = temp;
			print_list(*list);
		}
		current = current->next;
	}
}

