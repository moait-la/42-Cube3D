CC = gcc
CFLAGS = -Wall -Werror -Wextra 

MLX42 = -L$(HOME)/Desktop/MLX42/build -lmlx42
GLFW  = -L$(HOME)/.brew/Cellar/glfw/3.4/lib -lglfw
MACOS = -framework Cocoa -framework OpenGL -framework IOKit

LIBFT = ./libft/libft.a

SRC = $(shell find ./mandatory/src -name '*.c')
HEADERS = $(shell find ./mandatory/include/ -name '*.h')

OBJ = $(SRC:.cc=.o)
EXEC = cube

all: $(EXEC)

$(EXEC): $(OBJ) $(HEADERS)
	$(CC) $(CFLAGS) $(OBJ) $(MACOS) $(GLFW) $(MLX42) $(LIBFT) -o $@ 

clean:
	rm -rf $(OBJ) $(EXEC)