#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * getMax - Get the maximum element from the array.
 * @array: The array of integers.
 * @size: The size of the array.
 * Return: The maximum element in the array.
 */
int getMax(int *array, size_t size) {
	size_t i;
	int max = array[0];

	for (i = 1; i < size; i++) {
		if (array[i] > max) {
			max = array[i];
		}
	}

	return max;
}

/**
 * countSort - Perform counting sort based on the digit (exp).
 * @array: The array of integers.
 * @size: The size of the array.
 * @exp: The exponent for the current digit place value.
 */
void countSort(int *array, size_t size, int exp) {
	int *output;
	int count[10] = {0};
	int i;
	size_t ix;

	output = malloc(size * sizeof(int));
	if (output == NULL) {
		return;
	}

	for (ix = 0; ix < size; ix++) {
		count[(array[ix] / exp) % 10]++;
	}

	for (i = 1; i < 10; i++) {
		count[i] += count[i - 1];
	}

	for (i = size - 1; i >= 0; i--) {
		output[count[(array[i] / exp) % 10] - 1] = array[i];
		count[(array[i] / exp) % 10]--;
	}

	for (ix = 0; ix < size; ix++) {
		array[ix] = output[ix];
	}

	print_array(array, size);
	free(output);
}

/**
 * radix_sort - Sorts an array of integers in ascending order using radix sort.
 * @array: The array to sort.
 * @size: The size of the array.
 */
void radix_sort(int *array, size_t size) {
	int max;
	int exp;

	if (array == NULL || size < 2) {
		return;
	}

	max = getMax(array, size);

	for (exp = 1; max / exp > 0; exp *= 10) {
		countSort(array, size, exp);
	}
}
