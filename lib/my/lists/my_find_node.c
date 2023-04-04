/*
** EPITECH PROJECT, 2022
** My find Node
** File description:
** Return address of the first node.
*/

#include "mylist.h"
#include <stddef.h>

linked_list_t *my_find_node(linked_list_t const *begin,
void const *data_ref, int (*cmp)())
{
    while (begin != NULL) {
        if (cmp(begin->data, data_ref) == 0)
            return (linked_list_t *)(begin);
        begin = begin->next;
    }
    return (NULL);
}
