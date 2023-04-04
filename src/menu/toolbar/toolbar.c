/*
** EPITECH PROJECT, 2023
** TOOLBAR
** File description:
** TOOLBAR
*/

#include "paint.h"

int toolbar_destroy(toolbar_t *tb)
{
    text_destroy(&tb->label_brush_size);
    textbox_destroy(&tb->txtbox_brush_size);
    for (int i = 0; i < 6; i++)
        tool_destroy(&tb->tools[i]);
    return (0);
}

int check_action(toolbar_t *tb, app_t *app)
{
    int n = -1;

    for (int i = 0; i < 6; i++) {
        if (rectangleshape_is_hover(app->window, tb->tools[i].tickbox.rect.r)) {
            app->config_usr.tool = i;
            n = i;
        }
    }
    if (n == -1)
        return (0);
    for (int i = 0; i < 6; i++) {
        if (i != n)
            tb->tools[i].tickbox.is_tick = 0;
    }
    return (0);
}

int toolbar_events(toolbar_t *tb, app_t *app)
{
    if (app->event.type == sfEvtMouseButtonReleased)
        check_action(tb, app);
    textbox_events(&tb->txtbox_brush_size, app);
    for (int i = 0; i < 6; i++)
        tool_events(&tb->tools[i], app);
    return (0);
}

int toolbar_update(toolbar_t *tb, app_t *app)
{
    text_update(&tb->label_brush_size, app);
    if (my_str_isnum(tb->txtbox_brush_size.text)
    && my_strlen(tb->txtbox_brush_size.text) != 0) {
        app->config_usr.size_brush = my_getnbr(tb->txtbox_brush_size.text);
    }
    textbox_update(&tb->txtbox_brush_size, app);
    for (int i = 0; i < 6; i++)
        tool_update(&tb->tools[i], app);
    return (0);
}

toolbar_t toolbar_create(void)
{
    toolbar_t tb;

    tb.label_brush_size = text_create("Brush size",
    20, (sfVector2f){20, 50}, COLOR_WHITE);
    tb.txtbox_brush_size = textbox_create((sfVector2f){30, 90},
    (sfVector2f){50, 40}, 0, "10");
    tb.tools = malloc(sizeof(tool_t) * 6);
    tb.tools[0] = tool_create("Pencil", ICON_PENCIL, (sfVector2f){200, 75});
    tb.tools[1] = tool_create("Bucket", ICON_BUCKET, (sfVector2f){350, 75});
    tb.tools[2] = tool_create("Picker", ICON_PICKER, (sfVector2f){500, 75});
    tb.tools[3] = tool_create("Eraser", ICON_ERASER, (sfVector2f){650, 75});
    tb.tools[4] = tool_create("Square", ICON_SQUARE, (sfVector2f){800, 75});
    tb.tools[5] = tool_create("Circle", ICON_CIRCLE, (sfVector2f){950, 75});
    tb.tools[0].tickbox.is_tick = 0;
    return (tb);
}
