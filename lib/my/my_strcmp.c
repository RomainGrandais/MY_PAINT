/*
** EPITECH PROJECT, 2022
** My str cmp
** File description:
** Compare 2 strings.
*/

int my_strlen(char const *str);
int my_strncmp(char const *s1, char const *s2, int n);

int my_strcmp(char const *s1, char const *s2)
{
    int n = my_strlen(s1);

    if (n != my_strlen(s2))
        return (-1);
    return (my_strncmp(s1, s2, n));
}
