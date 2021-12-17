# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cbrito-l <cbrito-l@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/17 14:32:21 by cbrito-l          #+#    #+#              #
#    Updated: 2021/12/17 21:45:18 by cbrito-l         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_CLIENT = client
NAME_SERVER = server

NAME_CLIENT_BONUS = client_bonus
NAME_SERVER_BONUS = server_bonus

SRCS_DIR = srcs/
INC_DIR = includes/
INC_LIBFT_DIR = _libft/

SRCS_CLIENT = $(addprefix $(SRCS_DIR), \
		client.c 		\
		parse.c			\
		utils.c)

OBJS_CLIENT = $(SRCS_CLIENT:.c=.o)

SRCS_CLIENT_BONUS = $(addprefix $(SRCS_DIR), \
		client_bonus.c 		\
		parse_bonus.c			\
		utils_bonus.c)

OBJS_CLIENT_BONUS = $(SRCS_CLIENT_BONUS:.c=.o)

SRCS_SERVER	= $(addprefix $(SRCS_DIR),	\
		server.c)

OBJS_SERVER = $(SRCS_SERVER:.c=.o)

SRCS_SERVER_BONUS = $(addprefix $(SRCS_DIR),	\
		server_bonus.c)

OBJS_SERVER_BONUS = $(SRCS_SERVER_BONUS:.c=.o)

CC = gcc

INC = $(INC_DIR) $(INC_LIBFT_DIR)

INC_PARAMS = $(INC:%=-I%)

CFLAGS = -Wall -Wextra -Werror $(INC_PARAMS)

LIBFT = _Libft/libft.a


all: $(NAME_CLIENT) $(NAME_SERVER)

$(NAME_CLIENT): $(OBJS_CLIENT)
	$(MAKE) -C _Libft
	$(CC) $(CFLAGS) $(OBJS_CLIENT) $(LIBFT) -o $(NAME_CLIENT)

$(NAME_SERVER): $(OBJS_SERVER)
	$(MAKE) -C _Libft
	$(CC) $(CFLAGS) $(OBJS_SERVER) $(LIBFT) -o $(NAME_SERVER)


bonus: $(NAME_CLIENT_BONUS) $(NAME_SERVER_BONUS)

$(NAME_CLIENT_BONUS): $(OBJS_CLIENT_BONUS)
	$(MAKE) -C _Libft
	$(CC) $(CFLAGS) $(OBJS_CLIENT_BONUS) $(LIBFT) -o $(NAME_CLIENT_BONUS)

$(NAME_SERVER_BONUS): $(OBJS_SERVER_BONUS)
	$(MAKE) -C _Libft
	$(CC) $(CFLAGS) $(OBJS_SERVER_BONUS) $(LIBFT) -o $(NAME_SERVER_BONUS)


debug: CFLAGS += -fsanitize=address -g
debug: fclean all

clean:
	$(RM) $(OBJS_CLIENT) $(OBJS_SERVER) $(OBJS_CLIENT_BONUS) $(OBJS_SERVER_BONUS)
	$(MAKE) -C _Libft clean

fclean: clean
	$(RM) $(NAME_CLIENT) $(NAME_SERVER) $(LIBFT) $(NAME_CLIENT_BONUS) $(NAME_SERVER_BONUS)

re: fclean all

.PHONY = all clean fclean re
