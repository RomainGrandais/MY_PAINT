/*
** EPITECH PROJECT, 2022
** My put error
** File description:
** Put error
*/

#include <unistd.h>

static int my_putchar_error(char c)
{
    write(2, &c, 1);
    return (0);
}

int my_puterror(char *str)
{
    for (int i = 0; str[i] != '\0'; i++)
        my_putchar_error(str[i]);
    return (0);
}
