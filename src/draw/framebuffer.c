/*
** EPITECH PROJECT, 2022
** FrameBuffer
** File description:
** Create or destroy framebuffer.
*/

#include "graphic.h"
#include "draw.h"

void framebuffer_destroy(framebuffer_t *framebuffer)
{
    sfSprite_destroy(framebuffer->sprite);
    sfTexture_destroy(framebuffer->texture);
    free(framebuffer->pixels);
    free(framebuffer);
}

void framebuffer_update(framebuffer_t *framebuffer, app_t *app)
{
    sfTexture_updateFromPixels(framebuffer->texture,
    framebuffer->pixels, framebuffer->width, framebuffer->height, 0, 0);
    sfSprite_setPosition(framebuffer->sprite, framebuffer->position);
    sfSprite_setScale(framebuffer->sprite, framebuffer->scale);
    sfRenderWindow_drawSprite(app->window, framebuffer->sprite, NULL);
}

int framebuffer_fill(framebuffer_t *framebuffer, sfColor color)
{
    for (int y = 0; y < framebuffer->height; y++) {
        for (int x = 0; x < framebuffer->width; x++)
            put_pixel(framebuffer, x, y, color);
    }
    return (0);
}

framebuffer_t *framebuffer_create(int width, int height, sfVector2f position)
{
    framebuffer_t *fb = malloc(sizeof(framebuffer_t));

    fb->pixels = malloc(((sizeof(sfUint8) * width) * height) * 4);
    fb->width = width;
    fb->height = height;
    fb->sprite = sfSprite_create();
    fb->texture = sfTexture_create(width, height);
    fb->position = position;
    sfSprite_setTexture(fb->sprite, fb->texture, sfTrue);
    sfSprite_setOrigin(fb->sprite, (sfVector2f){width / 2, height / 2});
    fb->scale = (sfVector2f){1, 1};
    return (fb);
}
