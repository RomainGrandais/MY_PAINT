/*
** EPITECH PROJECT, 2023
** Draw Surface
** File description:
** surface to draw
*/

#include "paint.h"
#include "draw.h"
#include "paint.h"

int draw_surface_destroy(draw_surface_t *ds)
{
    for (int i = 0; i < ds->index_layer; i++)
        framebuffer_destroy(ds->layers[i]);
    free(ds->layers);
    return (0);
}

draw_surface_t draw_surface_create(void)
{
    draw_surface_t ds;

    ds.layers = malloc(sizeof(framebuffer_t) * MAX_LAYERS);
    ds.index_layer = 0;
    ds.choose_layer = -1;
    return (ds);
}
