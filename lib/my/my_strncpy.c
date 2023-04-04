/*
** EPITECH PROJECT, 2022
** My str N copy
** File description:
** Copy n characters from a string into another.
*/

int my_strlen(char const *str);

char *my_strncpy(char *dest, char const *src, int n)
{
    int i = 0;

    for (; i < n; i++)
        dest[i] = src[i];
    dest[i] = '\0';
    return (dest);
}
