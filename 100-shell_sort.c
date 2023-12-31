#include "sort.h"

/**
 * shell_sort - a function that sorts an array of
 * integers in ascending order using the Shell sort algorithm,
 * using the Knuth sequence
 * @array: array of integers
 * @size: size of the array
 * Return: Void
 */
void shell_sort(int *array, size_t size)
{
	size_t gap;
	int temp;
	size_t i, j;

	if (array == NULL || size < 2)
		return;

	gap = 1;

	while (gap <= size / 3)
	{
		gap = gap * 3 + 1;
	}

	while (gap > 0)
	{
		for (i = gap; i < size; i++)
		{
			temp = array[i];
			for (j = i; j >= gap && array[j - gap] > temp; j -= gap)
			{
				array[j] = array[j - gap];
			}
			array[j] = temp;
		}
		print_array(array, size);
		gap = (gap - 1) / 3;
	}

}
