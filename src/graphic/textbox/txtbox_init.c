/*
** EPITECH PROJECT, 2023
** Search
** File description:
** TextBox
*/

#include "graphic.h"

int textbox_destroy(textbox_t *txtbox)
{
    free(txtbox->text);
    text_destroy(&txtbox->text_display);
    sfSprite_destroy(txtbox->icon);
    sfTexture_destroy(txtbox->texture);
    sfRectangleShape_destroy(txtbox->rect);
    return (0);
}

static int texbox_create_step(textbox_t *txtbox,
sfVector2f pos, sfVector2f size, int show_icon)
{
    txtbox->rect = sfRectangleShape_create();
    sfRectangleShape_setPosition(txtbox->rect, pos);
    sfRectangleShape_setSize(txtbox->rect, size);
    sfRectangleShape_setFillColor(txtbox->rect, sfWhite);
    txtbox->icon = sfSprite_create();
    txtbox->texture = sfTexture_createFromFile("assets/icon_search.png", NULL);
    sfSprite_setTexture(txtbox->icon, txtbox->texture, sfFalse);
    sfSprite_setScale(txtbox->icon, (sfVector2f){0.03, 0.03});
    sfSprite_setPosition(txtbox->icon,
    (sfVector2f){pos.x + size.x - 50, pos.y + size.y - 35});
    txtbox->is_focus = 0;
    txtbox->show_icon = 1;
    if (show_icon == 0)
        txtbox->show_icon = 0;
    return (0);
}

textbox_t textbox_create(sfVector2f pos, sfVector2f size,
int show_icon, char *default_text)
{
    textbox_t txtbox;

    txtbox.text = malloc(sizeof(char) * 100);
    txtbox.i_text = -1;
    txtbox.text_display = text_init("assets/fonts/Consolas.ttf",
    size.y - 2, pos, sfBlack);
    if (my_strlen(default_text) > 0) {
        txtbox.text = my_strcpy(txtbox.text, default_text);
        txtbox.i_text = my_strlen(default_text) - 1;
        sfText_setString(txtbox.text_display.text, txtbox.text);
    }
    texbox_create_step(&txtbox, pos, size, show_icon);
    return (txtbox);
}
