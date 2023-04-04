/*
** EPITECH PROJECT, 2022
** My str is PRINTABLE
** File description:
** Return 1 if string only contains printable chars.
*/

int my_char_isprintable(char c)
{
    if (c >= 32 && c <= 76)
        return (1);
    return (0);
}

int my_str_isprintable(char const *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (my_char_isprintable(str[i]) == 0)
            return (0);
    }
    return (1);
}
