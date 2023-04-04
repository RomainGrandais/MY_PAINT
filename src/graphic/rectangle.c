/*
** EPITECH PROJECT, 2023
** RECTANGLE
** File description:
** Best rectangle gestion
*/

#include "paint.h"

int rectangle_destroy(rectangle_t *rect)
{
    sfRectangleShape_destroy(rect->r);
    return (0);
}

int rectangle_update(rectangle_t *rect, app_t *app)
{
    sfRenderWindow_drawRectangleShape(app->window, rect->r, NULL);
    return (0);
}

rectangle_t rectangle_create(sfVector2f position,
sfColor color, sfVector2f size)
{
    rectangle_t rect;

    rect.r = sfRectangleShape_create();
    sfRectangleShape_setFillColor(rect.r, color);
    sfRectangleShape_setSize(rect.r, size);
    sfRectangleShape_setPosition(rect.r, position);
    return (rect);
}
