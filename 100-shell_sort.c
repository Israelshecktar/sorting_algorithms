#include "sort.h"

/**
 * shell_sort - Sorts an array of integers in ascending order
 * @array: The array to be sorted
 * @size: The size of the array
 */
void shell_sort(int *array, size_t size)
{
	size_t gap, i, j;
	int temp;

	if (array == NULL || size < 2)
		return;

	/* Calculate the initial gap using the Knuth sequence */
	gap = 1;
	while (gap < size / 3)
		gap = gap * 3 + 1;

	while (gap > 0)
	{
		/* Perform insertion sort with the current gap */
		for (i = gap; i < size; i++)
		{
			temp = array[i];
			j = i;
			while (j >= gap && array[j - gap] > temp)
			{
				array[j] = array[j - gap];
				j -= gap;
			}
			array[j] = temp;
		}

		/* Print the array after each gap decrease */
		print_array(array, size);

		/* Decrease the gap */
		gap = (gap - 1) / 3;
	}
}
