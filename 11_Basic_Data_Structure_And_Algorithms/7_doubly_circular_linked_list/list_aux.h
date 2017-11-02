#ifndef _LIST_AUX_H 
#define _LIST_AUX_H 

#include "list.h" 

node_t *search_node (list_t *lst, data_t s_data); 
void   g_insert (node_t *target, node_t *new_node); 
void   g_delete (node_t *target); 
node_t *get_node (data_t data); 
node_t *get_last_node (list_t *lst); 

/* Not required for doubly linked list */ 
node_t *search_back_node (list_t *lst, data_t s_data); 
node_t **get_end_pointers (list_t *lst); 

#endif /* _LIST_AUX_H */ 
