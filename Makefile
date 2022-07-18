# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mkhan <mkhan@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/29 15:23:18 by mkhan             #+#    #+#              #
#    Updated: 2022/06/30 15:42:19 by mkhan            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CLIENT = client.o

SERVER = server.o

CLIENT_B = client_bonus.o

SERVER_B = server_bonus.o

SRC = client.c server.c

SRC_BONUS = client_bonus.c server_bonus.c

CLIENT_NAME = client

SERVER_NAME = server

CLIENT_NAME_B = client_bonus

SERVER_NAME_B = server_bonus

LIBFT_DIR = libft

LIBFT = libft.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror

RM = rm -rf

OBJ = $(SRC:.c=.o)

OBJ_BONUS = $(SRC_BONUS:.c=.o)

all: $(LIBFT) $(CLIENT_NAME) $(SERVER_NAME)
		

bonus: $(LIBFT) $(CLIENT_NAME_B) $(SERVER_NAME_B)
		

$(CLIENT_NAME): $(OBJ)
	$(CC) $(CFLAGS) $(CLIENT) -o $@ $(LIBFT_DIR)/$(LIBFT)
	
$(SERVER_NAME): $(OBJ)
	$(CC) $(CFLAGS) $(SERVER) -o $@ $(LIBFT_DIR)/$(LIBFT)

$(CLIENT_NAME_B): $(OBJ_BONUS)
	$(CC) $(CFLAGS) $(CLIENT_B) -o $@ $(LIBFT_DIR)/$(LIBFT)
	
$(SERVER_NAME_B): $(OBJ_BONUS)
	$(CC) $(CFLAGS) $(SERVER_B) -o $@ $(LIBFT_DIR)/$(LIBFT)
	
$(LIBFT) : 
	@make -C $(LIBFT_DIR)

clean:
	@make -C $(LIBFT_DIR) clean
	@$(RM) server.o client.o
	@$(RM) server_bonus.o client_bonus.o

fclean:
	@make -C $(LIBFT_DIR) fclean
	@make -C ./ clean
	@$(RM) server client server_bonus client_bonus

re:
	@make fclean
	@make all

bonusre:
	@make fclean
	@make bonus

norm:
	@norminette -R CheckForbiddenSourceHeader *.c

.PHONY:	all bonus clean fclean re norm