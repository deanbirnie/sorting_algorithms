#include "sort.h"

/**
 * swap - Swaps two integers
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
 * sift_down - Perform sift-down operation on a heap
 * @array: Array representing the heap
 * @size: Size of the heap
 * @index: Index of the element to sift down
 * @heap_size: Size of the current heap being sifted
 */
void sift_down(int *array, size_t size, size_t index, size_t heap_size)
{
	size_t max = index;
	size_t left = 2 * index + 1;
	size_t right = 2 * index + 2;

	if (left < heap_size && array[left] > array[max])
		max = left;

	if (right < heap_size && array[right] > array[max])
		max = right;

	if (max != index)
	{
		swap(&array[index], &array[max]);
		print_array(array, size);
		sift_down(array, size, max, heap_size);
	}
}

/**
 * heap_sort - Sorts an array of integers in ascending order using Heap sort algorithm
 * @array: Array of integers
 * @size: Size of the array
 */
void heap_sort(int *array, size_t size)
{
	int i;

	if (array == NULL || size < 2)
		return;

	for (i = size / 2 - 1; i >= 0; i--)
		sift_down(array, size, i, size);

	for (i = size - 1; i > 0; i--)
	{
		swap(&array[0], &array[i]);
		print_array(array, size);
		sift_down(array, size, 0, i);
	}
}
