/*
** EPITECH PROJECT, 2022
** My str is NUM
** File description:
** Return 1 if string only contains digits chars.
*/

int my_char_isdigit(char c)
{
    if (c >= '0' && c <= '9')
        return (1);
    return (0);
}

int my_str_isnum(char const *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (my_char_isdigit(str[i]) == 0)
            return (0);
    }
    return (1);
}
