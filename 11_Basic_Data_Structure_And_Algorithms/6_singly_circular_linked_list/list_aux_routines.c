#include <stdio.h> 
#include <stdlib.h> 
#include <assert.h> 
#include "common.h" 
#include "list_aux.h" 
#include "list.h" 

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

	while (run != lst) 
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

	while (run->next != lst) 
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
	node_t **arr; 
	node_t *run=lst->next, *run_prev=lst; 
	arr = (node_t**) get_block (2, sizeof (node_t*)); 
	
	while (run->next != lst)
	{
		run_prev = run; 
		run = run->next; 
	}

	arr[0] = run; 
	arr[1] = run_prev; 

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

	while (run->next != lst) 
	{
		run = run->next; 
	}

	return (run); 
}
