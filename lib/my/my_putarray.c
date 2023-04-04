/*
** EPITECH PROJECT, 2022
** My Put Array
** File description:
** Display Array
*/

#include <stddef.h>

int my_putstr(char const *str);

int my_put_array(char **array)
{
    for (int i = 0; array[i] != NULL; i++) {
        my_putstr(array[i]);
        my_putstr("\n");
    }
    return (0);
}
