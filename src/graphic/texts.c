/*
** EPITECH PROJECT, 2023
** Texts
** File description:
** texts
*/

#include "paint.h"

int text_destroy(text_t *text)
{
    sfFont_destroy(text->font);
    sfText_destroy(text->text);
    return (0);
}

int text_update(text_t *text, app_t *app)
{
    sfText_setColor(text->text, text->color);
    sfRenderWindow_drawText(app->window, text->text, NULL);
    return (0);
}

text_t text_create(char *str,
int font_size, sfVector2f position, sfColor color)
{
    text_t txt;

    txt.text = sfText_create();
    txt.font = sfFont_createFromFile(FONT_TITLE);
    txt.position = position;
    txt.color = color;
    sfText_setPosition(txt.text, txt.position);
    sfText_setString(txt.text, str);
    sfText_setCharacterSize(txt.text, font_size);
    sfText_setFont(txt.text, txt.font);
    sfText_setColor(txt.text, txt.color);
    return (txt);
}

text_t text_init(char *path,
int font_size, sfVector2f position, sfColor color)
{
    text_t txt;

    txt.text = sfText_create();
    txt.font = sfFont_createFromFile(path);
    txt.position = position;
    txt.color = color;
    sfText_setPosition(txt.text, txt.position);
    sfText_setString(txt.text, "");
    sfText_setCharacterSize(txt.text, font_size);
    sfText_setFont(txt.text, txt.font);
    sfText_setColor(txt.text, txt.color);
    return (txt);
}
