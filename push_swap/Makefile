NAME = push_swap
FLAGS = -Wall -Wextra -Werror -g
SRC =	commands.c commands_two.c printf.c stacks.c push_swap.c frees.c utils.c utils_two.c

OBJECTS_SRC = $(SRC:.c=.o)

.PHONY: all clean fclean re 

all: $(NAME)

$(NAME): $(OBJECTS_SRC)
	cc $(FLAGS) $(SRC) -o $(NAME)

clean:
	rm -f $(OBJECTS_SRC)

fclean:
	rm -f $(NAME)

re: fclean all