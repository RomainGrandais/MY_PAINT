/*
** EPITECH PROJECT, 2022
** My sort Int Array
** File description:
** sort an integer array
*/

void my_swap(int *a, int *b);

static int loop_sort(int *array, int i)
{
    for (int j = 0; j < i; j++) {
        if (array[i] < array[j])
            my_swap(&array[i], &array[j]);
    }
    return (0);
}

void my_sort_int_array(int *array, int size)
{
    for (int i = size - 1; i >= 1; i--)
        loop_sort(array, i);
}
