#include <stdio.h> 
#include <stdlib.h> 
#include "list_aux.h"
#include "list.h" 

list_t *create_list (void) 
{
	return ((list_t*)get_node (0)); 
}

result_t insert_beg (list_t *lst, data_t new_data) 
{
	node_t *new_node = get_node (new_data); 
	g_insert (lst, new_node); 
	return (SUCCESS); 
}

result_t insert_end (list_t *lst, data_t new_data) 
{
	node_t *new_node = get_node (new_data); 
	node_t *run = lst; 

	while (run->next != NULL) 
	{
		run = run->next; 
	}

	g_insert (run, new_node); 

	return (SUCCESS); 
}

result_t insert_after_data (list_t *lst, data_t e_data, 
			    data_t new_data)
{
	node_t *e_node = search_node (lst, e_data); 
	node_t *new_node; 

	if (e_node != NULL) 
	{
		new_node = get_node (new_data); 
		g_insert (e_node, new_node); 
		return (SUCCESS); 
	}
	else
	{
		return (DATA_NOT_FOUND); 
	}
}

result_t insert_before_data (list_t *lst, data_t e_data, 
		             data_t new_data) 
{
	node_t *e_node = search_node (lst, e_data); 
	node_t *new_node; 

	if (e_node != NULL) 
	{
		new_node = get_node (new_data); 
		g_insert (e_node->prev, new_node); 
		return (SUCCESS); 
	}
	else
	{
		return (DATA_NOT_FOUND); 
	}
}

result_t del_beg (list_t *lst)
{
	if (is_empty (lst) == TRUE) 
	{
		return (LIST_EMPTY); 
	}

	g_delete (lst->next); 
	return (SUCCESS); 
}

result_t del_end (list_t *lst) 
{
	node_t *run=lst; 
	if (is_empty (lst) == TRUE) 
	{
		return (LIST_EMPTY); 
	}
	
	while (run->next != NULL) 
	{
		run = run->next; 
	}
	
	g_delete (run); 
	return (SUCCESS); 
}

result_t del_data (list_t *lst, data_t e_data) 
{
	node_t *e_node = search_node (lst, e_data); 
	if (e_node != NULL) 
	{
		g_delete (e_node); 
		return (SUCCESS); 
	}
	else
	{
		return (DATA_NOT_FOUND); 
	}
}

result_t find (list_t *lst, data_t s_data) 
{
	node_t *e_node = search_node (lst, s_data); 

	if (e_node != NULL) 
	{
		return (TRUE); 
	}
	else
	{
		return (FALSE); 
	}
}

result_t examine_and_delete_beg (list_t *lst, data_t *p_object) 
{
	if (is_empty (lst) == TRUE) 
	{
		return (LIST_EMPTY); 
	}

	*p_object = lst->next->data; 
	g_delete (lst->next); 

	return (SUCCESS); 
}

result_t examine_and_delete_end (list_t *lst, data_t *p_object) 
{
	node_t *run=lst; 

	if (is_empty (lst) == TRUE) 
	{
		return (LIST_EMPTY); 
	}

	while (run->next != NULL) 
	{
		run = run->next; 
	}

	*p_object = run->data; 
	g_delete (run); 

	return (SUCCESS); 

}

result_t examine_beg (list_t *lst, data_t *p_object) 
{
	if (is_empty (lst) == TRUE) 
	{
		return (LIST_EMPTY); 
	}

	*p_object = lst->next->data; 

	return (SUCCESS); 
}

result_t examine_end (list_t *lst, data_t *p_object) 
{
	node_t *run=lst; 

	if (is_empty (lst) == TRUE) 
	{
		return (LIST_EMPTY); 
	}

	while (run->next != NULL)
	{
		run = run->next; 
	}

	*p_object = run->data; 

	return (SUCCESS); 
}

result_t is_empty (list_t *lst) 
{
	if (lst->next == NULL) 
	{
		return (TRUE); 
	}
	else
	{
		return (FALSE); 
	}
}

len_t length (list_t *lst) 
{
	len_t len; 
	node_t *run=lst->next; 

	while (run != NULL) 
	{
		len++; 
		run = run->next; 
	}

	return (len); 
}

void display (list_t *lst) 
{
	node_t *run=lst->next; 
	
	printf ("[beg]<->"); 

	while (run != NULL) 
	{
		printf ("[%d]<->", run->data); 
		run = run->next; 
	}
	
	printf ("[end]\n"); 
}

result_t destroy_list (list_t **pp_lst)
{
	list_t *lst = *pp_lst; 
	node_t *run=lst->next, *run_next; 

	while (run != NULL) 
	{
		run_next = run->next; 
		free (run); 
		run = run_next; 
	}

	free (lst); 
	*pp_lst = NULL; 

	return (SUCCESS); 
}
