/*
** EPITECH PROJECT, 2023
** PAINT
** File description:
** paint
*/

#ifndef PAINT_H_
    #define PAINT_H_

    #include "graphic.h"

    #define FONT_TITLE "./assets/fonts/Fast.ttf"

    #define COLOR_DARK_BG ((sfColor){18, 18, 18, 255})
    #define COLOR_BG ((sfColor){30, 30, 30, 255})
    #define COLOR_WHITE ((sfColor){242, 231, 254, 255})
    #define COLOR_PRIMARY ((sfColor){187, 134, 252, 255})
    #define COLOR_SECONDARY ((sfColor){3, 218, 197, 255})
    #define COLOR_RED ((sfColor){207, 102, 121, 255})

    #define ICON_BUCKET "./assets/icons/fill-drip-solid.png"
    #define ICON_ERASER "./assets/icons/eraser-solid.png"
    #define ICON_EYE "./assets/icons/eye-solid.png"
    #define ICON_PENCIL "./assets/icons/paintbrush-solid.png"
    #define ICON_PICKER "./assets/icons/eye-dropper-solid.png"
    #define ICON_TRASH "./assets/icons/trash-solid.png"
    #define ICON_SQUARE "./assets/icons/square-regular.png"
    #define ICON_CIRCLE "./assets/icons/circle.png"

    #define TOOL_PENCIL 0
    #define TOOL_BUCKET 1
    #define TOOL_PICKER 2
    #define TOOL_ERASER 3
    #define TOOL_SQUARE 4
    #define TOOL_CIRCLE 5

    #define MAX_LAYERS 50

#endif /* !PAINT_H_ */
