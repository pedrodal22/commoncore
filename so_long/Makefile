UNAME := $(shell uname)

MLX_DIR = ./mlx_linux/minilibx-linux
SRC_DIR = .
SUB_DIR = Get_Next_Line

NAME = so_long
SRC = so_long.c file_check.c flood_fill.c mem_alloc.c moves.c free.c mlx_images.c mlx_utils.c enemies.c $(SUB_DIR)/get_next_line.c $(SUB_DIR)/get_next_line_utils.c
OBJ = $(SRC:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror -O3 -g

ifeq ($(UNAME), Linux)
    INCLUDES = -I/usr/include -I$(MLX_DIR) -I$(SUB_DIR)
    MLX_FLAGS = -L$(MLX_DIR) -lmlx -L/usr/lib/X11 -lXext -lX11
    MLX_LIB = $(MLX_DIR)/libmlx.a
else
    INCLUDES = -I/opt/X11/include -I$(MLX_DIR) -I$(SUB_DIR)
    MLX_FLAGS = -L$(MLX_DIR) -lmlx -L/usr/X11/lib -lXext -lX11 -framework OpenGL -framework AppKit
    MLX_LIB = $(MLX_DIR)/libmlx.a
endif


all: $(MLX_LIB) $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(MLX_FLAGS) -o $(NAME)


%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c -o $@ $< $(INCLUDES)

$(MLX_LIB):
	$(MAKE) -C $(MLX_DIR)

clean:
	rm -f $(OBJ)
	$(MAKE) -C $(MLX_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(MLX_DIR) clean

re: fclean all
















#NAME = so_long
#FLAGS = -Wall -Wextra -Werror
#SRC = so_long.c
#OBJ = $(SRC:.c=.o)
#INCLUDES = -I/usr/include/ -Imlx_linux #-Imlx_linux pode causar problemas nos Macs da escola
#FLAGS = -Wall -Wextra -Werror
#MLX_FLAGS = -Lmlx_linux  -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz
#CC = gcc
#
#all: $(NAME)
#
#.c.o:
#	$(CC) -I/usr/include -Imlx_linux -03 -c $< -o $@
#
#$(NAME): $(OBJ)
#	$(CC) $(OBJ) $(MLX_FLAGS) -o $(NAME)