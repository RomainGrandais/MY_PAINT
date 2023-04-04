/*
** EPITECH PROJECT, 2022
** My str is LOWER
** File description:
** Return 1 if string only contains lower chars.
*/

int my_char_islower(char c)
{
    if (c >= 'a' && c <= 'z')
        return (1);
    return (0);
}

int my_str_islower(char const *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (my_char_islower(str[i]) == 0)
            return (0);
    }
    return (1);
}
