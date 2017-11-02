#include <stdio.h> 
#include <stdlib.h> 

#define TRUE  1
#define FALSE 0 

void merge_sort (int [], int, int); 
void merge (int[], int, int, int); 
void *xcalloc (int, int); 

typedef int flag_t; 

void merge_sort (int arr[], int start_index, int end_index)
{
	int mid_index; 

	if (start_index < end_index) 
	{
		mid_index = (start_index + end_index) / 2; 
		merge_sort (arr, start_index, mid_index); 
		merge_sort (arr, mid_index+1, end_index); 
		merge (arr, start_index, mid_index, end_index); 
	}
}

void merge (int arr[], int start_index, int mid_index, int end_index) 
{
	int n1=mid_index-start_index+1, n2=end_index-mid_index; 	
	int *tmp_arr1, *tmp_arr2; 
	int cnt, k1, k2; 
	flag_t from_arr1=FALSE, from_arr2=FALSE; 

	tmp_arr1 = (int*) xcalloc (n1, sizeof (int)); 
	tmp_arr2 = (int*) xcalloc (n2, sizeof (int)); 

	for (cnt=0; cnt < n1; cnt++) 
	{
		tmp_arr1[cnt] = arr[start_index+cnt]; 
	}

	for (cnt=0; cnt < n2; cnt++) 
	{
		tmp_arr2[cnt] = arr[mid_index+1+cnt]; 
	}

	cnt=k1=k2=0; 

	while (cnt < n1+n2) 
	{
		if (tmp_arr1[k1] <= tmp_arr2[k2])
		{
			arr[start_index+cnt] = tmp_arr1[k1]; 
			k1++;
			cnt++; 
			if (k1 == n1) 
			{
				from_arr1 = TRUE; 
				break; 
			}
		}
		else
		{
			arr[start_index+cnt] = tmp_arr2[k2]; 
			k2++; 
			cnt++; 
			if (k2 == n2) 
			{
				from_arr2 = TRUE; 
				break; 
			}
		}

	}

	if (from_arr1 == TRUE)
	{
		while (k2 < n2)
		{
			arr[start_index+cnt] = tmp_arr2[k2]; 
			k2++; 
			cnt++; 
		}
	}
	else if (from_arr2 == TRUE) 
	{
		while (k1 < n1)
		{
			arr[start_index+cnt] = tmp_arr1[k1]; 
			k1++; 
			cnt++; 
		}
	}

	free (tmp_arr1); 
	free (tmp_arr2); 
}

void *xcalloc (int nr_elements, int size_per_element)
{
	void *tmp; 

	tmp = calloc (nr_elements, size_per_element); 
	if (!tmp) 
	{
		fprintf (stderr, "fatal:calloc:out of memory\n"); 
		exit (EXIT_FAILURE); 
	}

	return (tmp); 
}
