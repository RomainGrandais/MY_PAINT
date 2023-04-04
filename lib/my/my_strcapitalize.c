/*
** EPITECH PROJECT, 2022
** My STR capitalize
** File description:
** capitalize the first letter of each word.
*/

#include <stdio.h>

int is_lower_case(char c)
{
    if (c >= 'a' && c <= 'z')
        return (1);
    return (0);
}

int is_upper_case(char c)
{
    if (c >= 'A' && c <= 'Z')
        return (1);
    return (0);
}

int is_special_char(char c)
{
    if (c >= 32 && c <= 47)
        return (1);
    return (0);
}

char *my_strcapitalize(char *str)
{
    if (is_lower_case(str[0]))
        str[0] -= 32;
    for (int i = 0; str[i + 1] != '\0'; i++) {
        if (is_special_char(str[i]) && is_lower_case(str[i + 1]))
            str[i + 1] -= 32;
        if (is_special_char(str[i]) == 0 && is_upper_case(str[i + 1]))
            str[i + 1] += 32;
    }
    return (str);
}
