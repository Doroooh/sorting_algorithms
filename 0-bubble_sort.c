#include "sort.h"

/**
 * bubble_sort - sorting array of integers in an ascending order
 * using the Bubble sort algorithm
 * @array: Array to be sorted
 * @size: size of array
 *
 * Return: Void
 */
void bubble_sort(int *array, size_t size)
{
	size_t k, l, sizetwo= size;
	int tmp, flag = 0;

	if (array == NULL || size < 2)
		return;
	for (k = 0; k< size; k++)
	{
		for (l = 1; l < sizetwo; l++)
		{
			if (array[l - 1] > array[l])
			{
				flag = 1;
				tmp = array[l];
				array[l] = array[l - 1];
				array[l - 1] = tmp;
				print_array(array, size);
			}
		}
		if (flag == 0)
			break;
		flag = 0;
		sizetwo--;
	}
}
