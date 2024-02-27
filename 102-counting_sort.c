#include <stdio.h>
#include <stdlib.h>
#include "sort.h"
#include <stddef.h>

/**
 * find_max - Finds the maximum element in an array
 * @array: The array to search
 * @size: Number of elements in the array
 * Return: The maximum element in the array
 */
int find_max(int *array, size_t size)
{
	size_t i;
	int max;

	max = array[0];
	for (i = 1; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}
	return (max);
}

/**
 * counting_sort - Sorts an array of integers in ascending order using
 * the Counting Sort algorithm
 * @array: The array to be sorted
 * @size: Number of elements in the array
 */
void counting_sort(int *array, size_t size)
{
	int max, *count, *output;
	size_t i;

	if (array == NULL || size < 2)
		return;

	max = find_max(array, size);
	count = malloc((max + 1) * sizeof(int));
	output = malloc(size * sizeof(int));

	if (count == NULL || output == NULL)
	{
		free(count);
		free(output);
		return;
	}

	for (i = 0; i <= (size_t)max; i++)
		count[i] = 0;

	for (i = 0; i < size; i++)
		count[array[i]]++;

	for (i = 1; i <= (size_t)max; i++)
		count[i] += count[i - 1];
	print_array(count, max + 1);

	for (i = size - 1; (int)i >= 0; i--)
	{
		output[count[array[i]] - 1] = array[i];
		count[array[i]]--;
	}

	for (i = 0; i < size; i++)
		array[i] = output[i];

	free(count);
	free(output);
}
