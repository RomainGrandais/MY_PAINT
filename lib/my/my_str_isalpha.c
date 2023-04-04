/*
** EPITECH PROJECT, 2022
** My str is alpha
** File description:
** Return 1 if string only contains alpha chars
*/

int my_char_isalpha(char c)
{
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
        return (1);
    if (c == '_')
        return (1);
    return (0);
}

int my_str_isalpha(char const *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (my_char_isalpha(str[i]) == 0)
            return (0);
    }
    return (1);
}
