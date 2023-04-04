/*
** EPITECH PROJECT, 2022
** My Put STR
** File description:
** Display a string
*/

void my_putchar(char c);

int my_putstr(char const *str)
{
    int n = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        my_putchar(str[i]);
        n++;
    }
    return (n);
}
