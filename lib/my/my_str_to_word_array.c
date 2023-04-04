/*
** EPITECH PROJECT, 2022
** My str to word array
** File description:
** STR to word array
*/

#include <stddef.h>
#include <stdlib.h>

int my_strcmp(char const *s1, char const *s2);

int free_array(char **array)
{
    for (int i = 0; array[i] != NULL; i++)
        free(array[i]);
    free(array);
    return (0);
}

static int count_words(char const *str)
{
    int c = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if ((str[i] == ' ' || str[i + 1] == '\0') && str[i + 1] != ' ')
            c++;
    }
    return (c);
}

static int len_word(char const *str, int i)
{
    int c = 0;

    for (; str[i] != ' ' && str[i] != '\0'; i++)
        c++;
    return (c);
}

static void add_to_array(char *w, char const *str, int *j, int i)
{
    w[*j] = str[i];
    *j = *j + 1;
}

char **my_str_to_word_array(char const *str)
{
    char **words = malloc(sizeof(char *) * (count_words(str) + 1));
    char *w = malloc(sizeof(char) * (len_word(str, 0)));
    int j = 0;
    int n = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if ((str[i] == ' ' || str[i] == '\n') && (str[i + 1] != ' '
        && str[i + 1] != '\n')) {
            words[n] = w;
            w = malloc(sizeof(char) * (len_word(str, i + 1)));
            j = 0;
            n++;
        }
        if (str[i] != ' ')
            add_to_array(w, str, &j, i);
    }
    words[n] = w;
    words[n + 1] = NULL;
    return (words);
}
