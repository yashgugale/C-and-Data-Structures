static void quick_sort (long int *arr, long int start_index, 
		 	long int end_index); 
static long int partition (long int *arr, long int start_index, 
		 	   long int end_index); 

void sort (long int *arr, long int nr_elements) 
{
	quick_sort (arr, 0, nr_elements-1); 	
}

static void quick_sort (long int *arr, long int start_index, 
		 	long int end_index) 
{
	long int index; 

	if (start_index < end_index) 
	{
		index = partition (arr, start_index, end_index); 
		quick_sort (arr, start_index, index-1); 
		quick_sort (arr, index+1, end_index); 
	}	
}

static long int partition (long int *arr, long int start_index, long int end_index) 
{
	long int x, i, j, tmp; 

	x = arr[end_index]; 
	i = start_index-1; 

	for (j=start_index; j < end_index; j++) 
	{
		if (arr[j] <= x) 
		{
			i = i + 1; 
			tmp = arr[i]; 
			arr[i] = arr[j]; 
			arr[j] = tmp; 
		}
	}

	tmp 		= arr[i+1]; 
	arr[i+1] 	= arr[end_index]; 
	arr[end_index]  = tmp; 

	return (i+1); 
}
