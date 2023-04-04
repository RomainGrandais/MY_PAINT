/*
** EPITECH PROJECT, 2022
** My STRCAT
** File description:
** Concatenates two strings
*/

int my_strlen(char const *str);

char *my_strcat(char *dest, char const *src)
{
    int i = my_strlen(dest);

    for (int j = 0; src[j] != '\0'; j++) {
        dest[i] = src[j];
        i++;
    }
    return (dest);
}
