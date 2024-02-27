#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * sift_down - Repair the heap whose root element is at index 'start'.
 * @array: The array containing the heap elements.
 * @start: The index of the root element of the heap.
 * @end: The index of the last element in the heap.
 */
void sift_down(int *array, size_t start, size_t end)
{
	size_t root, child, swap;
	int temp;

	root = start;
	while (root * 2 + 1 <= end)
	{
		child = root * 2 + 1;
		swap = root;

		if (array[swap] < array[child])
			swap = child;
		if (child + 1 <= end && array[swap] < array[child + 1])
			swap = child + 1;
		if (swap != root)
		{
			temp = array[root];
			array[root] = array[swap];
			array[swap] = temp;
			print_array(array, end + 1);
			root = swap;
		}
		else
			return;
	}
}

/**
 * heapify - Build a heap from the array.
 * @array: The array containing the elements to heapify.
 * @size: The size of the array.
 */
void heapify(int *array, size_t size)
{
	int start;

	for (start = (size - 2) / 2; start >= 0; start--)
		sift_down(array, start, size - 1);
}

/**
 * heap_sort - Sorts an array of integers in ascending order using heap sort.
 * @array: The array to sort.
 * @size: The size of the array.
 */
void heap_sort(int *array, size_t size)
{
	size_t end;
	int temp;

	if (array == NULL || size < 2)
		return;

	heapify(array, size);

	for (end = size - 1; end > 0; end--)
	{
		temp = array[0];
		array[0] = array[end];
		array[end] = temp;
		print_array(array, size);
		sift_down(array, 0, end - 1);
	}
}
