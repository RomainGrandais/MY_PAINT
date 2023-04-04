/*
** EPITECH PROJECT, 2022
** My Get element
** File description:
** my_get_element
*/

#include "mylist.h"

int list_get_element(linked_list_t *list, int index)
{
    linked_list_t *node = list;
    int n = 0;

    while (node != NULL) {
        if (n == index)
            return (node->data);
        node = node->next;
        n++;
    }
    return (0);
}
