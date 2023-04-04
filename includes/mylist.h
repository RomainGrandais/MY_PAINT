/*
** EPITECH PROJECT, 2022
** MyLIST
** File description:
** Linked list structure
*/

#ifndef MYLIST_H_
    #define MYLIST_H_

    #include <stddef.h>
    #include <stdlib.h>

typedef struct linked_list {
    int data;
    struct linked_list *next;
} linked_list_t;

void my_add_in_sorted_list(linked_list_t **begin, void *data, int (*cmp)());
int my_put_in_list(linked_list_t **list, int data);
int my_show_list(linked_list_t *list);
int my_apply_on_matching_nodes(linked_list_t *begin, int (*f)(),
void const *data_ref, int (*cmp)());
int my_apply_on_nodes(linked_list_t *begin, int (*f)(void *));
void my_concat_list(linked_list_t **begin1, linked_list_t *begin2);
int my_delete_nodes(linked_list_t **begin, void const *data_ref, int (*cmp)());
linked_list_t *my_find_node(linked_list_t const *begin,
void const *data_ref, int (*cmp)());
int my_list_size(linked_list_t const *begin);
linked_list_t *my_params_to_list(int ac, char * const *av);
void my_rev_list(linked_list_t **begin);
void my_sort_list(linked_list_t **begin, int (*cmp)());
int my_is_in_list(linked_list_t *list, void *value, int (*cmp)());
int my_free_list(linked_list_t *list);
int list_get_element(linked_list_t *list, int index);
int pop(linked_list_t **list);

#endif /* MYLIST_H_ */
