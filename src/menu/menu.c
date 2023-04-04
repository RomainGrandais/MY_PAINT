/*
** EPITECH PROJECT, 2023
** MENU
** File description:
** menu
*/

#include "paint.h"

int menu_destroy(menu_t *menu)
{
    rectangle_destroy(&menu->background);
    color_palette_destroy(&menu->color_palette);
    topbar_destroy(&menu->topbar);
    toolbar_destroy(&menu->toolbar);
    popup_newfile_destroy(&menu->popup_newfile);
    popup_layer_destroy(&menu->popup_layers);
    return (0);
}

int menu_events(menu_t *menu, app_t *app)
{
    topbar_events(&menu->topbar, app);
    toolbar_events(&menu->toolbar, app);
    color_palette_events(&menu->color_palette, app);
    popup_newfile_events(&menu->popup_newfile, app);
    popup_layer_events(&menu->popup_layers, app);
    return (0);
}

int menu_update(menu_t *menu, app_t *app)
{
    rectangle_update(&menu->background, app);
    toolbar_update(&menu->toolbar, app);
    topbar_update(&menu->topbar, app);
    color_palette_update(&menu->color_palette, app);
    popup_newfile_update(&menu->popup_newfile, app);
    popup_layer_update(&menu->popup_layers, app);
    return (0);
}

menu_t menu_create(void)
{
    menu_t menu;

    menu.topbar = topbar_create();
    menu.toolbar = toolbar_create();
    menu.background = rectangle_create((sfVector2f){0, 0},
    COLOR_BG, (sfVector2f){1920, 150});
    menu.color_palette = color_palette_create((sfVector2f){0, 550});
    menu.popup_newfile = popup_newfile_create();
    menu.popup_layers = popup_layer_create((sfVector2f){1920 - 350, 200});
    return (menu);
}
