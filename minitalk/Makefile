# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pedro <pedro@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/23 19:06:41 by pedro             #+#    #+#              #
#    Updated: 2024/04/25 02:03:32 by pedro            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SERVER = server
CLIENT = client 
FLAGS = -Wall -Wextra -Werror

SRC_SERVER = server.c ft_printf.c
SRC_CLIENT = client.c ft_printf.c
SRC = $(SRC_SERVER) $(SRC_CLIENT)

OBJ_SERVER = $(SRC_SERVER:.c=.o)
OBJ_CLIENT = $(SRC_CLIENT:.c=.o)
OBJS = $(OBJ_SERVER) $(OBJ_CLIENT)

.PHONY: all clean fclean re

all: $(SERVER) $(CLIENT)

$(SERVER): $(OBJ_SERVER)
	@cc $(FLAGS) $(OBJ_SERVER) -o $(SERVER)
	@echo "Server compilado."

$(CLIENT): $(OBJ_CLIENT)
	@cc $(FLAGS) $(OBJ_CLIENT) -o $(CLIENT)
	@echo "Cient compilado."
	
clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(SERVER) $(CLIENT)

re: fclean all
