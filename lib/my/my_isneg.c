/*
** EPITECH PROJECT, 2022
** My isNeg
** File description:
** Display 'N' if the integer is negative and 'P' if positive.
*/

void my_putchar(char c);

int my_isneg(int n)
{
    if (n < 0)
        my_putchar('N');
    else
        my_putchar('P');
    return (0);
}
