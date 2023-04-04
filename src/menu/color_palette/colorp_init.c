/*
** EPITECH PROJECT, 2023
** COLOR
** File description:
** PALETTE color
*/

#include "paint.h"

int color_palette_destroy(color_palette_t *cp)
{
    sfRectangleShape_destroy(cp->background);
    sfRectangleShape_destroy(cp->color_demo);
    text_destroy(&cp->label_r);
    text_destroy(&cp->label_g);
    text_destroy(&cp->label_b);
    textbox_destroy(&cp->txtbox_r);
    textbox_destroy(&cp->txtbox_g);
    textbox_destroy(&cp->txtbox_b);
    text_destroy(&cp->title);
    for (int i = 0; i < 8; i++)
        rectangle_destroy(&cp->default_palette[i]);
    return (0);
}

int color_palette_events(color_palette_t *cp, app_t *app)
{
    if (cp->is_visible == 0)
        return (0);
    textbox_events(&cp->txtbox_r, app);
    textbox_events(&cp->txtbox_g, app);
    textbox_events(&cp->txtbox_b, app);
    return (0);
}

static int cp_create_step2(color_palette_t *cp, sfVector2f position)
{
    cp->default_palette[2] =
    rectangle_create((sfVector2f){position.x + 90, position.y + 250},
    (sfColor){254, 209, 67, 255}, (sfVector2f){35, 35});
    cp->default_palette[3] =
    rectangle_create((sfVector2f){position.x + 125, position.y + 250},
    (sfColor){0, 151, 54, 255}, (sfVector2f){35, 35});
    cp->default_palette[4] =
    rectangle_create((sfVector2f){position.x + 20, position.y + 285},
    (sfColor){1, 80, 165, 255}, (sfVector2f){35, 35});
    cp->default_palette[5] =
    rectangle_create((sfVector2f){position.x + 55, position.y + 285},
    (sfColor){118, 58, 188, 255}, (sfVector2f){35, 35});
    cp->default_palette[6] =
    rectangle_create((sfVector2f){position.x + 90, position.y + 285},
    (sfColor){79, 53, 41, 255}, (sfVector2f){35, 35});
    cp->default_palette[7] =
    rectangle_create((sfVector2f){position.x + 125, position.y + 285},
    (sfColor){0, 0, 0, 255}, (sfVector2f){35, 35});
    cp->is_visible = 1;
    return (0);
}

static int cp_create_step1(color_palette_t *cp, sfVector2f position)
{
    cp->label_r = text_create("Red:", 15,
    (sfVector2f){position.x + 300, position.y + 30}, COLOR_WHITE);
    cp->label_g = text_create("Green:", 15,
    (sfVector2f){position.x + 300, position.y + 90}, COLOR_WHITE);
    cp->label_b = text_create("Blue:", 15,
    (sfVector2f){position.x + 300, position.y + 150}, COLOR_WHITE);
    cp->txtbox_r =
    textbox_create((sfVector2f){position.x + 350, position.y + 30},
    (sfVector2f){50, 30}, 0, "102");
    cp->txtbox_g =
    textbox_create((sfVector2f){position.x + 350, position.y + 90},
    (sfVector2f){50, 30}, 0, "0");
    cp->txtbox_b =
    textbox_create((sfVector2f){position.x + 350, position.y + 150},
    (sfVector2f){50, 30}, 0, "204");
    cp->default_palette = malloc(sizeof(rectangle_t) * 8);
    cp->default_palette[0] =
    rectangle_create((sfVector2f){position.x + 20, position.y + 250},
    (sfColor){233, 62, 63, 255}, (sfVector2f){35, 35});
    return (0);
}

color_palette_t color_palette_create(sfVector2f position)
{
    color_palette_t cp;

    cp.background = sfRectangleShape_create();
    cp.title = text_create("COLORS", 20,
    (sfVector2f){position.x + 175, position.y}, COLOR_WHITE);
    sfRectangleShape_setFillColor(cp.background, COLOR_BG);
    sfRectangleShape_setSize(cp.background, (sfVector2f){450, 350});
    sfRectangleShape_setPosition(cp.background, position);
    cp.color_demo = sfRectangleShape_create();
    cp.actual_color = (sfColor){102, 0, 204, 255};
    sfRectangleShape_setFillColor(cp.color_demo, cp.actual_color);
    sfRectangleShape_setSize(cp.color_demo, (sfVector2f){250, 175});
    sfRectangleShape_setPosition(cp.color_demo,
    (sfVector2f){position.x + 20, position.y + 30});
    cp_create_step1(&cp, position);
    cp.default_palette[1] =
    rectangle_create((sfVector2f){position.x + 55, position.y + 250},
    (sfColor){255, 113, 8, 255}, (sfVector2f){35, 35});
    cp_create_step2(&cp, position);
    return (cp);
}
