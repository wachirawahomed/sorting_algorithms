#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * merge_subarr - Merge two subarrays into one sorted subarray.
 * @subarr: The array containing the subarrays to merge.
 * @temp: The buffer to store the sorted subarray.
 * @start: The starting index of the first subarray.
 * @mid: The ending index of the first subarray.
 * @end: The ending index of the second subarray.
 */
void merge_subarr(int *subarr, int *temp, size_t start, size_t mid, size_t end)
{
	size_t i = start, j = mid, k = 0;

	printf("Merging...\n[left]: ");
	print_array(subarr + start, mid - start);
	printf("[right]: ");
	print_array(subarr + mid, end - mid);

	while (i < mid && j < end)
	{
		if (subarr[i] <= subarr[j])
			temp[k++] = subarr[i++];
		else
			temp[k++] = subarr[j++];
	}

	while (i < mid)
		temp[k++] = subarr[i++];
	while (j < end)
		temp[k++] = subarr[j++];

	for (i = start, k = 0; i < end; i++)
		subarr[i] = temp[k++];

	printf("[Done]: ");
	print_array(subarr + start, end - start);
}

/**
 * merge_sort_recursive - Recursively apply merge sort algorithm to subarrays.
 * @subarr: The array to sort.
 * @temp: The buffer for merging subarrays.
 * @start: The starting index of the subarray.
 * @end: The ending index of the subarray.
 */
void merge_sort_recursive(int *subarr, int *temp, size_t start, size_t end)
{
	size_t mid;

	if (end - start > 1)
	{
		mid = (start + end) / 2;
		merge_sort_recursive(subarr, temp, start, mid);
		merge_sort_recursive(subarr, temp, mid, end);
		merge_subarr(subarr, temp, start, mid, end);
	}
}

/**
 * merge_sort - Sorts an array of integers in ascending order using merge sort.
 * @array: The array to sort.
 * @size: The size of the array.
 */
void merge_sort(int *array, size_t size)
{
	int *temp;

	if (array == NULL || size < 2)
		return;

	temp = malloc(sizeof(int) * size);
	if (temp == NULL)
		return;

	merge_sort_recursive(array, temp, 0, size);

	free(temp);
}
