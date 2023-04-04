/*
** EPITECH PROJECT, 2022
** My POP
** File description:
** pop function
*/

#include <stdlib.h>
#include "mylist.h"

int pop(linked_list_t **list)
{
    linked_list_t *node = *list;
    int data = node->data;

    *list = node->next;
    free(node);
    return (data);
}
