MLX_DIR = ./mlx-linux/minilibx-linux
SRC_DIR = .
SUB_DIR = Get_Next_Line
SUB_DIR2 = printf

NAME = so_long
SRC = so_long.c file_check.c flood_fill.c mem_alloc.c moves.c free.c mlx_images.c mlx_utils.c enemies.c ft_itoa.c $(SUB_DIR)/get_next_line.c $(SUB_DIR)/get_next_line_utils.c $(SUB_DIR2)/ft_printf.c $(SUB_DIR2)/ft_putchar.c $(SUB_DIR2)/ft_putstr.c $(SUB_DIR2)/ft_putnbr.c $(SUB_DIR2)/ft_strchr.c

OBJ = $(SRC:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror -g

INCLUDES = -I/usr/include -I$(MLX_DIR) -I$(SUB_DIR) -I$(SUB_DIR2)
MLX_FLAGS = -L$(MLX_DIR) -lmlx -L/usr/lib/X11 -lXext -lX11
MLX_LIB = $(MLX_DIR)/libmlx.a

all: $(MLX_LIB) $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) $(MLX_FLAGS) -o $(NAME)


%.o: $(SRC_DIR)/%.c
	@$(CC) $(CFLAGS) -c -o $@ $< $(INCLUDES)

$(MLX_LIB):
	$(MAKE) -C $(MLX_DIR)

clean:
	rm -f $(OBJ)
	$(MAKE) -C $(MLX_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(MLX_DIR) clean

mem:
	make re && valgrind --leak-check=full --show-leak-kinds=all --log-file=val.log ./so_long map1.ver


re: fclean all
