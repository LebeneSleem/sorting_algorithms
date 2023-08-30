#include "sort.h"

/**
 * custom_swap -wap two elements in an array
 * @array: Array to swap elements in
 * @index1: Index of the first element to swap
 * @index2: Index of the second element to swap
 */

void custom_swap(int *array, ssize_t index1, ssize_t index2)
{
	int temp = array[index1];

	array[index1] = array[index2];
	array[index2] = temp;
}

/**
 * lomuto_partition - Lomuto partition scheme implementation
 * @array: Array to be partitioned
 * @low: Index of the first element
 * @high: Index of the last element
 * @size:ize of the array
 * Return: Position of the pivot after partitioning
 */

int lomuto_partition(int *array, ssize_t low, ssize_t high, size_t size)
{
	int pivot = array[high];
	ssize_t i = low - 1;

	for (ssize_t j = low; j <= high - 1; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			if (i != j)
			{
				custom_swap(array, i, j);
				print_array(array, size);
			}
		}
	}

	if (array[i + 1] != array[high])
	{
		custom_swap(array, i + 1, high);
		print_array(array, size);
	}

	return (i + 1);
}

/**
 * custom_quick_sort - Recursive Quick sort algorithm
 * @array: Array to be sorted
 * @low: Index of the first element
 * @high: Index of the last element
 * @size:ize of the array
 */

void custom_quick_sort(int *array, ssize_t low, ssize_t high, size_t size)
{
	if (low < high)
	{
		ssize_t pivot_index = custom_lomuto_partition(array, low, high, size);

		custom_quick_sort(array, low, pivot_index - 1, size);
		custom_quick_sort(array, pivot_index + 1, high, size);
	}
}

/**
 * quick_sort - Wrapper function to initiate Quick sort
 * @array: Array to be sorted
 * @size:ize of the array
 */

void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	custom_quick_sort(array, 0, size - 1, size);
}

