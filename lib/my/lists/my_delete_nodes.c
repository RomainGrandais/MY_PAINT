/*
** EPITECH PROJECT, 2022
** My delete nodes
** File description:
** Delete node
*/

#include "mylist.h"
#include <stddef.h>
#include <stdlib.h>

int my_delete_nodes(linked_list_t **begin, void const *data_ref, int (*cmp)())
{
    linked_list_t *list;
    linked_list_t *node = *begin;
    linked_list_t *trash;

    list = NULL;
    while (node != NULL) {
        if (cmp(node->data, data_ref) == 0) {
            trash = node;
            node = node->next;
            free(trash);
        }
        my_put_in_list(&list, node->data);
        node = node->next;
    }
    my_rev_list(&list);
    *begin = list;
    return (0);
}
