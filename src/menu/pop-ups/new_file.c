/*
** EPITECH PROJECT, 2023
** New file
** File description:
** New file UI
*/

#include "paint.h"
#include "draw.h"

int popup_newfile_destroy(popup_newfile_t *ppnf)
{
    rectangle_destroy(&ppnf->background);
    text_destroy(&ppnf->title);
    textbox_destroy(&ppnf->size_width);
    textbox_destroy(&ppnf->size_height);
    text_destroy(&ppnf->label_width);
    text_destroy(&ppnf->label_height);
    button_destroy(&ppnf->btn_create);
    return (0);
}

int popup_newfile_events(popup_newfile_t *ppnf, app_t *app)
{
    if (ppnf->is_visible == 0)
        return (0);
    if (button_isreleased(&ppnf->btn_create, app)) {
        my_printf("[INFO] try to create file...\n");
        if (new_file(my_getnbr(ppnf->size_width.text),
        my_getnbr(ppnf->size_height.text), app) != 84)
            ppnf->is_visible = 0;
    }
    textbox_events(&ppnf->size_width, app);
    textbox_events(&ppnf->size_height, app);
    return (0);
}

int popup_newfile_update(popup_newfile_t *ppnf, app_t *app)
{
    if (ppnf->is_visible == 0) {
        ppnf->btn_create.is_hover = 0;
        return (0);
    }
    if (sfKeyboard_isKeyPressed(sfKeyEscape))
        ppnf->is_visible = 0;
    rectangle_update(&ppnf->background, app);
    text_update(&ppnf->title, app);
    textbox_update(&ppnf->size_width, app);
    textbox_update(&ppnf->size_height, app);
    text_update(&ppnf->label_width, app);
    text_update(&ppnf->label_height, app);
    button_update(&ppnf->btn_create, app);
    return (0);
}

static int popup_newfile_create_step(popup_newfile_t *ppnf)
{
    ppnf->size_width = textbox_create(
    (sfVector2f){ppnf->position.x - 140, ppnf->position.y - 50},
    (sfVector2f){100, 30}, 0, "1080");
    ppnf->size_height = textbox_create(
    (sfVector2f){ppnf->position.x + 30, ppnf->position.y - 50},
    (sfVector2f){100, 30}, 0, "720");
    ppnf->label_width = text_create("Width", 18,
    (sfVector2f){ppnf->position.x - 130, ppnf->position.y - 100}, COLOR_WHITE);
    ppnf->label_height = text_create("Height", 18,
    (sfVector2f){ppnf->position.x + 40, ppnf->position.y - 100}, COLOR_WHITE);
    ppnf->btn_create = button_create("->CREATE<-", 30,
    (sfVector2f){ppnf->position.x - 70, ppnf->position.y + 50}, COLOR_WHITE);
    ppnf->is_visible = 1;
    return (0);
}

popup_newfile_t popup_newfile_create(void)
{
    popup_newfile_t ppnf;

    ppnf.position = (sfVector2f){1920 / 2, 1080 / 2};
    ppnf.title = text_create("NEW FILE", 20,
    (sfVector2f){ppnf.position.x - 38, ppnf.position.y - 175}, COLOR_WHITE);
    ppnf.background = rectangle_create(ppnf.position, COLOR_BG,
    (sfVector2f){450, 350});
    sfRectangleShape_setOrigin(ppnf.background.r,
    (sfVector2f){450 / 2, 350 / 2});
    popup_newfile_create_step(&ppnf);
    return (ppnf);
}
