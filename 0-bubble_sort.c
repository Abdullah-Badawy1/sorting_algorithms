#include "sort.h"

/**
* bubble_sort - Sorts a list using the bubble sort algorithm.
* @array: The array to be sorted.
* @size: Number of elements in @array.
*/
void bubble_sort(int *array, size_t size)
{
	/* Initialize variables */
	size_t idx_outer = 0, idx_inner = size;
	int temp_holder;

	/* Check for NULL array */
	if (array == NULL)
		return;

	/* Perform bubble sort */
	for (idx_inner = size; idx_inner > 0; idx_inner--)
	{
		for (idx_outer = 0; idx_outer < size - 1; idx_outer++)
		{
			/* Swap elements if needed */
			if (array[idx_outer] > array[idx_outer + 1])
		{
				temp_holder = array[idx_outer];
				array[idx_outer] = array[idx_outer + 1];
				array[idx_outer + 1] = temp_holder;
				print_array(array, size);
			}
		}
	}
}
