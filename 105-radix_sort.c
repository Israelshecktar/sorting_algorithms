#include "sort.h"

/**
 * get_max - Gets the maximum element in an array
 * @array: The array
 * @size: The size of the array
 * Return: The maximum element
 */
int get_max(int *array, size_t size)
{
	int max, i;

	max = array[0];
	for (i = 1; i < (int)size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}
	return (max);
}

/**
 * count_sort - Performs counting sort on an array based on a digit
 * @array: The array
 * @size: The size of the array
 * @exp: The exponent of 10 that represents the digit to sort by
 */
void count_sort(int *array, size_t size, int exp)
{
	int *output, *count;
	int i, digit;

	output = malloc(sizeof(int) * size);
	count = malloc(sizeof(int) * 10);
	if (output == NULL || count == NULL)
	{
		free(output);
		free(count);
		return;
	}

	/* Initialize the count array to zero */
	for (i = 0; i < 10; i++)
		count[i] = 0;

	/* Count the frequency of each digit in the array */
	for (i = 0; i < (int)size; i++)
	{
		digit = (array[i] / exp) % 10;
		count[digit]++;
	}

	/* Calculate the cumulative sum of the count array */
	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];

	for (i = size - 1; i >= 0; i--)
	{
		digit = (array[i] / exp) % 10;
		output[count[digit] - 1] = array[i];
		count[digit]--;
	}

	for (i = 0; i < (int)size; i++)
		array[i] = output[i];

	free(output);
	free(count);
}

/**
 * radix_sort - Sorts an array of integers in ascending order
 * @array: The array to be sorted
 * @size: The size of the array
 */
void radix_sort(int *array, size_t size)
{
	int max, exp;

	if (array == NULL || size < 2)
		return;

	/* Find the maximum element in the array */
	max = get_max(array, size);

	for (exp = 1; max / exp > 0; exp *= 10)
	{
		count_sort(array, size, exp);
		print_array(array, size);
	}
}
