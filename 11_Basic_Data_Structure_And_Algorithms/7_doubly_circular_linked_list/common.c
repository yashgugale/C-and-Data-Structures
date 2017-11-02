#include <stdio.h> 
#include <stdlib.h> 
#include "common.h" 

void *get_block (int nr_elements, int size_per_element) 
{
	void *tmp; 

	tmp = calloc (nr_elements, size_per_element); 
	if (tmp == NULL) 
	{
		fprintf (stderr, "calloc:fatal:out of memory\n"); 
		exit (EXIT_FAILURE); 
	}

	return (tmp); 
}

