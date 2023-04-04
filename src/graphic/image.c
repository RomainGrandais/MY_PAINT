/*
** EPITECH PROJECT, 2023
** IMAGE
** File description:
** image
*/

#include "paint.h"

int image_destroy(img_t *img)
{
    sfSprite_destroy(img->sprite);
    sfTexture_destroy(img->texture);
    return (0);
}

int image_update(img_t *img, app_t *app)
{
    sfRenderWindow_drawSprite(app->window, img->sprite, NULL);
    return (0);
}

img_t image_create(char *path, sfVector2f pos, sfVector2f scale)
{
    img_t img;

    img.sprite = sfSprite_create();
    img.texture = sfTexture_createFromFile(path, NULL);
    sfSprite_setTexture(img.sprite, img.texture, sfFalse);
    sfSprite_setPosition(img.sprite, pos);
    sfSprite_setScale(img.sprite, scale);
    return (img);
}
