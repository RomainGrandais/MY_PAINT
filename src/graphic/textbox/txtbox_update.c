/*
** EPITECH PROJECT, 2023
** TXTbox
** File description:
** update
*/

#include "paint.h"

static int textbox_events_step(textbox_t *txtbox, app_t *app)
{
    if (app->event.text.unicode == 8 && txtbox->i_text >= 0) {
        txtbox->text[txtbox->i_text] = '\0';
        txtbox->i_text -= 1;
    } else {
        txtbox->i_text += 1;
        txtbox->text[txtbox->i_text] = app->event.text.unicode;
        txtbox->text[txtbox->i_text + 1] = '\0';
    }
    return (0);
}

int textbox_events(textbox_t *txtbox, app_t *app)
{
    if (app->event.type == sfEvtTextEntered) {
        if (app->event.text.unicode < 128 && txtbox->is_focus)
            textbox_events_step(txtbox, app);
    }
    return (0);
}

int textbox_update(textbox_t *txtbox, app_t *app)
{
    if (rectangleshape_is_hover(app->window, txtbox->rect)) {
        sfRectangleShape_setFillColor(txtbox->rect,
        (sfColor){255, 240, 240, 255});
        if (sfMouse_isButtonPressed(sfMouseLeft))
            txtbox->is_focus = 1;
    } else {
        sfRectangleShape_setFillColor(txtbox->rect, sfWhite);
        if (sfMouse_isButtonPressed(sfMouseLeft))
            txtbox->is_focus = 0;
    }
    sfRenderWindow_drawRectangleShape(app->window, txtbox->rect, NULL);
    if (txtbox->show_icon)
        sfRenderWindow_drawSprite(app->window, txtbox->icon, NULL);
    text_update(&txtbox->text_display, app);
    sfText_setString(txtbox->text_display.text, txtbox->text);
    return (0);
}
