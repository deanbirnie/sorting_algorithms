#include "sort.h"

/**
 * getMax - Get the maximum element from the array
 * @array: the array
 * @size: size of the array
 *
 * Return: the maximum element in the array
 */
int getMax(int *array, size_t size)
{
	int max = array[0];
	size_t i;

	for (i = 1; i < size; i++)
	{
		if (array[i] > max)
		{
			max = array[i];
		}
	}
	return (max);
}

/**
 * countingSort - Counting sort for a specific digit (exp)
 * @array: The array
 * @size: Size of the array
 * @exp: exponent
 */
void countingSort(int *array, size_t size, int exp)
{
	int *output = malloc(size * sizeof(int));
	int count[10] = {0}, i;
	size_t j;

	for (j = 0; j < size; j++)
	{
		count[(array[j] / exp) % 10]++;
	}

	for (i = 1; i < 10; i++)
	{
		count[i] += count[i - 1];
	}

	for (i = size - 1; i >= 0; i--)
	{
		output[count[(array[i] / exp) % 10] - 1] = array[i];
		count[(array[i] / exp) % 10]--;
	}

	for (j = 0; j < size; j++)
	{
		array[j] = output[j];
	}

	print_array(array, size);

	free(output);
}

/**
 * radix_sort - Radix sort implementation
 * @array: the array
 * @size: the size of the array
 */
void radix_sort(int *array, size_t size)
{
	int max = getMax(array, size), exp;

	for (exp = 1; max / exp > 0; exp *= 10)
	{
		countingSort(array, size, exp);
	}
}
