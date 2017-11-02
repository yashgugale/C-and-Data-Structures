#include <stdio.h> 
#include <stdlib.h> 
#include "sll.h" 

list_t *create_list (void) 
{
	return ((list_t*)get_block (1, sizeof (list_t))); 
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
	node_t *target   = get_last_node (lst); 
	g_insert (target, new_node); 
	return (SUCCESS); 
}

result_t insert_after_data (list_t *lst, data_t e_data, 
		            data_t new_data) 
{
	node_t *new_node; 
	node_t *target = search_node (lst, e_data); 
	if (target == NULL) 
	{
		return (DATA_NOT_FOUND); 
	}	
	else
	{
		new_node = get_node (new_data); 
		g_insert (target, new_node); 
		return (SUCCESS); 		
	}
}

result_t insert_before_data (list_t *lst, data_t e_data, 
			     data_t new_data) 
{
	node_t *new_node; 
	node_t *target = search_back_node (lst, e_data); 

	if (target == NULL) 
	{
		return (DATA_NOT_FOUND); 
	}
	else 
	{
		new_node = get_node (new_data); 
		g_insert (target, new_node); 
		return (SUCCESS); 
	}
}

result_t del_beg (list_t *lst) 
{
	result_t rs; 

	rs = is_empty (lst); 
	if (rs == TRUE) 
	{
		return (LIST_EMPTY); 
	}
	else 
	{
		g_delete (lst->next, lst); 
		return (SUCCESS); 
	}
}

result_t del_end (list_t *lst) 
{
	result_t rs; 
	node_t *target=lst->next, *target_back=lst; 

	rs = is_empty (lst); 
	if (rs == TRUE) 
	{
		return (LIST_EMPTY); 
	}
	else 
	{
		while (target->next != NULL) 
		{
			target_back = target; 
			target = target->next; 
		}

		g_delete (target, target_back); 
		return (SUCCESS); 
	}
}

result_t del_data (list_t *lst, data_t data) 
{
	node_t *target, *target_back; 

	target      = search_node (lst, data); 
	if (target == NULL) 
	{
		return (DATA_NOT_FOUND); 
	}
	else
	{
		target_back = search_back_node (lst, data); 
		g_delete (target, target_back); 
		return (SUCCESS); 
	}
}

result_t examine_and_delete_beg (list_t *lst, data_t *p_object) 
{
	if (is_empty (lst) == TRUE) 
	{
		return (LIST_EMPTY); 
	}
	
	*p_object = lst->next->data; 
	g_delete (lst->next, lst); 

	return (SUCCESS); 
		
}

result_t examine_and_delete_end (list_t *lst, data_t *p_object) 
{
	node_t **arr; 

	if (is_empty (lst) == TRUE)
	{
		return (LIST_EMPTY); 
	}	

	arr = get_end_pointers (lst); 
	*p_object = arr[0]->data; 
	g_delete (arr[0], arr[1]); 
	free (arr); 

	return (SUCCESS); 
}

result_t examine_beg (list_t *lst, data_t *p_object) 
{
	node_t *tmp; 

	if (is_empty (lst) == TRUE) 
	{
		return (LIST_EMPTY); 
	}
	
	*p_object = lst->next->data; 

	return (SUCCESS); 
}

result_t examine_end (list_t *lst, data_t *p_object) 
{
	node_t *tmp; 

	if (is_empty (lst) == TRUE) 
	{
		return (LIST_EMPTY); 
	}
	
	tmp = get_last_node (lst); 
	*p_object = tmp->data; 

	return (SUCCESS); 
}

result_t find (list_t *lst, data_t s_data) 
{
	node_t *tmp = search_node (lst, s_data); 

	if (tmp != NULL) 
	{
		return (TRUE); 
	}
	else
	{
		return (FALSE); 
	}
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
	len_t cnt=0; 
	node_t *run = lst->next; 

	while (run != NULL) 
	{
		cnt++; 
		run = run->next; 
	}

	return (cnt); 
}

void display (list_t *lst) 
{
	node_t *run=lst->next; 

	printf ("[begin]->"); 

	while (run != NULL) 
	{
		printf ("[%d]->", run->data); 
		run = run->next; 
	}

	printf ("[end]\n"); 
}

result_t destroy_list (list_t **pp_list)
{
	list_t *lst = *pp_list; 
	node_t *run_n, *run; 

	run = lst->next; 
	
	while (run != NULL) 
	{
		run_n = run->next; 
		free (run); 
		run   = run_n; 
	}

	free (lst); 
	*pp_list = NULL; 
	
	return (SUCCESS); 
}
