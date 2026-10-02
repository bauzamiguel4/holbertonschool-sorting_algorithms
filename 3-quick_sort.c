#include "sort.h"

/**
 * lomuto_partition - Partitions the array using Lomuto scheme
 * @array: Array to partition
 * @low: Low index
 * @high: High index
 * @size: Size of the array
 *
 * Return: Index of the pivot
 */
int lomuto_partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high];
	int i = low - 1;
	int j, tmp;

	for (j = low; j <= high - 1; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			if (i != j)
			{
				tmp = array[i];
				array[i] = array[j];
				array[j] = tmp;
				print_array(array, size);
			}
		}
	}
	if (array[i + 1] > array[high])
	{
		tmp = array[i + 1];
		array[i + 1] = array[high];
		array[high] = tmp;
		print_array(array, size);
	}
	return (i + 1);
}

/**
 * quick_sort_rec - Recursive helper for quick sort
 * @array: Array to sort
 * @low: Low index
 * @high: High index
 * @size: Size of the array
 */
void quick_sort_rec(int *array, int low, int high, size_t size)
{
	int pi;

	if (low < high)
	{
		pi = lomuto_partition(array, low, high, size);
		quick_sort_rec(array, low, pi - 1, size);
		quick_sort_rec(array, pi + 1, high, size);
	}
}

/**
 * quick_sort - Sorts an array of integers in ascending order
 *              using Quick sort algorithm (Lomuto partition)
 * @array: Array to sort
 * @size: Size of the array
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quick_sort_rec(array, 0, size - 1, size);
}
