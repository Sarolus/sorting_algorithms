#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list of int in ascending order
 * using the Insertion sort algorithm
 *
 * @list: doubly linked list
 *
 * Return: void
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *tmp;

	if (!list)
		return;

	for (tmp = (*list)->next; tmp; tmp = tmp->next)
		while (tmp->prev && tmp->prev->n > tmp->n)
		{
			tmp->prev->next = tmp->next;
				if (tmp->next)
					tmp->next->prev = tmp->prev;

			tmp->next = tmp->prev;
			tmp->prev = tmp->next->prev;
			tmp->next->prev = tmp;

			if (tmp->prev == NULL)
				*list = tmp;
			else
				tmp->prev->next = tmp;

			print_list(*list);
		}
	}
}
