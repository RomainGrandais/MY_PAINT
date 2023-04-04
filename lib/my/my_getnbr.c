/*
** EPITECH PROJECT, 2022
** My Get NBR
** File description:
** Return the number in a string
*/

static int is_digit(char c)
{
    if (c >= '0' && c <= '9')
        return (1);
    return (0);
}

static int count_digits(char const *str)
{
    int rec = 0;
    int n = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (is_digit(str[i])) {
            rec = 1;
            n++;
        }
        if (is_digit(str[i]) == 0 && rec == 1)
            return (n);
    }
    return (n);
}

static int is_negative(char const *str)
{
    int n = 1;

    for (int i = 0; str[i] == '-' || str[i] == '+'; i++) {
        if (str[i] == '-')
            n *= -1;
    }
    return (n);
}

static int get_start_index(char const *str)
{
    int i = 0;

    for (; is_digit(str[i]) == 0; i++);
    return (i);
}

int my_getnbr(char const *str)
{
    int i = get_start_index(str);
    int n = 0;
    int is_neg = is_negative(str);

    if ((count_digits(str) >= 10 || is_digit(str[0]) == 0)
    && str[0] != '-' && str[0] != '+')
        return (0);
    for (;str[i] != '\0'; i++) {
        if (is_digit(str[i])) {
            n *= 10;
            n = n + (str[i] - '0');
        } else
            return (n * is_neg);
    }
    return (n * is_neg);
}
