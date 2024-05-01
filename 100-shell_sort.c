#include "sort.h"

/**
 * shell_sort - sorting array of integers in  an ascending order using a shell
 * sort algorithm, with the gap sizes determined by a decreasing Knuth seqeuence
 * @array: array of integers to  sort
 * @size: amount of elements in the array
 */
void shell_sort(int *array, size_t size)
{
	int k, l, gap, v, Knuth_max, temp;

	if (!array || size < 2)
		return;

	v = (int)size;
	for (gap = 1; gap < v; gap = (gap * 3) + 1)
	{
		Knuth_max = gap;
	}
/* Starting with the largest Knuth sequence value less than v as gap, */
/* and working down the sequence to a gap of 1 */
	for (gap = Knuth_max; gap > 0; gap = (gap - 1) / 3)
	{
		/* A gapped insertion sort for the gap size. */
		for (k = gap; k < v; k++)
		{
			/* adding an array[k] to gap sorted elements; */
			/* saving array[k] in temp in preparation to overwrite */
			temp = array[k];
			/* shifting the earlier gap-sorted elements up until the */
			/* correct location for array[k] is found */
			for (l = k; l >= gap && array[l - gap] > temp; l -= gap)
			{
				array[l] = array[l - gap];
			}
/* temp original array[k]) to its correct location */
			array[l] = temp;
		}
		print_array(array, size);
	}
}
