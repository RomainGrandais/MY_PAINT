/*
** EPITECH PROJECT, 2022
** My str N CMP
** File description:
** compare 2 strings (n firsts)
*/

int my_strlen(char const *str);

int my_strncmp(char const *s1, char const *s2, int n)
{
    for (int i = 0; i < n; i++) {
        if (s1[i] < s2[i])
            return ((s2[i] - s1[i]) * -1);
        if (s1[i] > s2[i])
            return ((s1[i] - s2[i]));
    }
    return (0);
}
