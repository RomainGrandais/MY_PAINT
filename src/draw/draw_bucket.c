/*
** EPITECH PROJECT, 2023
** Draw bucket
** File description:
** draw_bucket
*/

#include "paint.h"
#include "draw.h"

sfColor get_color_pixel(framebuffer_t *framebuffer, sfVector2f pos)
{
    sfUint8 *pixels = framebuffer->pixels;
    sfUint8 *pixel;

    if (pos.x < 0 || pos.x >= framebuffer->width ||
        pos.y < 0 || pos.y >= framebuffer->height) {
            return ((sfColor){0, 0, 0, 0});
        }
    pixel = &pixels[(int)pos.y * framebuffer->width * 4 + (int)pos.x * 4];
    return sfColor_fromRGBA(pixel[0], pixel[1], pixel[2], pixel[3]);
}

int is_same_color(sfColor color_1, sfColor color_2)
{
    if (color_1.a != color_2.a)
        return 0;
    if (color_1.r != color_2.r)
        return 0;
    if (color_1.g != color_2.g)
        return 0;
    if (color_1.b != color_2.b)
        return 0;
    return 1;
}
