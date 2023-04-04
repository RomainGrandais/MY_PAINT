/*
** EPITECH PROJECT, 2022
** My swap STR
** File description:
** Swap the content of two STR
*/

void my_swap_str(char **a, char **b)
{
    char *m = *a;

    *a = *b;
    *b = m;
}
