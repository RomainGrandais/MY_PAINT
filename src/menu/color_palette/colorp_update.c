/*
** EPITECH PROJECT, 2023
** Color palette UPDATE
** File description:
** colorp_update
*/

#include "paint.h"

static int color_palette_update_step(app_t *app, color_palette_t *cp)
{
    for (int i = 0; i < 8; i++) {
        if (rectangleshape_is_hover(app->window, cp->default_palette[i].r)
        && sfMouse_isButtonPressed(sfMouseLeft)) {
            cp->actual_color =
            sfRectangleShape_getFillColor(cp->default_palette[i].r);
            cp->txtbox_r.text =
            my_strcpy(cp->txtbox_r.text, itoa(cp->actual_color.r));
            cp->txtbox_r.i_text = my_strlen(itoa(cp->actual_color.r)) - 1;
            cp->txtbox_g.text =
            my_strcpy(cp->txtbox_g.text, itoa(cp->actual_color.g));
            cp->txtbox_g.i_text = my_strlen(itoa(cp->actual_color.g)) - 1;
            cp->txtbox_b.text =
            my_strcpy(cp->txtbox_b.text, itoa(cp->actual_color.b));
            cp->txtbox_b.i_text = my_strlen(itoa(cp->actual_color.b)) - 1;
        }
        rectangle_update(&cp->default_palette[i], app);
    }
    sfRectangleShape_setFillColor(cp->color_demo, cp->actual_color);
    text_update(&cp->title, app);
    return (0);
}

int color_palette_update(color_palette_t *cp, app_t *app)
{
    if (cp->is_visible == 0)
        return (0);
    sfRenderWindow_drawRectangleShape(app->window, cp->background, NULL);
    sfRenderWindow_drawRectangleShape(app->window, cp->color_demo, NULL);
    text_update(&cp->label_r, app);
    text_update(&cp->label_g, app);
    text_update(&cp->label_b, app);
    textbox_update(&cp->txtbox_r, app);
    textbox_update(&cp->txtbox_g, app);
    textbox_update(&cp->txtbox_b, app);
    cp->actual_color.r = my_getnbr(cp->txtbox_r.text);
    cp->actual_color.g = my_getnbr(cp->txtbox_g.text);
    cp->actual_color.b = my_getnbr(cp->txtbox_b.text);
    color_palette_update_step(app, cp);
    return (0);
}
