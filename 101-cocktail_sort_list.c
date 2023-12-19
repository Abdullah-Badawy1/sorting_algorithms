#include "sort.h"

/**
 * swap_nodes - Swaps the nodes themselves in a doubly linked list.
 * @current: Current node pointer.
 * @current_old: Old current node pointer.
 * @list: Doubly linked list.
 */
void swap_nodes(listint_t *current, listint_t *current_old, listint_t **list)
{
	listint_t *temp_next = current->next;
	listint_t *temp_prev = current_old->prev;

	if (temp_next != NULL)
		temp_next->prev = current_old;
	if (temp_prev != NULL)
		temp_prev->next = current;
	current->prev = temp_prev;
	current_old->next = temp_next;
	current->next = current_old;
	current_old->prev = current;

	if (*list == current_old)
		*list = current;

	print_list(*list);
}

/**
 * cocktail_sort_list - Sorts a doubly linked list
 * using the Cocktail Shaker sort algorithm.
 * @list: Doubly linked list to be sorted.
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *check = *list, *first = NULL, *last = NULL;

	if (!list || !(*list) || !(*list)->next)
		return;

	do {
		while (check->next)
		{
			if (check->n > check->next->n)
				swap_nodes(check->next, check, list);
			else
				check = check->next;
		}
		last = check;

		while (check->prev != first)
		{
			if (check->n < check->prev->n)
				swap_nodes(check, check->prev, list);
			else
				check = check->prev;
		}
		first = check;
	} while (first != last);
}
