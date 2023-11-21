#include <stdio.h>
#include "sort.h"

/**
 * swap - swaps two integers in an array
 * @a: first integer to swap
 * @b: second integer to swap
 */
void swap(int *a, int *b)
{
	int t = *a;
	*a = *b;
	*b = t;
}

/**
 * partition - partitions array around pivot
 * @array: array to partition
 * @start: starting index of partition
 * @end: ending index of partition
 * @size: size of array
 *
 * Return: final index for pivot
 */
int partition(int *array, int start, int end, size_t size)
{
	int pivot = array[start];
	int i = start - 1;
	int j = end + 1;

	while (1)
	{
		do {
			i++;
		} while (array[i] < pivot);

		do {
			j--;
		} while (array[j] > pivot);

		if (i >= j)
			return (j);

		swap(&array[i], &array[j]);
		print_array(array, size);
	}
}

/**
 * quicksort - sorts array using quicksort algorithm
 * @array: array to sort
 * @start: start index of array partition
 * @end: end index of array partition
 * @size: size of array
 */
void quicksort(int *array, int start, int end, size_t size)
{
	int pivot;

	if (start < end)
	{
		pivot = partition(array, start, end, size);
		quicksort(array, start, pivot, size);
		quicksort(array, pivot + 1, end, size);
	}
}

/**
 * quick_sort_hoare - sorts array using Hoare quicksort algorithm
 * @array: array to sort
 * @size: size of array
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quicksort(array, 0, size - 1, size);
}
