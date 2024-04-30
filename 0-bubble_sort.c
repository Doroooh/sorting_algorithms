#include "sort.h"

/**
 * bubble_sort - this sorts an array of integers in an ascending order with a bubble
 * sort algorithm
 * @array: array of integers to be sorted
 * @size: amount of elements in array
 */
void bubble_sort(int *array, size_t size)
{
	size_t a, m;
	int temp;
	bool swapped = true;

	if (!array || size < 2)
		return;

	m = size;
	while (swapped)
	{
		swapped = false;
		for (a = 1; a < m; a++)
		{
			if (array[a - 1] > array[a])
			{
				temp = array[a - 1];
				array[i - 1] = array[a];
				array[a] = temp;
				swapped = true;
				print_array(array, size);
			}
		}
		/* optimize by logically elinating final swap from last loop */
		m--;
	}
}
