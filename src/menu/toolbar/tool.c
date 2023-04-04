/*
** EPITECH PROJECT, 2023
** TOOL
** File description:
** tool gestion
*/

#include "paint.h"

int tool_destroy(tool_t *tool)
{
    tickbox_destroy(&tool->tickbox);
    image_destroy(&tool->icon);
    return (0);
}

int tool_events(tool_t *tool, app_t *app)
{
    tickbox_events(&tool->tickbox, app);
    return (0);
}

int tool_update(tool_t *tool, app_t *app)
{
    image_update(&tool->icon, app);
    tickbox_update(&tool->tickbox, app);
    return (0);
}

tool_t tool_create(char *name, char *path, sfVector2f pos)
{
    tool_t tool;

    tool.name = name;
    tool.icon = image_create(path, pos, (sfVector2f){0.08, 0.08});
    tool.tickbox = tickbox_create((sfVector2f){pos.x - 30, pos.y + 20});
    return (tool);
}
