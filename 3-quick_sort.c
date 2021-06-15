#include "sort.h"

/**
 * 
 * 
 */
void quick_sort(int *array, size_t size)
{
	size_t lo = 0;
	size_t hi = size - 1;

	if (size < 2 || array == NULL)
		return;

	quicksort(array, lo, hi, size);
}

void quicksort(int *array, size_t lo, size_t hi, size_t size)
{
	int p;

	if (lo < hi)
	{
		p = lomuto_partition(array, lo, hi, size);
		quicksort(array, lo, p - 1, size);
		quicksort(array, p + 1, hi, size);
	}
}

int lomuto_partition(int *array, size_t lo, size_t hi, size_t size)
{
	size_t i, j;
	int pivot;

	i = lo;
	pivot = array[hi];

	for (j = lo; j < hi; j++)
	{
		if (array[j] < pivot)
		{
			if (i != j)
			{
				swap(&array, i, j);
				print_array(array, size);
			}
			i++;
		}
	}

	if (array[hi] < array[i])
	{
		swap(&array, i, hi);
		print_array(array, size);
	}

	return (i);
}

void swap(int **array, size_t i, size_t j)
{
	int tmp;

	tmp = (*array)[i];
	(*array)[i] = (*array)[j];
	(*array)[j] = tmp;
}
