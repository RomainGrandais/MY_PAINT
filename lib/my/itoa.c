/*
** EPITECH PROJECT, 2022
** ITOA
** File description:
** Conv Int to char *
*/

#include <stdlib.h>

int my_putchar(char c);

static int count_nb(int nb)
{
    int i = 1;
    int n = 0;

    if (nb < 0) {
        n += 1;
        nb *= -1;
    }
    while ((nb / i) >= 10)
        i *= 10;
    while (i > 0) {
        n += 1;
        i /= 10;
    }
    return (n);
}

char *itoa(int nb)
{
    int i = 1;
    int j = 0;
    char *str = malloc(sizeof(char) * (count_nb(nb) + 1));

    if (nb < 0) {
        str[j] = '-';
        j += 1;
        nb *= -1;
    }
    while ((nb / i) >= 10)
        i *= 10;
    while (i > 0) {
        str[j] = (nb / i) % 10 + '0';
        j += 1;
        i /= 10;
    }
    str[j] = '\0';
    return (str);
}
