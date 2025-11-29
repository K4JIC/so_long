# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tozaki <tozaki@student.42.jp>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/29 20:38:07 by tozaki            #+#    #+#              #
#    Updated: 2025/11/29 20:52:56 by tozaki           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	so_long
CC		=	cc
FLAGS	=	-Wall -Werror -Wextra
LIB_DIR	=	minilibx-linux
LIBS	=	-lmlx -lXext -lX11
HDRS	=	minilibx-linux
SRCS	=	so_long.c
OBJS	=	$(SRCS:%.c=%.o)

.PHONY: all
all: $(NAME)

$(NAME): $(OBJS)
	$(CC)  $(OBJS) -L $(LIB_DIR) $(LIBS) -o $(NAME)

%.o: %.c $(HDRS)
	$(CC) $(FLAGS) -I $(HDRS) -c $< -o $@

.PHONY: clean
clean:
	rm -f $(OBJS)

.PHONY: fclean
fclean: clean
	rm -f $(NAME)
