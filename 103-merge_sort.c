#include "sort.h"

/**
 * print_sub_array - Prints an array of integers
 * @array: the array to be printed
 * @size: Number of elements in @array
 */
void print_sub_array(const int *array, size_t size)
{
	size_t i;

	for (i = 0; i < size; i++)
	{
		if (i > 0)
			printf(", ");
		printf("%d", array[i]);
	}
}

/**
 * merge - Merges two subarrays of an array.
 * @array: The array to be sorted
 * @size: The size of the array
 * @mid: The mid index where the array is split
 * @temp: A copy of the array
 */
void merge(int *array, size_t size, size_t mid, int *temp)
{
	size_t i = 0, j = mid, k = 0;

	printf("Merging...\n");
	printf("[left]: ");
	print_sub_array(array, mid);
	printf("\n[right]: ");
	print_sub_array(array + mid, size - mid);
	printf("\n");

	while (i < mid && j < size)
	{
		if (array[i] < array[j])
			temp[k++] = array[i++];
		else
			temp[k++] = array[j++];
	}

	while (i < mid)
		temp[k++] = array[i++];

	while (j < size)
		temp[k++] = array[j++];

	memcpy(array, temp, size * sizeof(int));
	printf("[Done]: ");
	print_sub_array(array, size);
	printf("\n");
}

/**
 * top_down_merge_sort - Sorts an array of integers in ascending order
 * @array: The array to sort
 * @size: The size of the array
 * @temp: A copy of the array
 */
void top_down_merge_sort(int *array, size_t size, int *temp)
{
	size_t mid;

	if (size < 2)
		return;

	mid = (size - 1) / 2;
	top_down_merge_sort(array, mid + 1, temp);
	top_down_merge_sort(array + mid + 1, size - mid - 1, temp + mid + 1);
	merge(array, size, mid + 1, temp);
}

/**
 * merge_sort - Sorts an array of integers in ascending order
 * @array: The array to sort
 * @size: The size of the array
 */
void merge_sort(int *array, size_t size)
{
	int *temp;

	if (array == NULL || size < 2)
		return;

	temp = malloc(size * sizeof(int));
	if (temp == NULL)
		return;

	memcpy(temp, array, size * sizeof(int));
	top_down_merge_sort(array, size, temp);

	free(temp);
}
