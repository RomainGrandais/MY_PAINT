/*
** EPITECH PROJECT, 2022
** My rev STR
** File description:
** Reverse string's characters.
*/

int my_strlen(char const *str);

char *my_revstr(char *str)
{
    char m;
    int n = my_strlen(str) - 1;

    for (int i = 0; i < n; i++) {
        m = str[i];
        str[i] = str[n];
        str[n] = m;
        n--;
    }
    return (str);
}
