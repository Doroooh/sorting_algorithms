#include "sorting.h"

/**
 * split - divides an array into two parts based on a pivot value, and then
 * rearranges the elements such that elements smaller than the pivot are on
 * the left and elements greater than or equal to the pivot are on the right.
 * @arr: array of integers to be sorted
 * @start: starting index of the partition
 * @end: ending index of the partition
 * @size: size of the array
 * Return: the index of the pivot element after partitioning
 */
int split(int *arr, int start, int end, size_t size)
{
	int i, j, pivot, temp;

	pivot = arr[end];
	i = start;
	for (j = start; j < end; j++)
	{
		if (arr[j] < pivot)
		{
			temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
			if (arr[i] != arr[j])
				print_array(arr, size);
			i++;
		}
	}
	temp = arr[i];
	arr[i] = arr[end];
	arr[end] = temp;
	if (arr[i] != arr[end])
		print_array(arr, size);
	return (i);
}

/**
 * recursive_sort - recursively sorts an array of integers using the
 * quicksort algorithm
 * @arr: array of integers to be sorted
 * @start: starting index of the partition
 * @end: ending index of the partition
 * @size: size of the array
 */
void recursive_sort(int *arr, int start, int end, size_t size)
{
	int pivot;

	if (start < end)
	{
		pivot = split(arr, start, end, size);
		recursive_sort(arr, start, pivot - 1, size);
		recursive_sort(arr, pivot + 1, end, size);
	}
}

/**
 * quick_sort - sorts an array of integers in ascending order using the
 * quicksort algorithm
 * @arr: array of integers to be sorted
 * @size: size of the array
 */
void quick_sort(int *arr, size_t size)
{
	if (!arr || size < 2)
		return;

	recursive_sort(arr, 0, (int)size - 1, size);
}
