#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of integers in ascending
 * order using the Insertion sort algorithm
 *
 * @list: Double pointer to the head of the list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *inner, *prev, *next;

	if (!list || !(*list) || !((*list)->next))
		return;

	current = (*list)->next;
	while (current)
	{
		inner = current;
		while (inner && inner->prev && inner->n < inner->prev->n)
		{
			prev = inner->prev;
			next = inner->next;

			if (prev->prev)
				prev->prev->next = inner;
			else
				*list = inner;

			if (next)
				next->prev = prev;

			inner->prev = prev->prev;
			inner->next = prev;
			prev->prev = inner;
			prev->next = next;

			print_list(*list);
			inner = current;
		}

		current = current->next;
	}
}
