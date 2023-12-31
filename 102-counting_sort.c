#include "sort.h"

/**
 * counting_sort - Sorts an array of integers in ascending order using
 *                the Counting sort algorithm
 * @array: The array to be sorted
 * @size: The size of the array
 */
void counting_sort(int *array, size_t size)
{
	int *count = NULL;
	int *output = NULL;
	size_t i, max_value = 0;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size; i++)
	{
		if ((size_t)array[i] > max_value)
			max_value = array[i];
	}
	count = malloc(sizeof(int) * (max_value + 1));
	if (count == NULL)
		return;

	output = malloc(sizeof(int) * size);
	if (output == NULL)
	{
		free(count);
		return;
	}
	for (i = 0; i <= max_value; i++)
		count[i] = 0;
	for (i = 0; i < size; i++)
		count[array[i]]++;
	for (i = 1; i <= max_value; i++)
		count[i] += count[i - 1];

	print_array(count, max_value + 1);
	for (i = size - 1; i < size; i--)
	{
		output[count[array[i]] - 1] = array[i];
		count[array[i]]--;
	}
	for (i = 0; i < size; i++)
		array[i] = output[i];

	free(count);
	free(output);
}
