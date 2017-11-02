#include <stdio.h> 
#include <stdlib.h> 
#include <assert.h> 
#include "sll.h" 

void g_insert (node_t *target, node_t *new_node) 
{
	new_node->next = target->next; 
	target->next   = new_node; 
}

void g_delete (node_t *target, node_t *back_ptr) 
{
	back_ptr->next = target->next; 
	free (target); 	
}

node_t *search_node (list_t *lst, data_t s_data) 
{
	node_t *run = lst->next; 

	while (run != NULL) 
	{
		if (run->data == s_data) 
		{
			return (run); 
		}	
		else
		{
			run = run->next; 
		}
	}

	return (NULL); 
}

node_t *search_back_node (list_t *lst, data_t s_data) 
{
 	node_t *run=lst; 

	while (run->next != NULL) 
	{
		if (run->next->data == s_data) 
		{
			return (run); 
		}
		else
		{
			run = run->next; 
		}
	}

	return (NULL); 
}

node_t **get_end_pointers (list_t *lst) 
{
	node_t **arr = (node_t**) get_block (2, sizeof (node_t*)); 
	node_t *run=lst->next, *run_back=lst; 

	while (run->next != NULL) 
	{
		run_back = run; 
		run = run->next; 
	}

	arr[0] = run; 
	arr[1] = run_back; 

	return (arr); 
}

node_t *get_node (data_t data) 
{
	node_t *tmp = (node_t*) get_block (1, sizeof (node_t)); 
	tmp->data = data; 
	return (tmp); 
}

node_t *get_last_node (list_t *lst) 
{
	node_t *run = lst; 

	while (run->next != NULL) 
	{
		run = run->next; 
	}

	return (run); 
}

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
