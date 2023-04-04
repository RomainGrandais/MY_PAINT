/*
** EPITECH PROJECT, 2023
** Array CPY
** File description:
** copy array
*/

#include "my.h"

char **copy_array(char **array)
{
    char **new_array = malloc(sizeof(char *) * (len_array(array) + 1));
    int i = 0;

    for (; array[i] != NULL; i++)
        new_array[i] = my_strdup(array[i]);
    new_array[i] = NULL;
    return (new_array);
}
