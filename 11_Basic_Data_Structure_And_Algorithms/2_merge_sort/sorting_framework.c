#include <stdio.h> 
#include <stdlib.h> 

#define CAP 1000000

void *xcalloc (int, int); 
void input (int[], int); 
void output (int[], int); 
void sort (int[], int); 
void merge_sort (int[], int, int); 

int main (int argc, char *argv[]) 
{
	int *arr; 
	int nr_elements; 

	if (argc != 2) 
	{
		fprintf (stderr, "usage:%s nr_elements\n", argv[0]); 
		exit (EXIT_FAILURE); 
	}

	nr_elements = atoi (argv[1]); 
	arr = xcalloc (nr_elements, sizeof (int)); 
	input (arr, nr_elements); 
	sort (arr, nr_elements); 
	output (arr, nr_elements); 
	
	return (0); 
}

void input (int arr[], int nr_elements)
{
	int cnt; 

	for (cnt=0; cnt < nr_elements; cnt++) 
	{
		arr[cnt] = rand () % CAP; 
	}
}

void output (int arr[], int nr_elements)
{
	int cnt; 

	for (cnt=0; cnt < nr_elements; cnt++) 
	{
		fprintf (stdout, "arr[%d]:%d\n", cnt, arr[cnt]); 
	}
}

void sort (int arr[], int nr_elements) 
{
	merge_sort (arr, 0, nr_elements-1); 
}
