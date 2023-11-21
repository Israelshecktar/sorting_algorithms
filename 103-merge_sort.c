#include "sort.h"
/**
 * merge - Merges two subarrays of integers in ascending order
 * @array: The array to be sorted
 * @size: The size of the array
 * @left: The left subarray
 * @right: The right subarray
 * @middle: The middle index
 */
void merge(int *array, size_t size, int *left, int *right, size_t middle)
{
	int i, j, k;

	i = j = k = 0;

	/* Print the left and right subarrays */
	printf("Merging...\n");
	printf("[left]: ");
	print_array(left, middle);
	printf("[right]: ");
	print_array(right, size - middle);

	/* Merge the subarrays */
	while (i < (int)middle && j < (int)(size - middle))
	{
		if (left[i] < right[j])
			array[k++] = left[i++];
		else
			array[k++] = right[j++];
	}

	/* Copy the remaining elements of the left subarray */
	while (i < (int)middle)
		array[k++] = left[i++];

	/* Copy the remaining elements of the right subarray */
	while (j < (int)(size - middle))
		array[k++] = right[j++];

	/* Print the merged array */
	printf("[Done]: ");
	print_array(array, size);
}

/**
 * merge_sort - Sorts an array of integers in ascending order
 * @array: The array to be sorted
 * @size: The size of the array
 */
void merge_sort(int *array, size_t size)
{
	size_t middle, i;
	int left[100], right[100];

	if (array == NULL || size < 2)
		return;

	/* Find the middle index */
	middle = size / 2;

	/* Divide the array into two subarrays */
	for (i = 0; i < middle; i++)
		left[i] = array[i];
	for (i = middle; i < size; i++)
		right[i - middle] = array[i];

	/* Sort the left subarray */
	merge_sort(left, middle);

	/* Sort the right subarray */
	merge_sort(right, size - middle);

	/* Merge the two subarrays */
	merge(array, size, left, right, middle);
}
