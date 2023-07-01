#include "sort.h"

/**
 * swap - Swaps two integers
 *
 * @a: First integer
 * @b: Second integer
 */
void swap(int *a, int *b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * partition - Lomuto partition scheme for Quick sort
 *
 * @array: The array to be sorted
 * @low: Starting index of the partition
 * @high: Ending index of the partition
 *
 * Return: Index of the pivot element
 */
int partition(int *array, int low, int high)
{
	int pivot = array[high];
	int i = low - 1;
	int j;

	for (j = low; j <= high - 1; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			swap(&array[i], &array[j]);
		}
	}
	swap(&array[i + 1], &array[high]);

	return (i + 1);
}

/**
 * quicksort - Recursive function to perform Quick sort
 *
 * @array: The array to be sorted
 * @low: Starting index of the partition
 * @high: Ending index of the partition
 */
void quicksort(int *array, int low, int high)
{
	int pivot, i;

	if (low < high)
	{
		pivot = partition(array, low, high);

		for (i = 0; i < high + 1; i++)
			printf("%d ", array[i]);
		printf("\n");

		quicksort(array, low, pivot - 1);
		quicksort(array, pivot + 1, high);
	}
}

/**
 * quick_sort - Sorts an array of integers in ascending order using
 *              the Quick sort algorithm with Lomuto partition scheme
 *
 * @array: The array to be sorted
 * @size: Number of elements in the array
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size <= 1)
		return;

	quicksort(array, 0, (int)size - 1);
}
