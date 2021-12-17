# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cbrito-l <cbrito-l@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/17 14:32:21 by cbrito-l          #+#    #+#              #
#    Updated: 2021/12/17 20:59:18 by cbrito-l         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_CLIENT = client
NAME_SERVER = server

SRCS_DIR = srcs/
INC_DIR = includes/
INC_LIBFT_DIR = _libft/

SRCS_CLIENT = $(addprefix $(SRCS_DIR), \
		client.c 		\
		parse.c			\
		utils.c)

OBJS_CLIENT = $(SRCS_CLIENT:.c=.o)


SRCS_SERVER	= $(addprefix $(SRCS_DIR),	\
		server.c)

OBJS_SERVER = $(SRCS_SERVER:.c=.o)

CC = gcc

INC = $(INC_DIR) $(INC_LIBFT_DIR)

INC_PARAMS = $(INC:%=-I%)

CFLAGS = -Wall -Wextra -Werror $(INC_PARAMS)
DFLAGS = 

LIBFT = Libft/libft.a


all: $(NAME_CLIENT) $(NAME_SERVER)

$(NAME_CLIENT): $(OBJS_CLIENT)
	$(MAKE) -C Libft
	$(CC) $(CFLAGS) $(OBJS_CLIENT) $(LIBFT) -o $(NAME_CLIENT)

$(NAME_SERVER): $(OBJS_SERVER)
	$(MAKE) -C Libft
	$(CC) $(CFLAGS) $(OBJS_SERVER) $(LIBFT) -o $(NAME_SERVER)

bonus: fclean all

debug: CFLAGS += -fsanitize=address -g
debug: fclean all

clean:
	$(RM) $(OBJS_CLIENT) $(OBJS_SERVER)
	$(MAKE) -C Libft clean

fclean: clean
	$(RM) $(NAME_CLIENT) $(NAME_SERVER) $(LIBFT)

re: fclean all

.PHONY = all clean fclean re
