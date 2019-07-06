NAME = fractol

SRCDIR	= ./srcs/

SRC = burningship.c \
	  main.c \
	  images.c \
	  hook.c \
	  tricorn.c \
	  normsucks.c \
	  mandelbrot.c \
	  julia.c

OBJECTS = $(SRC:.c=.o)

INC = includes

CC = gcc
CFLAGS = -Wall -Wextra -Werror

FRAMEWORK = -framework OpenGL -framework AppKit

LIBFT = libft/libft.a

MLX =  minilibx_macos/libmlx.a

.PHONY: all
all: $(NAME)

$(NAME):
	@make -C libft
	@make -C minilibx_macos
	@echo "\033[32mmaking fractol...\033[0m"
	@$(CC) $(CFLAGS) -c $(addprefix $(SRCDIR),$(SRC)) -I $(INC)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJECTS) $(LIBFT) $(MLX) $(FRAMEWORK)

.PHONY: clean
clean:
	@echo  "\033[33mcleaning...\033[0m"
	@/bin/rm -f $(OBJECTS)
	@make -C libft clean
	@make -C minilibx_macos clean

.PHONY: fclean
fclean: clean
		rm -rf $(NAME)
		make -C libft fclean
.PHONY: re
re: fclean all
