/*
** EPITECH PROJECT, 2023
** Compress
** File description:
** Compress Text file
*/

#include "my.h"

int count_words(char *str)
{
    int c = 1;

    for (int i = 0; str[i] != '\0'; i++) {
        if ((str[i] == ' ' || str[i] == '\n' || str[i] == '\t')
        && (str[i + 1] != ' ' && str[i + 1] != '\n' && str[i + 1] != '\t')
        && str[i + 1] != '\0') {
            c++;
        }
    }
    return (c);
}

static int first_index(char *buffer)
{
    int i = 0;

    for (; (buffer[i] == ' ' || buffer[i] == '\n' || buffer[i] == '\t'); i++);
    return (i);
}

int len_word(char const *str, int i)
{
    int c = 0;

    for (; str[i] != '\n' && str[i] != ' '
    && str[i] != '\t' && str[i] != '\0'; i++) {
        c++;
    }
    return (c);
}

static int create_array_step(array_t *array, char *buffer, int i)
{
    if (((buffer[i] == ' ' || buffer[i] == '\n' || buffer[i] == '\t')
    && (buffer[i + 1] != ' ' && buffer[i + 1] != '\n' && buffer[i + 1] != '\t'))
    && buffer[i + 1] != '\0') {
        array->word[array->k] = '\0';
        array->array[array->n] = array->word;
        array->n += 1;
        array->k = 0;
        array->word = malloc(sizeof(char) * (len_word(buffer, i + 1) + 1));
    }
    if (buffer[i] != ' ' && buffer[i] != '\n' && buffer[i] != '\t') {
        array->word[array->k] = buffer[i];
        array->k += 1;
    }
    return (0);
}

char **buffer_to_word_array(char *buffer)
{
    array_t array;

    array.array = malloc(sizeof(char *) * (count_words(buffer) + 1));
    array.word = malloc(sizeof(char)
    * (len_word(buffer, first_index(buffer)) + 1));
    array.k = 0;
    array.n = 0;
    for (int i = first_index(buffer); buffer[i] != '\0'; i++)
        create_array_step(&array, buffer, i);
    array.word[array.k] = '\0';
    array.array[array.n] = array.word;
    array.array[array.n + 1] = NULL;
    return (array.array);
}
