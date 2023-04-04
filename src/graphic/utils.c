/*
** EPITECH PROJECT, 2023
** Utils functions
** File description:
** utils
*/

#include "graphic.h"

int rectangleshape_is_hover(sfRenderWindow *window,
sfRectangleShape *rectangle)
{
    sfVector2i mpos = sfMouse_getPositionRenderWindow(window);
    sfVector2f rectpos = sfRectangleShape_getPosition(rectangle);

    if (mpos.x >= rectpos.x
    && mpos.x <= rectpos.x + sfRectangleShape_getSize(rectangle).x
    && mpos.y >= rectpos.y
    && mpos.y <= rectpos.y + sfRectangleShape_getSize(rectangle).y)
        return (1);
    return (0);
}

sfVector2f mouse_pos_to_framebuffer_pos(sfVector2i mouse_pos, framebuffer_t *fb)
{
    sfVector2f pos;

    pos.x = mouse_pos.x - (fb->position.x - (fb->width / 2));
    pos.y = mouse_pos.y - (fb->position.y - (fb->height / 2));
    return (pos);
}

int swap_bool(int *n)
{
    if (*n)
        *n = 0;
    else
        *n = 1;
    return (0);
}
