#include <stdio.h> 
#include <stdlib.h> 
#include "list.h" 

int main (void) 
{
	list_t *lst1; 
	result_t rs; 
	data_t data; 
	len_t len; 
	int cnt; 

	lst1 = create_list (); 
	
	if (is_empty (lst1) == TRUE)
	{
		printf ("list is empty\n"); 
		display (lst1); 
	}

	rs = del_beg (lst1); 
	if (rs == LIST_EMPTY) 
	{
		printf ("del_beg:Cannot delete from empty list\n"); 
	}

	rs = del_end (lst1); 
	if (rs == LIST_EMPTY) 
	{
		printf ("del_end:Cannot delete from empty list\n"); 
	}

	rs = del_data (lst1, 1000); 
	if (rs == DATA_NOT_FOUND)
	{
		printf ("del_data:Data not found\n"); 
	}

	rs = examine_and_delete_beg (lst1, &data);  
	if (rs == LIST_EMPTY)
	{
		printf ("examine_and_delete_beg:list is empty\n"); 
	}

	rs = examine_and_delete_end (lst1, &data); 
	if (rs == LIST_EMPTY) 
	{
		printf ("examine_and_delete_beg:list is empty\n"); 
	}

	rs = examine_beg (lst1, &data); 
	if (rs == LIST_EMPTY) 
	{
		printf ("examine_beg:list is empty\n"); 
	}

	rs = examine_end (lst1, &data); 
	if (rs == LIST_EMPTY) 
	{
		printf ("examine_end:list is empty\n"); 
	}

	for (cnt=0; cnt < 5; cnt++) 
	{
		rs = insert_beg (lst1, cnt); 
		if (rs != SUCCESS) 
		{
			printf ("insert_beg:Error\n"); 
			exit (EXIT_FAILURE); 
		}
	} 
	display (lst1); 

	for (cnt=5; cnt < 10; cnt++) 
	{
		rs = insert_end (lst1, cnt); 
		if (rs != SUCCESS)
		{
			printf ("insert_end:Error\n"); 
			exit (EXIT_FAILURE); 
		}
	}

	display (lst1); 

	rs = insert_after_data (lst1, 0, 100); 
	if (rs != SUCCESS)
	{
		printf ("insert_after_data:Error\n"); 
		exit (EXIT_FAILURE); 
	}
	
	display (lst1); 

	rs = insert_before_data (lst1, 0, 200); 
	if (rs != SUCCESS) 
	{
		printf ("insert_before_data:Error\n"); 
		exit (EXIT_FAILURE); 
	}
	display (lst1); 

	rs = insert_before_data (lst1, 4, 400); 
	if (rs != SUCCESS) 
	{
		printf ("insert_before_data:Error\n"); 
		exit (EXIT_FAILURE); 
	}
	display (lst1); 

	rs = insert_after_data (lst1, 9, 900); 
	if (rs != SUCCESS) 
	{
		printf ("insert_after_data:Error\n"); 
		exit (EXIT_FAILURE); 
	}
	display (lst1); 

	rs = insert_after_data (lst1, 1000, 2000); 
	if (rs == DATA_NOT_FOUND) 
	{
		printf ("insert_after_data:Data not found\n"); 
	}

	rs = insert_before_data (lst1, 1000, 2000); 
	if (rs == DATA_NOT_FOUND)
	{
		printf ("insert_before_data:Data not found\n"); 
	}
	
	if (is_empty (lst1) == FALSE) 
	{
		printf ("lst1 is not empty\n"); 
	}

	rs = del_beg (lst1); 
	if (rs != SUCCESS) 
	{
		printf ("del_beg:Error\n"); 
		exit (EXIT_FAILURE); 
	}	
	display (lst1); 

	rs = del_end (lst1); 
	if (rs != SUCCESS)
	{
		printf ("del_end:Error\n"); 
		exit (EXIT_FAILURE); 
	}
	display (lst1); 

	rs = del_data (lst1, 0); 
	if (rs != SUCCESS)
	{
		printf ("del_data:Error\n");
		exit (EXIT_FAILURE); 
	}
	display (lst1); 

	rs = del_data (lst1, 2000); 
	if (rs == DATA_NOT_FOUND) 
	{
		printf ("del_data:Data not found\n"); 
	}
	
	rs = examine_and_delete_beg (lst1, &data);  
	if (rs == SUCCESS)
	{
		printf ("examine_and_delete_beg:%d\n", data); 
	}

	rs = examine_and_delete_end (lst1, &data); 
	if (rs == SUCCESS) 
	{
		printf ("examine_and_delete_beg:%d\n", data); 
	}

	rs = examine_beg (lst1, &data); 
	if (rs == SUCCESS) 
	{
		printf ("examine_beg:%d\n", data); 
	}

	rs = examine_end (lst1, &data); 
	if (rs == SUCCESS) 
	{
		printf ("examine_end:%d\n", data); 
	}

	rs = find (lst1, 4); 
	if (rs == TRUE)
	{
		printf ("4 is present in lst1\n"); 
	}

	rs = find (lst1, 3000); 
	if (rs == FALSE)
	{
		printf ("3000 is not present in lst1\n"); 
	}

	len = length (lst1); 
	printf ("len=%d\n", len); 

	while (is_empty (lst1) != TRUE) 
	{
		rs = del_beg (lst1); 
		if (rs != SUCCESS) 
		{
			printf ("del_beg:Error\n"); 
			exit (EXIT_FAILURE); 
		}
	}
	display (lst1); 

	rs = destroy_list (&lst1); 
	if (rs != SUCCESS && lst1 != NULL) 
	{
		printf ("destroy_list:Error\n"); 
		exit (EXIT_FAILURE); 
	}
	else 
	{
		printf ("List is destroyed successfully\n"); 
	}

	exit (EXIT_SUCCESS); 	
}
