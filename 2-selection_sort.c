#include "sort.h"

/**
 * selection_sort - Sorts a list using the selection sort algorithm.
 * @array: The array to be sorted.
 * @size: Number of elements in @array.
 */
void selection_sort(int *array, size_t size)
{
	/* Declare variables */
	size_t idx_i, idx_c, idx_less, temp, swap;

	/* Check for NULL array */
	if (array == NULL)
		return;

	for (idx_i = 0; idx_i < size; idx_i++)
	{
		for (idx_less = idx_i, idx_c = idx_i; idx_c < size; idx_c++)
		{
			if (array[idx_c] < array[idx_less])
			{
				idx_less = idx_c;
				swap = 1;
			}
		}

		if (swap == 1)
		{
			/* Swap elements */
			temp = array[idx_less];
			array[idx_less] = array[idx_i];
			array[idx_i] = temp;

			print_array(array, size);
			swap = 0;
		}
	}
}
