#include "sort.h"

/**
 * merge - Merges two sorted subarrays into one sorted array
 * @array: The original array
 * @size: The size of the array
 * @left: Pointer to the left subarray
 * @left_size: Size of the left subarray
 * @right: Pointer to the right subarray
 * @right_size: Size of the right subarray
 */
void merge(int *array, size_t size, int *left, size_t left_size, int *right, size_t right_size)
{
	size_t i = 0, j = 0, k = 0;
	int *merged = malloc(sizeof(int) * size);

	if (merged == NULL)
		return;

	printf("Merging...\n[left]: ");
	print_array(left, left_size);
	printf("[right]: ");
	print_array(right, right_size);

	while (i < left_size && j < right_size)
	{
		if (left[i] <= right[j])
			merged[k++] = left[i++];
		else
			merged[k++] = right[j++];
	}

	while (i < left_size)
		merged[k++] = left[i++];

	while (j < right_size)
		merged[k++] = right[j++];

	for (i = 0; i < size; i++)
		array[i] = merged[i];

	printf("[Done]: ");
	print_array(array, size);

	free(merged);
}

/**
 * merge_sort - Sorts an array of integers in ascending order
 *              using the Merge sort algorithm (top-down)
 * @array: The array to be sorted
 * @size: The size of the array
 */
void merge_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	if (size > 1)
	{
		size_t mid = size / 2;
		size_t left_size = mid;
		size_t right_size = size - mid;
		int *left = array;
		int *right = array + mid;

		printf("Splitting...\n[left]: ");
		print_array(left, left_size);
		printf("[right]: ");
		print_array(right, right_size);

		merge_sort(left, left_size);
		merge_sort(right, right_size);

		merge(array, size, left, left_size, right, right_size);
	}
}
