/*
** EPITECH PROJECT, 2022
** My str N cat
** File description:
** concatenate two strings (n firsts chars).
*/

int my_strlen(char const *str);

char *my_strncat(char *dest, char const *src, int nb)
{
    int i = my_strlen(dest);

    for (int j = 0; j < nb; j++) {
        dest[i] = src[j];
        i++;
    }
    return (dest);
}
