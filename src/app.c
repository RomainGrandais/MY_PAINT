/*
** EPITECH PROJECT, 2022
** App
** File description:
** App gestion
*/

#include "graphic.h"
#include "paint.h"
#include "draw.h"

int app_destroy(app_t *app)
{
    menu_destroy(&app->menu);
    draw_surface_destroy(&app->ds);
    my_printf("-------DESTROY--------\n");
    sfRenderWindow_destroy(app->window);
    my_printf("[DELETE] Window destroyed !\n");
    my_printf("______________________\n");
    return (0);
}

static int app_events_step(app_t *app)
{
    if (app->event.type == sfEvtClosed)
        sfRenderWindow_close(app->window);
    if (app->event.type == sfEvtKeyPressed) {
        if (app->event.key.control && app->event.key.code == sfKeyV) {
            my_printf("PASTE\n");
            img_to_framebuffer(sfClipboard_getString(), app);
        }
    }
    menu_events(&app->menu, app);
    return (0);
}

int app_events(app_t *app)
{
    while (sfRenderWindow_pollEvent(app->window, &app->event))
        app_events_step(app);
    return (0);
}

int app_update(app_t *app)
{
    sfRenderWindow_clear(app->window, COLOR_DARK_BG);
    app->mouse_pos = sfMouse_getPositionRenderWindow(app->window);
    draw_surface_update(&app->ds, app);
    menu_update(&app->menu, app);
    sfRenderWindow_display(app->window);
    return (0);
}

app_t app_create(char *title, int width, int height, int fps_limit)
{
    app_t app;

    my_printf("clipboard: %s\n", sfClipboard_getString());
    my_printf("-------BUILD LOGS-------\n");
    app.mode = (sfVideoMode){width, height, 32};
    app.window = sfRenderWindow_create(app.mode,
    title, sfClose | sfResize, NULL);
    sfRenderWindow_setPosition(app.window, (sfVector2i){0, 0});
    sfRenderWindow_setFramerateLimit(app.window, fps_limit);
    sfRenderWindow_setTitle(app.window, title);
    my_printf("[BUILD] App created.\n");
    app.menu = menu_create();
    app.config_usr.size_brush = 10;
    app.ds = draw_surface_create();
    app.mouse_pos = (sfVector2i){0, 0};
    return (app);
}
