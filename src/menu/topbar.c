/*
** EPITECH PROJECT, 2023
** TOPBAR
** File description:
** top bar
*/

#include "paint.h"

int topbar_destroy(topbar_t *tb)
{
    for (int i = 0; i < tb->nb_top_buttons; i++)
        scrolling_btn_destroy(&tb->top_buttons[i]);
    free(tb->top_buttons);
    return (0);
}

int topbar_events(topbar_t *tb, app_t *app)
{
    if (button_isreleased(&tb->top_buttons[0].btn_elements[2], app)){
        my_printf("[INFO] click on new file.\n");
        app->menu.popup_newfile.is_visible = 1;
        tb->top_buttons[0].btn_elements[2].is_hover = 0;
    }
    if (button_isreleased(&tb->top_buttons[2].btn_elements[1], app)) {
        my_printf("[INFO] click on show/hide Colors\n");
        swap_bool(&app->menu.color_palette.is_visible);
    }
    if (button_isreleased(&tb->top_buttons[2].btn_elements[2], app)) {
        my_printf("[INFO] click on show/hide Layers\n");
        swap_bool(&app->menu.popup_layers.is_visible);
    }
    return (0);
}

int topbar_update(topbar_t *tb, app_t *app)
{
    for (int i = 0; i < tb->nb_top_buttons; i++)
        scrolling_btn_update(&tb->top_buttons[i], app);
    return (0);
}

int topbar_create_step(topbar_t *tb)
{
    tb->top_buttons[0] = scrolling_btn_create(
    buffer_to_word_array("File Open New_file Save Save_as Exit"),
    20, (sfVector2f){20, 10});
    tb->top_buttons[1] = scrolling_btn_create(
    buffer_to_word_array("Edit Test test2 test3 test4 test5 test6"),
    20, (sfVector2f){110, 10});
    tb->top_buttons[2] = scrolling_btn_create(
    buffer_to_word_array("View Colors Layers"), 20, (sfVector2f){210, 10});
    tb->top_buttons[3] = scrolling_btn_create(
    buffer_to_word_array("Image"), 20, (sfVector2f){310, 10});
    tb->top_buttons[4] = scrolling_btn_create(
    buffer_to_word_array("Layers"), 20, (sfVector2f){410, 10});
    tb->top_buttons[5] = scrolling_btn_create(
    buffer_to_word_array("Effects"), 20, (sfVector2f){510, 10});
    tb->top_buttons[6] = scrolling_btn_create(
    buffer_to_word_array("Window"), 20, (sfVector2f){610, 10});
    tb->top_buttons[7] = scrolling_btn_create(
    buffer_to_word_array("Help Exit"), 20, (sfVector2f){710, 10});
    return (0);
}

topbar_t topbar_create(void)
{
    topbar_t tb;

    tb.nb_top_buttons = 8;
    tb.top_buttons = malloc(sizeof(scrolling_btn_t) * tb.nb_top_buttons);
    topbar_create_step(&tb);
    return (tb);
}
