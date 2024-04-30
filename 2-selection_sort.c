#include "sort.h"
/**
  * selection_sort - select the sort algorithm
  * @array: array to be sorted
  * @size: size of an array
  */
void selection_sort(int *array, size_t size)
{
	size_t l, l2;
	int min, tmp, idx;

	for (l = 0; l < size; l++)
	{
		min = array[l];
		for (l2 = l + 1; l2 < size; l2++)
		{
			if (min > array[l2])
			{
				min = array[l2];
				idx = l2;
			}
		}
		if (min != array[l])
		{
			tmp = array[l];
			array[l] = min;
			array[idx] = tmp;
			print_array(array, size);
		}
	}
}
