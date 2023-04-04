/*
** EPITECH PROJECT, 2023
** LAYER GESTION
** File description:
** GESTION layers
*/

#include "paint.h"

int popup_layer_destroy(popup_layers_t *ppl)
{
    rectangle_destroy(&ppl->background);
    text_destroy(&ppl->title);
    button_destroy(&ppl->btn_create_layer);
    for (int i = 0; i < ppl->nb_layers; i++)
        layer_destroy(&ppl->layers[i]);
    free(ppl->layers);
    return (0);
}

int popup_layer_events(popup_layers_t *ppl, app_t *app)
{
    if (button_isreleased(&ppl->btn_create_layer, app)) {
        ppl->y -= 55;
        ppl->nb_layers += 1;
        ppl->layers[ppl->nb_layers - 1] =
        layer_create((sfVector2f){ppl->position.x + 60, ppl->y}, "new_LAYER");
    }
    for (int i = 0; i < ppl->nb_layers; i++)
        layer_events(&ppl->layers[i], app);
    return (0);
}

int popup_layer_update(popup_layers_t *ppl, app_t *app)
{
    if (ppl->is_visible == 0)
        return (0);
    rectangle_update(&ppl->background, app);
    text_update(&ppl->title, app);
    button_update(&ppl->btn_create_layer, app);
    for (int i = 0; i < ppl->nb_layers; i++)
        layer_update(&ppl->layers[i], app);
    return (0);
}

popup_layers_t popup_layer_create(sfVector2f pos)
{
    popup_layers_t ppl;

    ppl.position = pos;
    ppl.background = rectangle_create(pos, COLOR_BG, (sfVector2f){350, 700});
    ppl.title = text_create("LAYERS", 20,
    (sfVector2f){pos.x + 150, pos.y}, COLOR_WHITE);
    ppl.layers = malloc(sizeof(layer_t) * MAX_LAYERS);
    ppl.y = pos.y + 500;
    ppl.layers[0] = layer_create((sfVector2f){pos.x + 60, ppl.y}, "Layer0");
    ppl.nb_layers = 1;
    ppl.btn_create_layer = button_create("Create layer", 15,
    (sfVector2f){pos.x + 150, pos.y + 600}, COLOR_WHITE);
    ppl.is_visible = 1;
    return (ppl);
}
