/*
** EPITECH PROJECT, 2022
** My Putchar
** File description:
** Putchar
*/

#include <unistd.h>

int my_putchar(char c)
{
    return (write(1, &c, 1));
}
