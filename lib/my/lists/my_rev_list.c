/*
** EPITECH PROJECT, 2022
** My rev list
** File description:
** Reverse list
*/

#include "mylist.h"
#include <stddef.h>

void my_rev_list(linked_list_t **begin)
{
    linked_list_t *tmp = *begin;
    linked_list_t *list = NULL;
    linked_list_t *node;

    while (tmp != NULL) {
        node = tmp;
        my_put_in_list(&list, tmp->data);
        tmp = tmp->next;
        free(node);
    }
    *begin = list;
}
