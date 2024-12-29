NAME = cub3D

CC = cc

CFLAGS = -Wall -Werror -Wextra -0fast
# -fsanitize=address

MLX_FLAGS := -lglfw -framework Cocoa -framework OpenGL -framework IOKit

MLX = MLX42/build/libmlx.a

I = -I /Users/${USER}/.brew/Cellar/glfw/3.4/include/GLFW
L = -L /Users/${USER}/.brew/Cellar/glfw/3.4/lib

LIBFT = ./libft/libft.a

SRC = 

# SRC = $(shell find ./mandatory/src -name '*.c')

HEADERS = $(shell find ./mandatory/include/ -name '*.h')

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) $(HEADERS)
	$(CC) $(CFLAGS) $(MLX_FLAGS) $(OBJ) $(MLX) $(I) $(L) $(LIBFT) -o $@ 

%.o : %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@ -I ./manda

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re : fclean all 

.PHONY: clean