/*
** EPITECH PROJECT, 2022
** Merge Stringss
** File description:
** Merge 2 strings and malloc
*/

#include <stddef.h>
#include <stdlib.h>

int my_strlen(char const *str);
char *my_strcpy(char *dest, char const *src);
char *my_strcat(char *dest, char const *src);

char *merge_strings(char *str1, char *str2)
{
    int size = (my_strlen(str1) + my_strlen(str2));
    char *str = malloc(sizeof(char) * (size + 1));

    if (str == NULL)
        return (NULL);
    str = my_strcpy(str, str1);
    my_strcat(str, str2);
    str[size] = '\0';
    return (str);
}
