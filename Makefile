NAME = wolf3d

SRC_PATH = src

SRC_NAME = event.c main.c init.c parsing.c check.c draw.c hitbox.c raycasting.c\
			raycastcalc2.c raycastcalc.c tga.c dir_player.c texturing.c\
			dir_ray.c quit.c

CPPFLAGS = -I libft/includes/ -I /usr/local/include/ -MMD

LDFLAGS = -L libft/ -lft

CC = gcc

SDLFLAGS =  $(SDLINCL) -L$(HOME)/.brew/Cellar/sdl2/2.0.10/lib -lSDL2

SDLINCL = -I $(HOME)/.brew/Cellar/sdl2/2.0.10/include/SDL2

CFLAGS = -Werror -Wall -Wextra -O3 -march=native

OBJ_NAME = $(SRC_NAME:.c=.o)

OBJ_PATH = obj

HEADER_PATH = includes/

HEADER_NAME = wolf3d.h

OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))

SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))

HEADER = $(addprefix $(HEADER_PATH)/,$(HEADER_NAME))

all: $(NAME)

$(NAME): $(OBJ)
	make -C libft/
	$(CC) $(CFLAGS) $(LDFLAGS) $(SDLFLAGS) $^ -o $@

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c | $(OBJ_PATH)
	$(CC) $(CFLAGS) $(CPPFLAGS) $(SDLINCL) -I $(HEADER_PATH) -o $@ -c $<

$(OBJ_PATH):
	@mkdir $(OBJ_PATH) 2> /dev/null || true

clean:
	make clean -C libft/
	rm -f $(OBJ) $(OBJ:.o=.d)
	@rmdir $(OBJ_PATH) 2> /dev/null || true

fclean: clean
	make fclean -C libft/
	rm -f $(NAME)

re: fclean
	$(MAKE) all

.PHONY: make clean fclean re

-include $(OBJ:.o=.d)
