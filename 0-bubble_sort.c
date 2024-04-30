#include "sort.h"

/**
 * custom_bubble_sort - sorting an array of integers in an ascending order
 * using a modified Bubble sort algorithm
 * @arr: Array to sort
 * @size: size of the array
 *
 * Return: Void
 */
void custom_bubble_sort(int *arr, size_t size)
{
	size_t i, j, size2 = size;
	int temp, sorted = 0;

	if (arr == NULL || size < 2)
		return;

	for (i = 0; i < size; i++)
	{
		for (j = 1; j < size2; j++)
		{
			if (arr[j - 1] > arr[j])
			{
				sorted = 1;
				temp = arr[j];
				arr[j] = arr[j - 1];
				arr[j - 1] = temp;
				print_array(arr, size);
			}
		}

		// If there is no swapping,  array  already sorted
		if (!sorted)
			break;

		// Reset sorted flag
		sorted = 0;

		// Decrease size for optimization
		size2--;
	}
}
