/*
** EPITECH PROJECT, 2022
** My is Prime
** File description:
** Return 1 if the number is prime, 0 if not.
*/

int my_compute_square_root(int nb);

int my_is_prime(int nb)
{
    int n = 0;

    if (nb <= 0)
        return (0);
    for (int i = 1; i < nb; i++) {
        if (nb % i == 0)
            n++;
    }
    if (my_compute_square_root(nb) == 0 && n <= 2)
        return (1);
    return (0);
}
