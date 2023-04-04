/*
** EPITECH PROJECT, 2023
** change_color.c
** File description:
** change color for pickcolor tools
*/

#include "graphic.h"
#include "draw.h"
#include "paint.h"

int change_color(color_palette_t *color_palette, sfColor color)
{
    if (color.r == 0 && color.g == 0 && color.b == 0)
        return (0);
    color_palette->actual_color.a = color.a;
    color_palette->actual_color.r = color.r;
    color_palette->actual_color.g = color.g;
    color_palette->actual_color.b = color.b;
    color_palette->txtbox_r.text = my_strcpy(color_palette->txtbox_r.text,
    itoa(color_palette->actual_color.r));
    color_palette->txtbox_g.text = my_strcpy(color_palette->txtbox_g.text,
    itoa(color_palette->actual_color.g));
    color_palette->txtbox_b.text = my_strcpy(color_palette->txtbox_b.text,
    itoa(color_palette->actual_color.b));
    sfRectangleShape_setFillColor(color_palette->color_demo, color);
    return (0);
}

int remove_color(framebuffer_t *framebuffer, sfVector2f center,
float rad, sfColor color)
{
    color.a = 0;
    draw_circle(framebuffer, center, rad, color);
    return 0;
}
