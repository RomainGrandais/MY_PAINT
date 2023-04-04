/*
** EPITECH PROJECT, 2022
** My str Low case
** File description:
** Puts every letter in lowercase
*/

int is_upper_digit(char c)
{
    if (c >= 'A' && c <= 'Z')
        return (1);
    return (0);
}

char *my_strlowcase(char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (is_upper_digit(str[i]))
            str[i] += 32;
    }
    return (str);
}
