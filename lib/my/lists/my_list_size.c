/*
** EPITECH PROJECT, 2022
** My list size
** File description:
** Return the nb of elements.
*/

#include "mylist.h"
#include <stddef.h>

int my_list_size(linked_list_t const *begin)
{
    linked_list_t const *tmp;
    int n = 0;

    tmp = begin;
    for (; tmp != NULL; n++)
        tmp = tmp->next;
    return (n);
}
