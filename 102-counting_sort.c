#include "sort.h"
#include <stdlib.h>

/**
 * counting_sort - sorting array of integers in ascending order using the
 * counting sort algorithm
 * @array: array of integers to  sort
 * @size: amount of elements in array
 */
void counting_sort(int *array, size_t size)
{
	int k, total, max;
	int *count, *output;

	if (!array || size < 2)
		return;

	max = array[0];
	for (k = 0; k < (int)size; k++)
	{
		if (array[k] > max)
			max = array[k];
	}

	count = calloc((max + 1), sizeof(int));
	if (!count)
		return;
	for (k = 0; k < (int)size; k++)
		count[array[k]]++;

	for (k = 0, total = 0; k < max + 1; k++)
	{
		total = count[k] + total;
		count[k] = total;
	}
	print_array(count, max + 1);

	output = malloc(sizeof(int) * size);
	if (!output)
		return;

	for (k = 0; k < (int)size; k++)
	{
		output[count[array[k]] - 1] = array[k];
		count[array[k]]--; /*handling the identical values*/
	}

	for (k = 0; k < (int)size; k++)
		array[k] = output[k];
	free(count);
	free(output);
}
