#include <stdio.h> 
#include <stdlib.h> 
#include "common.h" 
#include "list_aux.h" 
#include "list.h" 


node_t *search_node (list_t *lst, data_t s_data) 
{
	node_t *run=lst->next; 

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

void g_insert (node_t *target, node_t *new_node) 
{
	new_node->next = target->next; 
	new_node->prev = target; 
	target->next = new_node; 
	if (target->next != NULL)
	{
		target->next->prev = new_node; 
	}
}

void g_delete (node_t *target)
{
	target->prev->next = target->next; 
	if (target->next != NULL) 
	{
		target->next->prev = target->prev; 
	}	
	free (target); 
}

node_t *get_node (data_t data) 
{
	node_t *node = (node_t*)get_block (1, sizeof (node_t));
	node->data   = data; 
	return (node); 	
}
