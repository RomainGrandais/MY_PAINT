/*
** EPITECH PROJECT, 2022
** My show mem
** File description:
** showmem
*/

int my_showmem(char const *str, int size)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (i == size)
            return (1);
    }
    return (0);
}
