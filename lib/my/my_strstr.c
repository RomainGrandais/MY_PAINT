/*
** EPITECH PROJECT, 2022
** My STR STR
** File description:
** Find the first occurence of the substring in the string.
*/

#include <stddef.h>

int my_strlen(char const *str);

char *my_strstr(char *str , char const *to_find)
{
    int j = 0;
    int n = my_strlen(to_find);
    int m;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == to_find[j] && j == 0)
            m = i;
        if (str[i] == to_find[j] && j == n - 1)
            return (&str[m]);
        if (str[i] == to_find[j])
            j++;
    }
    return (NULL);
}
