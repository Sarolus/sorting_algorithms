#include "sort.h"

/**
 * quick_sort - sorts an array of integers in ascending
 * order using the Quick sort Algorithm.
 * @array: array of int
 * @size: size of the array
 */
void quick_sort(int *array, size_t size)
{
	ssize_t lo = 0;
	ssize_t hi = size - 1;

	if (size < 2 || array == NULL)
		return;

	quicksort(array, lo, hi, size);
}

/**
 * quicksort - Quick sort algorithm using the lomuto
 * partition.
 * @array: array of int
 * @lo: lowest index of the partition
 * @hi: highest index of the partition
 * @size: size of the array
 */
void quicksort(int *array, ssize_t lo, ssize_t hi, size_t size)
{
	int p;

	if (lo < hi)
	{
		p = lomuto_partition(array, lo, hi, size);
		quicksort(array, lo, p - 1, size);
		quicksort(array, p + 1, hi, size);
	}
}

/**
 * lomuto_partition - Lomuto partition calling the swap
 * function.
 * @array: array of int
 * @lo: lowest index of the partition
 * @hi: highest index of the partition
 * @size: size of the array
 * Return: Return the index.
 */
int lomuto_partition(int *array, ssize_t lo, ssize_t hi, size_t size)
{
	ssize_t i, j;
	int pivot;

	i = lo;
	pivot = array[hi];

	for (j = lo; j < hi; j++)
	{
		if (array[j] < pivot)
		{
			if (i != j)
			{
				swap(array, i, j);
				print_array(array, size);
			}
			i++;
		}
	}

	if (array[hi] < array[i])
	{
		swap(array, i, hi);
		print_array(array, size);
	}

	return (i);
}

/**
 * swap - swap two values.
 * @array: array of int
 * @i: first value
 * @j: second value
 */
void swap(int *array, ssize_t i, ssize_t j)
{
	int tmp;

	tmp = array[i];
	array[i] = array[j];
	array[j] = tmp;
}
