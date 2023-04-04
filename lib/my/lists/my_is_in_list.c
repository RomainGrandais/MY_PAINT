/*
** EPITECH PROJECT, 2022
** My is in list
** File description:
** Check if value is in list.
*/

#include "mylist.h"
#include <stddef.h>

int my_is_in_list(linked_list_t *list, void *value, int (*cmp)())
{
    linked_list_t *node = list;

    while (node != NULL) {
        if (cmp(node->data, value))
            return (1);
        node = node->next;
    }
    return (0);
}
