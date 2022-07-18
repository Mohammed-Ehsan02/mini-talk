# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mkhan <mkhan@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/25 11:28:17 by mkhan             #+#    #+#              #
#    Updated: 2022/07/16 19:57:45 by mkhan            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SRCS			=	ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c \
					ft_isprint.c ft_strlen.c ft_memset.c ft_bzero.c \
					ft_memcpy.c ft_memmove.c ft_strlcpy.c ft_strlcat.c \
					ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c \
					ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c \
					ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c \
					ft_strjoin.c ft_strtrim.c ft_putchar_fd.c ft_putstr_fd.c \
					ft_putendl_fd.c ft_putnbr_fd.c ft_striteri.c ft_strmapi.c \
					ft_itoa.c ft_split.c
OBJS			= $(SRCS:.c=.o)

BONUS			=	ft_lstadd_back.c ft_lstadd_front.c ft_lstlast.c \
					ft_lstnew.c ft_lstsize.c ft_lstdelone.c \
					ft_lstclear.c ft_lstiter.c ft_lstmap.c

BONUS_OBJS		= $(BONUS:.c=.o)

PRINTF			= 	ft_printf.c ft_putchar.c ft_putstr.c ft_hexaddr.c \
					ft_intdec.c ft_unint.c ft_hexalow.c ft_hexacap.c \

PRINTF_OBJS		= $(PRINTF:.c=.o)

GNL				=	get_next_line.c get_next_line_bonus.c \
					ft_gnl_strjoin.c \

GNL_OBJS		= $(GNL:.c=.o)

CC				= gcc
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror -I.

NAME			= libft.a

all:			$(NAME)

$(NAME):		$(OBJS) $(BONUS_OBJS) $(PRINTF_OBJS) $(GNL_OBJS)
				ar rcs $(NAME) $(OBJS) $(BONUS_OBJS) $(GNL_OBJS)

bonus:			$(BONUS_OBJS)
				ar rcs $(NAME) $(BONUS_OBJS)

printf:			$(PRINTF_OBJS)
				ar rcs $(NAME) $(PRINTF_OBJS)

gnl:			$(GNL_OBJS)
				ar rcs $(NAME) $(GNL_OBJS)

re:				fclean $(NAME)

clean:
				$(RM) $(OBJS) $(BONUS_OBJS) $(PRINTF_OBJS) $(GNL_OBJS)

fclean:			clean
				$(RM) $(NAME)

.PHONY:			all clean fclean re bonus