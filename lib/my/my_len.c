/*
** EPITECH PROJECT, 2022
** My LEN
** File description:
** LEN....
*/

#include <stddef.h>

int len_array(char **array)
{
    int n = 0;

    for (int i = 0; array[i] != NULL; i++)
        n++;
    return (n);
}

int len_str(char *str)
{
    int n = 0;

    for (int i = 0; str[i] != '\0'; i++)
        n++;
    return (n);
}
