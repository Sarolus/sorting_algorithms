#include "sort.h"

/**
 * selection_sort - sorts an array of integers in ascending order using the Selection sort algorithm
 * 
 * @array: array of int
 * @size: size of the array
 * 
 * Return: void
 */

void selection_sort(int *array, size_t size)
{
	size_t i, j = 0, iMin;
	int tmp;

	if (size < 2)
		return;
	
	for (i = 0; i < size - 1; i++)
	{
		iMin = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[iMin])
			iMin = j;
		}
		tmp = array[i];
		array[i] = array[iMin];
		array[iMin] = tmp;
		if (iMin != i)
			print_array(array, size);
	}
}
