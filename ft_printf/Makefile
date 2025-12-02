# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tozaki <tozaki@student.42tokyo.jp>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/15 19:58:38 by tozaki            #+#    #+#              #
#    Updated: 2025/12/02 20:32:20 by tozaki           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libftprintf.a
CC		=	cc
FLAG	=	-Wall -Werror -Wextra
SRCS 	= 	ft_printf.c get_next_line.c get_next_line_utils.c
MAIN	=	main.c
OBJS 	= 	ft_printf.o get_next_line.o get_next_line_utils.o
HDR 	= 	ft_printf.h get_next_line.h

.PHONY: all
all: $(NAME)

$(NAME): $(OBJS) libft/libft.a
	cp libft/libft.a $(NAME)
	ar rcs $(NAME) $(OBJS)

%.o: %.c $(HDR)
	$(CC) $(FLAGS) -c $< -o $@

.PHONY: run
run: libft/libft.a
	$(CC) $(FLAG) $(SRCS) $(MAIN) $(HDR) -I libft -L libft -lft
	./a.out

libft/libft.a:
	make -C libft all
	make -C libft clean

.PHONY: clean
clean:
	rm -f $(OBJS)

.PHONY: fclean
fclean: clean
	rm -f $(NAME)

.PHONY: re
re: fclean all

