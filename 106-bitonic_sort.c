#include "sort.h"

/**
 * bitonic_split - Performs the bitonic split phase of the Bitonic sort
 * algorithm
 * @array: The array to be sorted
 * @low: The starting index of the subarray
 * @size: The size of the subarray
 * @dir: The direction of the sorting, 1 for ascending and 0 for descending
 */
void bitonic_split(int *array, size_t low, size_t size, int dir)
{
	size_t i, gap;
	int temp;

	if (size > 1)
	{
		gap = size / 2;
		for (i = low; i < low + gap; i++)
		{
			if ((dir == 1 && array[i] > array[i + gap]) ||
					(dir == 0 && array[i] < array[i + gap]))
			{
				temp = array[i];
				array[i] = array[i + gap];
				array[i + gap] = temp;
				print_array(array, size);
			}
		}
		bitonic_split(array, low, gap, dir);
		bitonic_split(array, low + gap, gap, dir);
	}
}

/**
 * bitonic_merge - Performs the bitonic merge phase of the Bitonic sort
 * algorithm
 * @array: The array to be sorted
 * @low: The starting index of the subarray
 * @size: The size of the subarray
 * @dir: The direction of the sorting, 1 for ascending and 0 for descending
 */
void bitonic_merge(int *array, size_t low, size_t size, int dir)
{
	size_t i, gap;
	int temp;

	if (size > 1)
	{
		gap = size / 2;
		for (i = low; i < low + gap; i++)
		{
			if ((dir == 1 && array[i] > array[i + gap]) ||
					(dir == 0 && array[i] < array[i + gap]))
			{
				temp = array[i];
				array[i] = array[i + gap];
				array[i + gap] = temp;
				print_array(array, size);
			}
		}
		bitonic_merge(array, low, gap, dir);
		bitonic_merge(array, low + gap, gap, dir);
	}
}

/**
 * bitonic_sort - Sorts an array of integers in ascending order using the
 * Bitonic sort algorithm
 * @array: The array to be sorted
 * @size: The size of the array
 */
void bitonic_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	bitonic_split(array, 0, size, 1);
}
