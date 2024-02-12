# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pedro <pedro@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/02 18:51:51 by pedro             #+#    #+#              #
#    Updated: 2024/02/12 10:54:24 by pedro            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
FLAGS = -Wall -Wextra -Werror
SRC =	ft_hexa_Cap.c ft_hexa.c ft_printf.c ft_putchar.c ft_putnbr.c ft_putstr.c ft_unsint.c ft_ptr.c

OBJECTS_SRC = $(SRC:.c=.o)

.PHONY: all clean fclean re 

all: $(NAME)

$(NAME): 
	cc $(FLAGS) $(SRC)
	ar rc $(NAME)

clean:
	rm -f $(OBJECTS_SRC)

fclean: clean
	rm -f $(NAME)

re: fclean all


