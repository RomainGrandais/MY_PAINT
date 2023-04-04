/*
** EPITECH PROJECT, 2022
** My Put NBR
** File description:
** Display a number
*/

void my_putchar(char c);

int my_put_nbr(int nb)
{
    int i = 0;
    int n = 0;

    if (nb < 0) {
        my_putchar('-');
        nb = 0 - nb;
        n += 1;
    }
    if (nb >= 10) {
        i = nb % 10;
        nb = nb / 10;
        my_put_nbr(nb);
        my_putchar(i + '0');
        n += 1;
    } else {
        my_putchar(nb + '0');
        n += 1;
    }
    return (n);
}
