/*
** EPITECH PROJECT, 2022
** My STR len
** File description:
** Count the number of characters
*/

int my_strlen(char const *str)
{
    int i = 0;

    for (; str[i] != '\0'; i++);
    return (i);
}
