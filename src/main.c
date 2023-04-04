/*
** EPITECH PROJECT, 2023
** MAIN
** File description:
** main PAINT
*/

#include "graphic.h"

int main(void)
{
    app_t app = app_create("Paint", 1920, 1080, 240);

    while (sfRenderWindow_isOpen(app.window)) {
        app_events(&app);
        app_update(&app);
    }
    app_destroy(&app);
    return (0);
}
