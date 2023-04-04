/*
** EPITECH PROJECT, 2022
** My merge
** File description:
** Merge two lists (work only with SORTED lists)
*/

#include "mylist.h"
#include <stddef.h>

static int append_last_data(int nb_elements,
linked_list_t *begin2, linked_list_t **list)
{
    linked_list_t *node;

    if (nb_elements != my_list_size(begin2)) {
        node = begin2;
        for (int i = 0; i < nb_elements; i++)
            node = node->next;
        while (node != NULL) {
            my_put_in_list(list, node->data);
            node = node->next;
        }
    }
    return (0);
}

static int compare_and_put(linked_list_t **list, linked_list_t *node,
linked_list_t *node2, int (*cmp)())
{
    if (cmp(node->data, node2->data) > 0) {
        my_put_in_list(list, node2->data);
        return (1);
    }
    return (0);
}

void my_merge(linked_list_t **begin1, linked_list_t *begin2, int (*cmp)())
{
    linked_list_t *node = *begin1;
    linked_list_t *node2 = begin2;
    linked_list_t *list = NULL;
    int nb_elements = 0;

    for (int i = 0; node != NULL; i++) {
        node2 = begin2;
        for (int j = 0; j < i - 2; j++)
            node2 = node2->next;
        while (node2 != NULL) {
            nb_elements += compare_and_put(&list, node, node2, cmp);
            node2 = node2->next;
        }
        my_put_in_list(&list, node->data);
        node = node->next;
    }
    append_last_data(nb_elements, begin2, &list);
    my_rev_list(&list);
    *begin1 = list;
}
