/*
** EPITECH PROJECT, 2023
** Tickbox
** File description:
** tickbox
*/

#include "paint.h"

int tickbox_destroy(tickbox_t *tb)
{
    rectangle_destroy(&tb->rect);
    return (0);
}

int tickbox_events(tickbox_t *tb, app_t *app)
{
    if (app->event.type == sfEvtMouseButtonPressed
    && rectangleshape_is_hover(app->window, tb->rect.r))
        swap_bool(&tb->is_tick);
    return (0);
}

int tickbox_update(tickbox_t *tb, app_t *app)
{
    if (tb->is_tick)
        sfRectangleShape_setFillColor(tb->rect.r, COLOR_SECONDARY);
    if (tb->is_tick == 0)
        sfRectangleShape_setFillColor(tb->rect.r, COLOR_WHITE);
    if (rectangleshape_is_hover(app->window, tb->rect.r))
        sfRectangleShape_setScale(tb->rect.r, (sfVector2f){1.1, 1.1});
    else
        sfRectangleShape_setScale(tb->rect.r, (sfVector2f){1.0, 1.0});
    rectangle_update(&tb->rect, app);
    return (0);
}

tickbox_t tickbox_create(sfVector2f pos)
{
    tickbox_t tb;

    tb.is_tick = 0;
    tb.rect = rectangle_create(pos, COLOR_WHITE, (sfVector2f){20, 20});
    return (tb);
}
