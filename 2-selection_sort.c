#include "sort.h"

/**
 * selection_sort - Sorts an array of integers in ascending order
 * @array: The array to be sorted
 * @size: The size of the array
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, min;
	int temp;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		min = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[min])
				min = j;
		}
		if (min != i)
		{
			/* Swap the elements */
			temp = array[i];
			array[i] = array[min];
			array[min] = temp;

			/* Print the array after each swap */
			print_array(array, size);
		}
	}
}
