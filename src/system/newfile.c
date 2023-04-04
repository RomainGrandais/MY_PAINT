/*
** EPITECH PROJECT, 2023
** New file
** File description:
** newfile
*/

#include "paint.h"

int new_file(int width, int height, app_t *app)
{
    if (width == 0 || height == 0)
        return (84);
    for (int i = 0; i < app->ds.index_layer; i++)
        framebuffer_destroy(app->ds.layers[i]);
    app->ds.index_layer = 0;
    app->ds.layers[app->ds.index_layer] =
    framebuffer_create(width, height, (sfVector2f){1920 / 2, 1080 / 2});
    framebuffer_fill(app->ds.layers[0], sfWhite);
    app->ds.index_layer += 1;
    app->ds.choose_layer = 0;
    my_printf("[INFO] file created (%d, %d)\n", width, height);
    return (0);
}
