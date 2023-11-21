#include "sort.h"

/**
 * swap - Swaps two elements in an array
 * @array: The array
 * @i: The first index
 * @j: The second index
 * @size: The size of the array
 * @dir: The direction to sort
 */
void swap(int *array, int i, int j, size_t size, int dir)
{
	int temp;

	if (dir == (array[i] > array[j]))
	{
		temp = array[i];
		array[i] = array[j];
		array[j] = temp;
		print_array(array, size);
	}
}

/**
 * bitonic_merge - Merges two subarrays in a bitonic sequence
 * @array: The array
 * @low: The lowest index of the subarray
 * @count: The size of the subarray
 * @size: The size of the array
 * @dir: The direction to sort
 */
void bitonic_merge(int *array, int low, int count, size_t size, int dir)
{
	int i, k;

	if (count > 1)
	{
		k = count / 2;
		for (i = low; i < low + k; i++)
			swap(array, i, i + k, size, dir);
		bitonic_merge(array, low, k, size, dir);
		bitonic_merge(array, low + k, k, size, dir);
	}
}

/**
 * bitonic_sort_rec - Recursively sorts a bitonic sequence
 * @array: The array
 * @low: The lowest index of the subarray
 * @count: The size of the subarray
 * @size: The size of the array
 * @dir: The direction to sort
 */
void bitonic_sort_rec(int *array, int low, int count, size_t size, int dir)
{
	int k;

	if (count > 1)
	{
		k = count / 2;
		printf("Merging [%d/%lu] (%s):\n", count, size, dir ? "UP" : "DOWN");
		print_array(array + low, count);
		bitonic_sort_rec(array, low, k, size, 1);
		bitonic_sort_rec(array, low + k, k, size, 0);
		printf("Result [%d/%lu] (%s):\n", count, size, dir ? "UP" : "DOWN");
		bitonic_merge(array, low, count, size, dir);
		print_array(array + low, count);
	}
}

/**
 * bitonic_sort - Sorts an array of integers in ascending order
 * @array: The array to be sorted
 * @size: The size of the array
 */
void bitonic_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	bitonic_sort_rec(array, 0, size, size, 1);
}
