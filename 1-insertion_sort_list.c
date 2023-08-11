#include "sort.h"

/**
 * insertion_sort_list - Implements a insertion sort on the list
 * @list: The list to sort
 *
 * Return: No return
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *after = NULL;
	listint_t *now = head;
	listint_t *before;
	listint_t *earlier = NULL;

	while (now != NULL)
	{
		before = now->next;

		if (after == NULL || after->n > now->n)
		{
			now->next = after;
			if (after != NULL)
				after->prev = current;
			after = now;
		}
		else
		{
			earlier = after;
			while (earlier->next != NULL && earlier->next->n <= current->data)
				earlier = earlier->next;
			now->next = earlier->next;
			if (earlier->next != NULL)
					earlier->next->prev = now;
			earlier->next = now;
			now->prev = earlier;
		}
		now = before;
	}
	head = after;
}