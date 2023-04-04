/*
** EPITECH PROJECT, 2022
** My swap
** File description:
** Swap the content of two integers
*/

void my_swap(int *a, int *b)
{
    int m = *a;

    *a = *b;
    *b = m;
}
