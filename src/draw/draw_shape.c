/*
** EPITECH PROJECT, 2023
** place_shape.c
** File description:
** place some shape in frame buffer
*/

#include "graphic.h"
#include "paint.h"
#include "draw.h"

sfVector2f find_end(sfVector2f pos_start, sfVector2f pos)
{
    sfVector2f end;

    if (pos_start.x >= pos.x)
        end.x = pos_start.x;
    else
        end.x = pos.x;
    if (pos_start.y >= pos.y)
        end.y = pos_start.y;
    else
        end.y = pos.y;
    return end;
}

sfVector2f find_start(sfVector2f pos_start, sfVector2f pos)
{
    sfVector2f start;

    if (pos_start.x <= pos.x)
        start.x = pos_start.x;
    else
        start.x = pos.x;
    if (pos_start.y <= pos.y)
        start.y = pos_start.y;
    else
        start.y = pos.y;
    return start;
}

int draw_square_shape(framebuffer_t *framebuffer, sfVector2f pos_start,
sfColor color, app_t *app)
{
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(app->window);
    sfVector2f pos = mouse_pos_to_framebuffer_pos(mouse_pos, framebuffer);
    sfVector2f start;
    sfVector2f end;

    if (pos_start.x > framebuffer->width || pos_start.y > framebuffer->height ||
        pos_start.x < 0 || pos_start.y < 0)
        return (0);
    while (pos.x < framebuffer->width && pos.y < framebuffer->height &&
            pos.x >= 0 && pos.y >= 0 && sfMouse_isButtonPressed(sfMouseLeft)) {
        mouse_pos = sfMouse_getPositionRenderWindow(app->window);
        pos = mouse_pos_to_framebuffer_pos(mouse_pos, framebuffer);
    }
    start = find_start(pos_start, pos);
    end = find_end(pos_start, pos);
    for (int i = start.x; i < end.x; i++) {
        for (int j = start.y; j < end.y; j++)
            put_pixel(framebuffer, i, j, color);
    }
    return (0);
}

int draw_circle_shape(framebuffer_t *framebuffer, sfVector2f pos_start,
sfColor color, app_t *app)
{
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(app->window);
    sfVector2f pos = mouse_pos_to_framebuffer_pos(mouse_pos, framebuffer);
    sfVector2f start;
    sfVector2f end;

    if (pos_start.x > framebuffer->width || pos_start.y > framebuffer->height ||
        pos_start.x < 0 || pos_start.y < 0)
        return 0;
    while (pos.x < framebuffer->width && pos.y < framebuffer->height &&
            pos.x >= 0 && pos.y >= 0 &&
            sfMouse_isButtonPressed(sfMouseLeft) == sfTrue) {
        mouse_pos = sfMouse_getPositionRenderWindow(app->window);
        pos = mouse_pos_to_framebuffer_pos(mouse_pos, framebuffer);
    }
    start = find_start(pos_start, pos);
    end = find_end(pos_start, pos);
    draw_circle_for_shape(framebuffer, end, start, color);
    return 0;
}
