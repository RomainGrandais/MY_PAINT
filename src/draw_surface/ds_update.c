/*
** EPITECH PROJECT, 2023
** Draw surface UPDATE
** File description:
** ds_update
*/

#include "paint.h"
#include "draw.h"

static int ds_controller_step(draw_surface_t *ds)
{
    if (sfKeyboard_isKeyPressed(sfKeyA)) {
        for (int i = 0; i < ds->index_layer; i++) {
            ds->layers[i]->scale.x += 0.01;
            ds->layers[i]->scale.y += 0.01;
        }
    }
    if (sfKeyboard_isKeyPressed(sfKeyE)) {
        for (int i = 0; i < ds->index_layer; i++) {
            ds->layers[i]->scale.x -= 0.01;
            ds->layers[i]->scale.y -= 0.01;
        }
    }
    return (0);
}

int draw_surface_controller(draw_surface_t *ds)
{
    ds_controller_step(ds);
    if (sfKeyboard_isKeyPressed(sfKeyZ)) {
        for (int i = 0; i < ds->index_layer; i++)
            ds->layers[i]->position.y += 1;
    }
    if (sfKeyboard_isKeyPressed(sfKeyQ)) {
        for (int i = 0; i < ds->index_layer; i++)
            ds->layers[i]->position.x += 1;
    }
    if (sfKeyboard_isKeyPressed(sfKeyS)) {
        for (int i = 0; i < ds->index_layer; i++)
            ds->layers[i]->position.y -= 1;
    }
    if (sfKeyboard_isKeyPressed(sfKeyD)) {
        for (int i = 0; i < ds->index_layer; i++)
            ds->layers[i]->position.x -= 1;
    }
    return (0);
}

static int ds_surface_update_step(draw_surface_t *ds,
app_t *app, sfVector2f pos)
{
    if (app->config_usr.tool == TOOL_PENCIL)
        draw_circle(ds->layers[ds->choose_layer], pos,
        app->config_usr.size_brush, app->menu.color_palette.actual_color);
    if (app->config_usr.tool == TOOL_PICKER)
        change_color(&app->menu.color_palette,
        get_color_pixel(ds->layers[ds->choose_layer], pos));
    if (app->config_usr.tool == TOOL_ERASER)
        remove_color(ds->layers[ds->choose_layer], pos,
        app->config_usr.size_brush, app->menu.color_palette.actual_color);
    if (app->config_usr.tool == TOOL_SQUARE)
        draw_square_shape(ds->layers[ds->choose_layer], pos,
        app->menu.color_palette.actual_color, app);
    if (app->config_usr.tool == TOOL_CIRCLE)
        draw_circle_shape(ds->layers[ds->choose_layer], pos,
        app->menu.color_palette.actual_color, app);
    return (0);
}

int draw_surface_update(draw_surface_t *ds, app_t *app)
{
    sfVector2f pos;

    draw_surface_controller(ds);
    if (sfMouse_isButtonPressed(sfMouseLeft) && ds->choose_layer != -1) {
        pos = mouse_pos_to_framebuffer_pos(app->mouse_pos,
        ds->layers[ds->choose_layer]);
        ds_surface_update_step(ds, app, pos);
    }
    for (int i = 0; i < ds->index_layer; i++)
        framebuffer_update(ds->layers[i], app);
    return (0);
}
