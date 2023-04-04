/*
** EPITECH PROJECT, 2022
** MY.h
** File description:
** All prototypes
*/

#ifndef MY_H_
    #define MY_H_

typedef struct array_s {
    char **array;
    char *word;
    int k;
    int n;
} array_t;

void my_putchar(char c);
int my_isneg(int nb);
int my_put_nbr(int nb);
void my_swap(int *a, int *b);
int my_putstr(char const *str);
int my_strlen(char const *str);
int my_int_comp(int n, int n2);
int my_getnbr(char const *str);
void my_sort_int_array(int *tab, int size);
int my_compute_power_rec(int nb, int power);
int my_compute_square_root(int nb);
int my_is_prime(int nb);
int my_find_prime_sup(int nb);
char *my_strcpy(char *dest, char const *src);
char *my_strncpy(char *dest, char const *src, int n);
char *my_revstr(char *str);
char *my_strstr(char *str, char const *to_find);
int my_strcmp(char const *s1, char const *s2);
int my_strncmp(char const *s1, char const *s2, int n);
char *my_strupcase(char *str);
char *my_strlowcase(char *str);
char *my_strcapitalize(char *str);
int my_str_isalpha(char const *str);
int my_str_isnum(char const *str);
int my_str_islower(char const *str);
int my_str_isupper(char const *str);
int my_str_isprintable(char const *str);
int my_showstr(char const *str);
int my_show_mem(char const *str, int size);
char *my_strcat(char *dest, char const *src);
char *my_strncat(char *dest, char const *src, int n);
char **my_str_to_word_array(char const *str);
char *my_strdup(char const *src);
int my_show_word_array(char * const *tab);
int my_showmem(char const *str, int size);
int is_lower_case(char c);
int is_special_char(char c);
int is_upper_case(char c);
int my_char_isalpha(char c);
int my_char_islower(char c);
int my_char_isdigit(char c);
int my_char_isprintable(char c);
int my_char_isupper(char c);
int is_upper_digit(char c);
int is_digit_lowercase(char c);
int my_puterror(char *str);
void my_swap_char(char *a, char *b);
void my_swap_str(char **a, char **b);
int my_printf(char *format, ...);
int free_array(char **array);
char *merge_strings(char *str1, char *str2);
int len_array(char **array);
int len_str(char *str);
char *itoa(int nb);
char *get_buffer(char *path);
char **buffer_to_word_array(char *buffer);
char **copy_array(char **array);

    #include "mylist.h"

#endif /* MY_H_ */
