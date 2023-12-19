#include "sort.h"

/**
 * shell_sort - Sorts an array using Shell sort with Knuth Sequence
 * @array: Array to be sorted
 * @size: Size of the array
 */
void shell_sort(int *array, size_t size)
{
	int gap = 1, idx_i, idx_j, temp;

	while (gap < ((int)(size)))
		gap = (3 * gap) + 1;
	for (gap = (gap - 1) / 3; gap > 0; gap = (gap - 1) / 3)
	{
		for (idx_i = gap; idx_i < (int)size; idx_i += 1)
		{
			temp = array[idx_i];

			for (idx_j = idx_i; idx_j >= gap &&
				array[idx_j - gap] > temp; idx_j -= gap)
				array[idx_j] = array[idx_j - gap];

			array[idx_j] = temp;
		}
		print_array(array, size);
	}
}
