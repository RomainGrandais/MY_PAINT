/*
** EPITECH PROJECT, 2022
** My compute square root
** File description:
** Return the square root (if it is a whole nb).
*/

int my_compute_power_rec(int nb, int p);

int my_compute_square_root(int nb)
{
    for (int i = nb; i > 0; i--) {
        if (my_compute_power_rec(i, 2) == nb)
            return (i);
    }
    return (0);
}
