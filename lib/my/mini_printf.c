/*
** EPITECH PROJECT, 2022
** MINI Printf
** File description:
** mini printf PROJECT
*/

#include <stdarg.h>

int my_putchar(char c);
int my_putstr(char const *str);
int my_put_nbr(int nb);
int my_put_array(char **array);

int check_argument(char c, int *i, va_list list, int *n)
{
    if (c == ' ')
        *i += 2;
    if (c == 'd' || c == 'i' || c == 's' || c == '%' || c == 'c' || c == 'a')
        *i += 1;
    switch (c) {
        case 'd': *n += my_put_nbr(va_arg(list, int)); break;
        case 'i': *n += my_put_nbr(va_arg(list, int)); break;
        case 's': *n += my_putstr(va_arg(list, char *)); break;
        case 'c': *n += my_putchar(va_arg(list, int)); break;
        case 'a': *n += my_put_array(va_arg(list, char **)); break;
        case '%': *n += my_putchar('%'); break;
        default: my_putchar('%');
    }
    return (0);
}

int my_printf(char *format, ...)
{
    va_list list;
    int n = 0;

    va_start(list, format);
    for (int i = 0; format[i]; i++) {
        if (format[i] == '%')
            check_argument(format[i + 1], &i, list, &n);
        else
            n += my_putchar(format[i]);
    }
    va_end(list);
    return (n);
}
