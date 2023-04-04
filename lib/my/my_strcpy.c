/*
** EPITECH PROJECT, 2022
** My str Copy
** File description:
** Copy characters from a string to another
*/

char *my_strncpy(char *dest, char const *src, int n);
int my_strlen(char const *str);

char *my_strcpy(char *dest, char const *src)
{
    int n = my_strlen(src);

    return (my_strncpy(dest, src, n));
}
