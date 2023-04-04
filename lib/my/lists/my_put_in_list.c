/*
** EPITECH PROJECT, 2022
** My put in list
** File description:
** Put element in list
*/

#include <stdlib.h>
#include "mylist.h"

int my_put_in_list(linked_list_t **list, int data)
{
    linked_list_t *element;

    element = malloc(sizeof(*element));
    element->data = data;
    element->next = *list;
    *list = element;
    return (0);
}
