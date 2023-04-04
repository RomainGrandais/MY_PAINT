/*
** EPITECH PROJECT, 2022
** My free list
** File description:
** Free list
*/

#include "mylist.h"


#include <stdio.h>

int my_free_list(linked_list_t *list)
{
    linked_list_t *node;

    while (list != NULL) {
        node = list;
        list = list->next;
        free(node);
    }
    return (0);
}
