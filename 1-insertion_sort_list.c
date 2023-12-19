#include "sort.h"

/**
* insertion_sort_list -Sorts a linked list using
* the insertion sort algorithm.
* @list: Linked list to be sorted.
*/
void insertion_sort_list(listint_t **list)
{
	/* Declare temporary variables */
	listint_t *current_node;
	int temp_value;

	/* Check for NULL list */
	if (!list)
		return;

	current_node = *list;

	while (current_node)
	{
		while (current_node)
		{
			if (current_node->next)
			{
				if (current_node->n > current_node->next->n)
				{
					/* Swap values */
					temp_value = current_node->n;
			*(int *)&current_node->n = current_node->next->n;
			*(int *)&current_node->next->n = temp_value;

					current_node = *list;
					print_list(*list);
					break;
				}
			}
			current_node = current_node->next;
		}
	}
}
