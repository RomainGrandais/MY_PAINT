/*
** EPITECH PROJECT, 2022
** Concat two lists.
** File description:
** Concat begin2 in begin1.
*/

#include "mylist.h"
#include <stddef.h>

void my_concat_list(linked_list_t **begin1, linked_list_t *begin2)
{
    while (begin2 != NULL) {
        my_rev_list(begin1);
        my_put_in_list(begin1, begin2->data);
        my_rev_list(begin1);
        begin2 = begin2->next;
    }
}
