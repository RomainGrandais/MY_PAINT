/*
** EPITECH PROJECT, 2022
** My str is UPPER
** File description:
** Return 1 if string only contains upper chars.
*/

int my_char_isupper(char c)
{
    if (c >= 'A' && c <= 'Z')
        return (1);
    return (0);
}

int my_str_isupper(char const *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (my_char_isupper(str[i]) == 0)
            return (0);
    }
    return (1);
}
