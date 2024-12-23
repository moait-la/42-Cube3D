CC = gcc
CFLAGS = -Wall -Werror -Wextra 

MLX42 = -L$(HOME)/my_libraries/MLX42/lib -lmlx42
GLFW  = -L$(HOME)/.brew/Cellar/glfw/3.4/lib -lglfw

LDFLAGS = -fsanitize=address -fsanitize=undefined


LIBFT = ./libft/libft.a

SRC = $(shell find ./mandatory/src -name '*.c')
HEADERS = $(shell find ./mandatory/include/ -name '*.h')

OBJ = $(SRC:.c=.o)
EXEC = cube

all: $(EXEC)

$(EXEC): $(OBJ) $(HEADERS)
<<<<<<< HEAD
	$(CC) $(CFLAGS) $(OBJ) $(GLFW) $(MLX42) $(LIBFT) -o $@ 

clean:
	rm -rf $(OBJ)

# fclean: $(clean)
# 	rm -rf $(EXEC)
=======
	$(CC) $() $(OBJ) $(MACOS) $(GLFW) $(MLX42) $(LIBFT) $(LDFLAGS) -o $@ 

clean:
	rm -rf $(OBJ) $(EXEC)

fclean: $(clean)
	rm -rf $(EXEC)
>>>>>>> 3d8cf8c3502ca5ae9460cb7c62c8c50214a58201
