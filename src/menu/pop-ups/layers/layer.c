/*
** EPITECH PROJECT, 2023
** LAYER
** File description:
** layer
*/

#include "paint.h"

int layer_destroy(layer_t *layer)
{
    rectangle_destroy(&layer->bg);
    textbox_destroy(&layer->name);
    image_destroy(&layer->icon_eye);
    image_destroy(&layer->icon_trash);
    return (0);
}

int layer_events(layer_t *layer, app_t *app)
{
    textbox_events(&layer->name, app);
    return (0);
}

int layer_update(layer_t *layer, app_t *app)
{
    rectangle_update(&layer->bg, app);
    textbox_update(&layer->name, app);
    if (layer->is_visible)
        sfSprite_setColor(layer->icon_eye.sprite, COLOR_SECONDARY);
    else
        sfSprite_setColor(layer->icon_eye.sprite, COLOR_WHITE);
    image_update(&layer->icon_eye, app);
    image_update(&layer->icon_trash, app);
    return (0);
}

layer_t layer_create(sfVector2f pos, char *name)
{
    layer_t layer;

    layer.is_visible = 1;
    layer.name = textbox_create((sfVector2f){pos.x + 30, pos.y + 15},
    (sfVector2f){130, 20}, 0, name);
    layer.bg = rectangle_create(pos, COLOR_DARK_BG, (sfVector2f){260, 50});
    layer.icon_eye = image_create(ICON_EYE,
    (sfVector2f){pos.x + 175, pos.y + 10}, (sfVector2f){0.05, 0.05});
    layer.icon_trash = image_create(ICON_TRASH,
    (sfVector2f){pos.x + 220, pos.y + 10}, (sfVector2f){0.05, 0.05});
    return (layer);
}
