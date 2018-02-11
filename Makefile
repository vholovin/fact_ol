NAME		= fractol
NAME_dSYM	= $(NAME:=.dSYM)

CC			= gcc
FLAG		= -Wall -Wextra -Werror -O2 -pipe
FRAMEWORK	= -lmlx -framework OpenGL -framework AppKit
LOCAL		= -I minilibX -g -L minilibX
LIBFT		= libft/libft.a

SRC			= src/main.c				\
			src/init_struct.c			\
			src/error.c					\
			src/calculate_fractal.c		\
			src/fractal_mandelbrot.c	\
			src/fractal_julia.c			\
			src/fractal_burningship.c	\
			src/fractal_tricorn.c		\
			src/fractal_ship.c			\
			src/set_color.c				\
			src/mods_of_colors.c		\
			src/zoom.c					\
			src/key_hook.c				\
			src/mouse_hook.c			\
			src/expose_hook.c			\
			src/tutorial.c

OBJ			= $(patsubst src/%.c,obj/%.o,$(SRC))
.SILENT:

all: $(NAME)

obj/%.o: src/%.c
	mkdir -p obj
	$(CC) $(FLAG) -c $< -o $@
	printf '\033[31m ✔  %s\n\033[0m' "$<"

$(NAME): $(OBJ)
	make -C libft/
	$(CC) $(FLAG) $(LIBFT) $(LOCAL) $(FRAMEWORK) $(OBJ) -o $(NAME)
	printf '\033[32m ✔  %s\n\033[0m' "Create Fractol"

clean:
	make -C libft/ clean
	rm -f $(OBJ)
	rm -f $(NAME_dSYM)
	printf '\033[33m ✔  %s\n\033[0m' "Clean Fractol"

fclean: clean
	make -C libft/ fclean
	rm -rf obj
	rm -f $(NAME)
	printf '\033[33m ✔  %s\n\033[0m' "Fclean Fractol"

re: fclean all

all: $(NAME)
.PHONY: clean fclean re all
