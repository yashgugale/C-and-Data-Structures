#ifndef _LIST_H 
#define _LIST_H 

#define SUCCESS		0 
#define FAILURE		1 
#define DATA_NOT_FOUND  2 
#define LIST_EMPTY	3
#define TRUE		0
#define FALSE		1 

struct _node; 
typedef struct _node node_t; 
typedef struct _node list_t; 
typedef int data_t; 
typedef int result_t; 
typedef int len_t; 

struct _node 
{
	data_t data; 
	struct _node *next; 
}; 

/* list interface routines */ 
/* Creation */ 
list_t *create_list (void); 
/* Insert routines */ 
result_t insert_beg (list_t *lst, data_t new_data); 
result_t insert_end (list_t *lst, data_t new_data); 
result_t insert_after_data (list_t *lst, data_t e_data, 
			    data_t new_data); 
result_t insert_before_data (list_t *lst, data_t e_data, 
		             data_t new_data); 
/* Delete routines */ 
result_t del_beg (list_t *lst); 
result_t del_end (list_t *lst); 
result_t del_data (list_t *lst, data_t e_data); 

/* Examine and delete */ 
result_t examine_and_delete_beg (list_t *lst, data_t *p_object); 
result_t examine_and_delete_end (list_t *lst, data_t *p_object); 

/* Examine */ 
result_t examine_beg (list_t *lst, data_t *p_object); 
result_t examine_end (list_t *lst, data_t *p_object); 

/* Membership testing */ 
result_t find (list_t *lst, data_t s_data); 

/* Miscallaneous */ 
result_t is_empty (list_t *lst); 
void display (list_t *lst); 
result_t sort (list_t *lst); 
len_t length (list_t *lst); 
/* Destruction */ 
result_t destroy_list (list_t **pp_lst); 

/* Inter list operations */ 
list_t *concat (list_t *lst1, list_t *lst2); 
list_t *merge (list_t *lst1, list_t *lst2); 

#endif /* _LIST_H */ 
