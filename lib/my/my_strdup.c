/*
** EPITECH PROJECT, 2022
** My str DUP
** File description:
** allocate memory and return this string
*/

#include <stdlib.h>
#include <stddef.h>

int my_strlen(char const *str);

char *my_strdup(char const *src)
{
    int len = my_strlen(src);
    char *str = malloc(sizeof(char) * (len + 1));
    int i = 0;

    if (str == NULL)
        return (NULL);
    for (; i < len; i++)
        str[i] = src[i];
    str[i] = '\0';
    return (str);
}
