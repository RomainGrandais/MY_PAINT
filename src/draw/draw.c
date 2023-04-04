/*
** EPITECH PROJECT, 2022
** Draw
** File description:
** All tools for drawing
*/

#include "graphic.h"
#include "paint.h"

int put_pixel(framebuffer_t *framebuffer, int x, int y, sfColor color)
{
    if (x < framebuffer->width && y < framebuffer->height && x >= 0 && y >= 0) {
        framebuffer->pixels[(y * framebuffer->width + x) * 4] = color.r;
        framebuffer->pixels[(y * framebuffer->width + x) * 4 + 1] = color.g;
        framebuffer->pixels[(y * framebuffer->width + x) * 4 + 2] = color.b;
        framebuffer->pixels[(y * framebuffer->width + x) * 4 + 3] = color.a;
    }
    return (0);
}

void if_in_circle(float *pos, int *index,
framebuffer_t *framebuffer, sfColor color)
{
    int i = index[0];
    int j = index[1];
    float x = pos[0];
    float y = pos[1];
    float rad = pos[2];

    if (my_compute_power_rec(j - x, 2) + my_compute_power_rec(i - y, 2) <=
        my_compute_power_rec(rad, 2)) {
                put_pixel(framebuffer, j, i, color);
        }
}

int draw_circle(framebuffer_t *framebuffer, sfVector2f center,
float rad, sfColor color)
{
    float tab[3];
    int index[2];

    for (int i = center.y - rad; i <= center.y + rad; i++) {
        for (int j = center.x - rad; j <= center.x + rad; j++) {
            tab[0] = center.x;
            tab[1] = center.y;
            tab[2] = rad;
            index[0] = i;
            index[1] = j;
            if_in_circle(tab, index, framebuffer, color);
        }
    }
    return (0);
}

int draw_square(framebuffer_t *framebuffer, sfVector2i position,
int size, sfColor color)
{
    for (int y = position.y; y < position.y + size; y++) {
        for (int x = position.x; x < position.x + size; x++)
            put_pixel(framebuffer, x, y, color);
    }
    return (0);
}
