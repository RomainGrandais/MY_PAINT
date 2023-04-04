/*
** EPITECH PROJECT, 2023
** Graphic
** File description:
** My LIB GRAPHIC
*/

#ifndef GRAPHIC_H_
    #define GRAPHIC_H_

    #include <SFML/Graphics.h>
    #include <SFML/System.h>
    #include <SFML/Window.h>
    #include <math.h>
    #include "my.h"

int rectangleshape_is_hover(sfRenderWindow *window,
sfRectangleShape *rectangle);
int swap_bool(int *n);

typedef struct text_s {
    sfText *text;
    sfFont *font;
    int font_size;
    sfColor color;
    sfVector2f position;
} text_t;

typedef struct textbox_s {
    int i_text;
    char *text;
    text_t text_display;
    sfRectangleShape *rect;
    sfSprite *icon;
    int show_icon;
    sfTexture *texture;
    int is_focus;
} textbox_t;

typedef struct button_s {
    text_t text;
    sfRectangleShape *rect;
    int is_hover;
    sfColor color;
} button_t;

typedef struct img_s {
    sfSprite *sprite;
    sfTexture *texture;
} img_t;

typedef struct rectangle_s {
    sfRectangleShape *r;
} rectangle_t;

typedef struct tickbox_s {
    rectangle_t rect;
    int is_tick;
} tickbox_t;

typedef struct scrolling_btn_s {
    button_t *btn_elements;
    int nb_elements;
    rectangle_t rect;
    int is_active;
} scrolling_btn_t;

typedef struct color_palette_s {
    text_t title;
    sfRectangleShape *color_demo;
    sfRectangleShape *background;
    text_t label_r;
    textbox_t txtbox_r;
    text_t label_g;
    textbox_t txtbox_g;
    text_t label_b;
    textbox_t txtbox_b;
    sfColor actual_color;
    rectangle_t *default_palette;
    int is_visible;
} color_palette_t;

typedef struct topbar_s {
    scrolling_btn_t *top_buttons;
    int nb_top_buttons;
} topbar_t;

typedef struct tool_s {
    char *name;
    img_t icon;
    sfVector2f pos;
    tickbox_t tickbox;
} tool_t;

typedef struct toolbar_s {
    text_t label_brush_size;
    textbox_t txtbox_brush_size;
    tool_t *tools;
} toolbar_t;

typedef struct layer_s {
    textbox_t name;
    int opacity;
    int is_visible;
    img_t icon_eye;
    img_t icon_trash;
    rectangle_t bg;
} layer_t;

typedef struct popup_layers_s {
    text_t title;
    sfVector2f position;
    rectangle_t background;
    layer_t *layers;
    int nb_layers;
    button_t btn_create_layer;
    int is_visible;
    int y;
} popup_layers_t;

typedef struct popup_newfile_s {
    text_t title;
    sfVector2f position;
    rectangle_t background;
    textbox_t size_width;
    text_t label_width;
    textbox_t size_height;
    text_t label_height;
    button_t btn_create;
    int is_visible;
} popup_newfile_t;

typedef struct popup_openimg_s {
    text_t title;
    sfVector2f position;
    rectangle_t background;
    textbox_t size_width;
    text_t label_width;
    textbox_t size_height;
    text_t label_height;
    button_t btn_create;
    int is_visible;
} popup_openimg_t;

typedef struct menu_s {
    topbar_t topbar;
    rectangle_t background;
    color_palette_t color_palette;
    toolbar_t toolbar;
    popup_newfile_t popup_newfile;
    popup_layers_t popup_layers;
} menu_t;

typedef struct framebuffer_s {
    sfUint8 *pixels;
    int width;
    int height;
    sfVector2f position;
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2f scale;
} framebuffer_t;

typedef struct fill_info_s{
    sfVector2f center;
    sfVector2f rad;
    int i;
    int j;
} fill_info_t;

typedef struct config_user_s {
    int size_brush;
    int tool;
} config_user_t;

typedef struct draw_surface_s {
    framebuffer_t **layers;
    int index_layer;
    int choose_layer;
} draw_surface_t;

typedef struct app_s {
    sfVideoMode mode;
    sfRenderWindow *window;
    sfVector2i mouse_pos;
    sfEvent event;
    menu_t menu;
    draw_surface_t ds;
    config_user_t config_usr;
} app_t;

text_t text_create(char *str,
int font_size, sfVector2f position, sfColor color);
text_t text_init(char *path,
int font_size, sfVector2f position, sfColor color);
int text_update(text_t *text, app_t *app);
int text_destroy(text_t *text);

button_t button_create(char *str, int font_size,
sfVector2f pos, sfColor color);
int button_update(button_t *btn, app_t *app);
int button_isreleased(button_t *btn, app_t *app);
int button_destroy(button_t *btn);

img_t image_create(char *path, sfVector2f pos, sfVector2f scale);
int image_update(img_t *img, app_t *app);
int image_destroy(img_t *img);

tickbox_t tickbox_create(sfVector2f pos);
int tickbox_update(tickbox_t *tb, app_t *app);
int tickbox_events(tickbox_t *tb, app_t *app);
int tickbox_destroy(tickbox_t *tb);

scrolling_btn_t scrolling_btn_create(char **elements,
int font_size, sfVector2f pos);
int scrolling_btn_update(scrolling_btn_t *btn, app_t *app);
int scrolling_btn_destroy(scrolling_btn_t *btn);

textbox_t textbox_create(sfVector2f pos, sfVector2f size,
int show_icon, char *default_text);
int textbox_update(textbox_t *txtbox, app_t *app);
int textbox_destroy(textbox_t *txtbox);
int textbox_events(textbox_t *txtbox, app_t *app);

rectangle_t rectangle_create(sfVector2f position,
sfColor color, sfVector2f size);
int rectangle_update(rectangle_t *rect, app_t *app);
int rectangle_destroy(rectangle_t *rect);

color_palette_t color_palette_create(sfVector2f position);
int color_palette_update(color_palette_t *cp, app_t *app);
int color_palette_destroy(color_palette_t *cp);
int color_palette_events(color_palette_t *cp, app_t *app);

topbar_t topbar_create(void);
int topbar_update(topbar_t *tb, app_t *app);
int topbar_events(topbar_t *tb, app_t *app);
int topbar_destroy(topbar_t *tb);

tool_t tool_create(char *name, char *path, sfVector2f pos);
int tool_update(tool_t *tool, app_t *app);
int tool_events(tool_t *tool, app_t *app);
int tool_destroy(tool_t *tool);

toolbar_t toolbar_create(void);
int toolbar_update(toolbar_t *tb, app_t *app);
int toolbar_events(toolbar_t *tb, app_t *app);
int toolbar_destroy(toolbar_t *tb);

layer_t layer_create(sfVector2f pos, char *name);
int layer_update(layer_t *layer, app_t *app);
int layer_events(layer_t *layer, app_t *app);
int layer_destroy(layer_t *layer);

popup_layers_t popup_layer_create(sfVector2f pos);
int popup_layer_update(popup_layers_t *ppl, app_t *app);
int popup_layer_events(popup_layers_t *ppl, app_t *app);
int popup_layer_destroy(popup_layers_t *ppl);

popup_newfile_t popup_newfile_create(void);
int popup_newfile_update(popup_newfile_t *ppnf, app_t *app);
int popup_newfile_events(popup_newfile_t *ppnf, app_t *app);
int popup_newfile_destroy(popup_newfile_t *ppnf);

menu_t menu_create(void);
int menu_update(menu_t *menu, app_t *app);
int menu_events(menu_t *menu, app_t *app);
int menu_destroy(menu_t *menu);

framebuffer_t *framebuffer_create(int width, int height, sfVector2f position);
void framebuffer_destroy(framebuffer_t *framebuffer);
int framebuffer_fill(framebuffer_t *framebuffer, sfColor color);
void framebuffer_update(framebuffer_t *framebuffer, app_t *app);

sfVector2f mouse_pos_to_framebuffer_pos(sfVector2i mouse_pos,
framebuffer_t *fb);
int img_to_framebuffer(const char *path, app_t *app);
int new_file(int width, int height, app_t *app);

draw_surface_t draw_surface_create(void);
int draw_surface_update(draw_surface_t *ds, app_t *app);
int draw_surface_destroy(draw_surface_t *ds);

app_t app_create(char *title, int width, int height, int fps_limit);
int app_update(app_t *app);
int app_events(app_t *app);
int app_destroy(app_t *app);

#endif /* !GRAPHIC_H_ */
