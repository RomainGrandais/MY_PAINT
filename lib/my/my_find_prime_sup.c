/*
** EPITECH PROJECT, 2022
** Find Prime SUP
** File description:
** Return the smallest prime nb greater than or equal to the nb.
*/

int my_is_prime(int nb);

int my_find_prime_sup(int nb)
{
    int i = nb;

    for (; my_is_prime(i) != 1; i++);
    return (i);
}
