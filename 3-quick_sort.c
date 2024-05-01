#include "sort.h"

/**
 * partition - scanning  partition of  array of integers for values less than
 * pivot value, and swaps it with the first value in partition, then swaps pivot
 * value with first value in the partition
 * @array: array of integers to sort
 * @low: index in array  beginning the partition
 * @high: index in array  ending the  partition
 * @size: amount of elements in the array
 * Return: new index where to start new recursive partition
 */
int partition(int *array, int low, int high, size_t size)
{
	int k, l, pivot, temp;

	pivot = array[high];
	k = low;
	for (l = low; l < high; l++)
	{
		if (array[l] < pivot)
		{
			temp = array[k];
			array[k] = array[l];
			array[l] = temp;
			if (array[k] != array[l])
				print_array(array, size);
			k++;
		}
	}
	temp = array[k];
	array[k] = array[high];
	array[high] = temp;
	if (array[k] != array[high])
		print_array(array, size);
	return (k);
}

/**
 * quicksort - this recursively sorts the array of integers separating into two
 * partitions, using the Lomuto quick sort
 * @array: the array of integers to sort
 * @low: index in array which will  begin partition
 * @high: index in array which will ends the partition
 * @size: amount of elements in array
 */
void quicksort(int *array, int low, int high, size_t size)
{
	int v;

	if (low < high)
	{
		v = partition(array, low, high, size);
		quicksort(array, low, v - 1, size);
		quicksort(array, v + 1, high, size);
	}
}

/**
 * quick_sort - sorting an array of integers in an ascending order with the quick
 * sort algorithm, with Lomuto partition scheme
 * @array: array of integers to sort
 * @size: amount of elements in array
 */
void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	quicksort(array, 0, (int)size - 1, size);
}
