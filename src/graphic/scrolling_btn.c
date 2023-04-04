/*
** EPITECH PROJECT, 2023
** Scrolling BTN
** File description:
** scrolling button
*/

#include "paint.h"

int scrolling_btn_destroy(scrolling_btn_t *btn)
{
    rectangle_destroy(&btn->rect);
    for (int i = 0; i < btn->nb_elements; i++)
        button_destroy(&btn->btn_elements[i]);
    free(btn->btn_elements);
    return (0);
}

int scrolling_btn_update(scrolling_btn_t *btn, app_t *app)
{
    if (btn->btn_elements[0].is_hover)
        btn->is_active = 1;
    else if (btn->btn_elements[0].is_hover == 0
    && rectangleshape_is_hover(app->window, btn->rect.r) == 0)
        btn->is_active = 0;
    if (btn->is_active) {
        btn->btn_elements[0].text.color = COLOR_PRIMARY;
        rectangle_update(&btn->rect, app);
        for (int i = 1; i < btn->nb_elements; i++)
            button_update(&btn->btn_elements[i], app);
    } else
        btn->btn_elements[0].text.color = COLOR_WHITE;
    button_update(&btn->btn_elements[0], app);

    return (0);
}

scrolling_btn_t scrolling_btn_create(char **elements,
int font_size, sfVector2f pos)
{
    scrolling_btn_t btn;

    btn.nb_elements = len_array(elements);
    btn.is_active = 0;
    btn.btn_elements = malloc(sizeof(button_t) * btn.nb_elements);
    for (int i = 0, y = 0; elements[i] != NULL; i++, y += 30)
        btn.btn_elements[i] = button_create(elements[i], font_size,
        (sfVector2f){pos.x, y}, COLOR_WHITE);
    btn.btn_elements[0].text.color = COLOR_WHITE;
    btn.rect = rectangle_create(pos, COLOR_DARK_BG,
    (sfVector2f){100, 30 * btn.nb_elements});
    free(elements);
    return (btn);
}
