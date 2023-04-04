##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## Makefile MYPAINT
##

SRC = 	src/main.c 									\
		src/app.c 									\
		src/draw_surface/ds_init.c 					\
		src/draw_surface/ds_update.c 				\
		src/menu/menu.c 							\
		src/menu/color_palette/colorp_init.c		\
		src/menu/color_palette/colorp_update.c		\
		src/menu/toolbar/toolbar.c 					\
		src/menu/toolbar/tool.c 					\
		src/menu/topbar.c 							\
		src/menu/pop-ups/new_file.c 				\
		src/menu/pop-ups/layers/layer_gestion.c 	\
		src/menu/pop-ups/layers/layer.c 			\
		src/draw/draw.c 							\
		src/draw/framebuffer.c 						\
		src/draw/change_color.c						\
		src/draw/draw_shape.c						\
		src/draw/draw_bucket.c						\
		src/draw/draw_for_shape.c					\
		src/graphic/rectangle.c  					\
		src/graphic/image.c							\
		src/graphic/texts.c 						\
		src/graphic/textbox/txtbox_init.c			\
		src/graphic/textbox/txtbox_update.c			\
		src/graphic/tickbox.c  						\
		src/graphic/button.c 						\
		src/graphic/scrolling_btn.c 				\
		src/graphic/utils.c							\
		src/system/img_to_framebuffer.c				\
		src/system/newfile.c

OBJ = *.o

NAME = my_paint

LIB_PATH = lib/my/

LIB_NAME = my

INCLUDE_PATH = includes/

CFLAGS = -Wall -Wextra -lcsfml-graphics -lcsfml-window -lcsfml-system -lm -g

all:
	make -C $(LIB_PATH)
	gcc -c $(SRC) -I $(INCLUDE_PATH) -Wall -Wextra -g
	gcc $(OBJ) -L $(LIB_PATH) -l$(LIB_NAME) -o $(NAME) $(CFLAGS)

clean:
	make clean -C $(LIB_PATH)
	rm -f $(OBJ)

fclean: clean
	make fclean -C $(LIB_PATH)
	rm -f $(NAME)

re: fclean all
