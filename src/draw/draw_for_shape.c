/*
** EPITECH PROJECT, 2023
** draw_for_shape.c
** File description:
** draw for shape
*/

#include "graphic.h"
#include "paint.h"
#include "draw.h"

double my_pow(double nb, double p)
{
    if (p < 0)
        return (0);
    if (p == 0)
        return (1);
    return (nb * my_pow(nb, p - 1));
}

void draw_pixel_for_shape(fill_info_t info,
framebuffer_t *framebuffer, sfColor color)
{
    if ((my_pow((info.j - info.center.x) / info.rad.x, 2) +
        my_pow((info.i - info.center.y) / info.rad.y, 2)) <= 1) {
        put_pixel(framebuffer, info.j, info.i, color);
        }
}

void draw_circle_for_shape(framebuffer_t *framebuffer, sfVector2f end,
sfVector2f start, sfColor color)
{
    sfVector2f rad;
    sfVector2f center;
    fill_info_t info;

    center.x = (end.x + start.x) / 2;
    center.y = (end.y + start.y) / 2;
    rad.x = center.x - start.x;
    rad.y = center.y - start.y;
    for (int i = center.y - rad.y; i <= center.y + rad.y; i++) {
        for (int j = center.x - rad.x; j <= center.x + rad.x; j++) {
            info.center = center;
            info.rad = rad;
            info.i = i;
            info.j = j;
            draw_pixel_for_shape(info, framebuffer, color);
        }
    }
}
