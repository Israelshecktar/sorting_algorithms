#include "sort.h"

/**
 * swap_nodes - Swaps two nodes of a doubly linked list
 * @list: The list to be modified
 * @a: The first node to be swapped
 * @b: The second node to be swapped
 */
void swap_nodes(listint_t **list, listint_t *a, listint_t *b)
{
	listint_t *prev, *next;

	prev = a->prev;
	next = b->next;

	/* Adjust the links of the previous and next nodes */
	if (prev != NULL)
		prev->next = b;
	else
		*list = b;
	if (next != NULL)
		next->prev = a;

	/* Swap the nodes */
	a->next = next;
	a->prev = b;
	b->next = a;
	b->prev = prev;
}

/**
 * cocktail_sort_list - Sorts a doubly linked list of integers in ascending
 * order
 * @list: The list to be sorted
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *current;
	int swapped;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	current = *list;
	swapped = 1;

	while (swapped)
	{
		swapped = 0;

		/* Traverse the list from left to right */
		while (current->next != NULL)
		{
			if (current->n > current->next->n)
			{
				/* Swap the nodes */
				swap_nodes(list, current, current->next);

				/* Print the list after each swap */
				print_list(*list);

				swapped = 1;
			}
			else
			{
				/* Move to the next node */
				current = current->next;
			}
		}

		/* If no swap occurred, the list is sorted */
		if (swapped == 0)
			break;

		swapped = 0;

		/* Traverse the list from right to left */
		while (current->prev != NULL)
		{
			if (current->n < current->prev->n)
			{
				/* Swap the nodes */
				swap_nodes(list, current->prev, current);

				/* Print the list after each swap */
				print_list(*list);

				swapped = 1;
			}
			else
			{
				/* Move to the previous node */
				current = current->prev;
			}
		}
	}
}
