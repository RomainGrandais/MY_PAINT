/*
** EPITECH PROJECT, 2023
** IMG to framebuffer
** File description:
** img_to_framebuffer
*/

#include "paint.h"
#include "draw.h"

static int img_to_framebuf_step(sfVector2u size,
app_t *app, sfImage *img, int y)
{
    sfColor color;

    for (int x = 0; x < (int)size.x; x++) {
        color = sfImage_getPixel(img, x, y);
        if (x < app->ds.layers[0]->width && y < app->ds.layers[0]->height)
            put_pixel(app->ds.layers[0], x, y, color);
    }
    return (0);
}

int img_to_framebuffer(const char *path, app_t *app)
{
    sfImage *img = sfImage_createFromFile(path);

    if (img == NULL) {
        my_printf("IMPOSSIBLE to load img\n");
        sfImage_destroy(img);
        return (84);
    }
    my_printf("IMG {%s} loaded. apply...\n", path);
    sfVector2u size = sfImage_getSize(img);
    for (int y = 0; y < (int)size.y; y++)
        img_to_framebuf_step(size, app, img, y);
    sfImage_destroy(img);
    return (0);
}
