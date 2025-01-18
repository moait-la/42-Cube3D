NAME = cub3d

CC = cc

CFLAGS = -Wall -Werror -Wextra
# -fsanitize=address

MLX_FLAGS := -lglfw -framework Cocoa -framework OpenGL -framework IOKit

MLX = MLX42/build/libmlx.a

I = -I /Users/${USER}/.brew/Cellar/glfw/3.4/include/GLFW
L = -L /Users/${USER}/.brew/Cellar/glfw/3.4/lib

LIBFT = ./libft/libft.a


SRC =	$(shell find ./mandatory/src -name '*.c') \
		$(shell find ./mandatory/gnl -name '*.c') \
		$(shell find ./mandatory/parsing -name '*.c') \

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