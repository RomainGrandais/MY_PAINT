/*
** EPITECH PROJECT, 2023
** Draw
** File description:
** draw methods
*/

#ifndef DRAW_H_
    #define DRAW_H_
    #include "graphic.h"

int put_pixel(framebuffer_t *framebuffer, int x, int y, sfColor color);
int draw_circle(framebuffer_t *framebuffer, sfVector2f center,
float rad, sfColor color);
int draw_square(framebuffer_t *framebuffer,
sfVector2i position, int size, sfColor color);
int draw_bucket(framebuffer_t *framebuffer,
sfVector2f pos, sfColor color_replace);
sfColor get_color_pixel(framebuffer_t *framebuffer, sfVector2f pos);
int is_same_color(sfColor color_1, sfColor color_2);
int change_color(color_palette_t *color_palette, sfColor color);
int remove_color(framebuffer_t *framebuffer, sfVector2f center,
float rad, sfColor color);
int draw_square_shape(framebuffer_t *framebuffer,
sfVector2f pos, sfColor color, app_t *app);
int draw_circle_shape(framebuffer_t *framebuffer,
sfVector2f pos_start, sfColor color, app_t *app);
void draw_circle_for_shape(framebuffer_t *framebuffer, sfVector2f end,
sfVector2f start, sfColor color);

#endif /* !DRAW_H_ */
