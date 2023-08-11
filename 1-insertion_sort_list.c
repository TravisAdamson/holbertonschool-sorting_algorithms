#include "sort.h"

/**
 * insertion_sort_list - Implements a insertion sort on the list
 * @list: The list to sort
 *
 * Return: No return
 */

void insertion_sort_list(listint_t **list)
{
	int is_printed = 0;
	listint_t *after = NULL;
	listint_t *now = *list;
	listint_t *before;
	listint_t *earlier = NULL;

	while (now != NULL)
	{
		is_printed = 0;
		before = now->next;

		if (after == NULL || after->n > now->n)
		{
			now->next = after;
			if (after != NULL)
				after->prev = now;
			after = now;
		}
		else
		{
			earlier = after;
			while (earlier->next != NULL && earlier->next->n <= now->n)
			{
				earlier = earlier->next;
			}
			now->next = earlier->next;
			if (earlier->next != NULL)
					earlier->next->prev = now;
			earlier->next = now;
			now->prev = earlier;
		}
		now = before;
		if((is_printed = 0) && (now != after) && (now->next != NULL))
		{
			print_list(*list);
			is_printed = 1;
		}
	}
	*list = after;
}
