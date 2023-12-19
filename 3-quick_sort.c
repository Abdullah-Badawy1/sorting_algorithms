#include "sort.h"

/**
* partition - Partitions the array for Quick Sort
* @array: Array to be sorted
* @first: First position
* @last: Last position
* @size: Size of the array
* Return: Integer pivot index
*/
int partition(int *array, int first, int last, size_t size)
{
	int idx_i = first - 1, temp, idx_j;

	for (idx_j = first; idx_j <= last - 1; idx_j++)
	{
		if (array[idx_j] < array[last])
		{
			idx_i++;
			if (idx_i < idx_j)
			{
				temp = array[idx_i];
				array[idx_i] = array[idx_j];
				array[idx_j] = temp;
				print_array(array, size);
			}
		}
	}
	if (array[idx_i + 1] > array[last])
	{
		temp = array[idx_i + 1];
		array[idx_i + 1] = array[last];
		array[last] = temp;
		print_array(array, size);
	}

	return (idx_i + 1);
}

/**
* qs - Sorts an array of integers recursively
* @array: Array to sort
* @first: First position
* @last: Last position
* @size: Size of the array
*/
void qs(int *array, int first, int last, size_t size)
{
	int pivot;

	if (first < last)
	{
		pivot = partition(array, first, last, size);
		qs(array, first, pivot - 1, size);
		qs(array, pivot + 1, last, size);
	}
}

/**
* quick_sort - Sorts an array of integers using the Quick
* sort algorithm in ascending order
* @array: Array to sort
* @size: Size of the array
*/
void quick_sort(int *array, size_t size)
{
	qs(array, 0, size - 1, size);
}
