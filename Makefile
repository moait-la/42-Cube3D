CC = gcc
CFLAGS = -Wall -Werror -Wextra 

MLX42 = -L$(HOME)/Desktop/MLX42/build -lmlx42
GLFW  = -L$(HOME)/.brew/Cellar/glfw/3.4/lib -lglfw
MACOS = -framework Cocoa -framework OpenGL -framework IOKit

LDFLAGS = -fsanitize=address -fsanitize=undefined


LIBFT = ./libft/libft.a

SRC = $(shell find ./mandatory/src -name '*.c')
HEADERS = $(shell find ./mandatory/include/ -name '*.h')

OBJ = $(SRC:.cc=.o)
EXEC = cube

all: $(EXEC)

$(EXEC): $(OBJ) $(HEADERS)
	$(CC) $() $(OBJ) $(MACOS) $(GLFW) $(MLX42) $(LIBFT) $(LDFLAGS) -o $@ 

clean:
	rm -rf $(OBJ) $(EXEC)

fclean: $(clean)
	rm -rf $(EXEC)