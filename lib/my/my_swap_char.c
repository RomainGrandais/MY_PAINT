/*
** EPITECH PROJECT, 2022
** My swap CHAR
** File description:
** Swap the content of two chars
*/

void my_swap_char(char *a, char *b)
{
    char m = *a;

    *a = *b;
    *b = m;
}
