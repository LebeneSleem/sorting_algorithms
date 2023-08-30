#include "sort.h"

/**
 * swap_integers -waps the values of two integers.
 * @a: Pointer to the first integer.
 * @b: Pointer to the second integer.
 **/
void swap_integers(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * bubble_sort - sorts an array of integers in ascending order using
 * the Bubble sort algorithm
 * @array: pointer to array
 * @size: size of the array
 **/
void bubble_sort(int *array, size_t size)
{
	size_t a, b;
	int flag;

	if (array == NULL || size < 2)
		return;

	for (a = 0; a < size - 1; a++)

	{
		flag = 0;
		for (b = 0; b < size - 1 - a; b++)

		{
			if (array[b] > array[b + 1])
			{
				swap_integers(array + b, array + b + 1);
				flag = 1;
				print_array(array, size);
			}
		}
		if (flag == 0)
		break;
	}
}

