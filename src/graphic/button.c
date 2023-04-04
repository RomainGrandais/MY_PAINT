/*
** EPITECH PROJECT, 2023
** BUTTON
** File description:
** BUTTON
*/

#include "paint.h"

int button_destroy(button_t *btn)
{
    sfRectangleShape_destroy(btn->rect);
    text_destroy(&btn->text);
    return (0);
}

int button_update(button_t *btn, app_t *app)
{
    if (rectangleshape_is_hover(app->window, btn->rect)) {
        btn->is_hover = 1;
        btn->text.color = COLOR_PRIMARY;
    } else {
        btn->is_hover = 0;
        btn->text.color = btn->color;
    }
    sfRenderWindow_drawRectangleShape(app->window, btn->rect, NULL);
    text_update(&btn->text, app);
    return (0);
}

int button_isreleased(button_t *btn, app_t *app)
{
    if (app->event.type == sfEvtMouseButtonReleased && btn->is_hover)
        return (1);
    return (0);
}

button_t button_create(char *str, int font_size, sfVector2f pos, sfColor color)
{
    button_t btn;

    btn.text = text_create(str, font_size, pos, color);
    btn.rect = sfRectangleShape_create();
    sfRectangleShape_setFillColor(btn.rect, (sfColor){255, 255, 255, 0});
    sfRectangleShape_setPosition(btn.rect, pos);
    sfRectangleShape_setSize(btn.rect,
    (sfVector2f){font_size * (my_strlen(str) / 1.5), font_size});
    btn.is_hover = 0;
    btn.color = color;
    return (btn);
}
