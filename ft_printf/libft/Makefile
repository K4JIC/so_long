# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tozaki <tozaki@student.42tokyo.jp>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/18 14:53:35 by tozaki            #+#    #+#              #
#    Updated: 2025/11/16 05:16:27 by tozaki           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libft.a
CC		=	cc
CFLAGS	=	-Wall -Werror -Wextra
LIBS	=	ar -rc
PART1	=	ft_isalpha.c	\
			ft_isdigit.c	\
			ft_isalnum.c	\
			ft_isascii.c	\
			ft_isprint.c	\
			ft_strlen.c		\
			ft_memset.c		\
			ft_bzero.c		\
			ft_memcpy.c		\
			ft_memmove.c	\
			ft_strlcpy.c	\
			ft_strlcat.c	\
			ft_toupper.c	\
			ft_tolower.c	\
			ft_strchr.c		\
			ft_strrchr.c	\
			ft_strncmp.c	\
			ft_memchr.c		\
			ft_memcmp.c		\
			ft_strnstr.c	\
			ft_atoi.c		\
			ft_calloc.c		\
			ft_strdup.c
PART2	=	ft_substr.c		\
			ft_strjoin.c	\
			ft_strtrim.c	\
			ft_split.c		\
			ft_itoa.c		\
			ft_strmapi.c	\
			ft_striteri.c	\
			ft_putchar_fd.c	\
			ft_putstr_fd.c	\
			ft_putendl_fd.c	\
			ft_putnbr_fd.c	\
			ft_putnbr_base_fd.c	\
			ft_putnbr_base_ui_fd.c	\
			ft_putnbr_hex_fd.c	\
			ft_putnbr_ui_fd.c	\
			ft_putptr_fd.c
M_SRCS	=	$(PART1) $(PART2)
BONUSES	=	ft_lstnew.c		\
			ft_lstadd_front.c	\
			ft_lstsize.c	\
			ft_lstlast.c	\
			ft_lstadd_back.c\
			ft_lstdelone.c	\
			ft_lstclear.c	\
			ft_lstiter.c	\
			ft_lstmap.c
B_SRCS	=	$(PART1) $(PART2) $(BONUSES)
HDR		=	libft.h
M_OBJS	=	$(M_SRCS:%.c=%.o)
B_OBJS	=	$(B_SRCS:%.c=%.o)
OBJS	=	$(M_OBJS)
ifdef WITH_BONUS
OBJS += $(B_OBJS)
endif

.PHONY: all
all: $(NAME)

$(NAME): $(M_OBJS)
	$(LIBS) $(NAME) $(OBJS)

.PHONY: bonus
bonus: $(B_OBJS)
	make WITH_BONUS=1

%.o: %.c $(HDR)
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: clean
clean:
	rm -f $(B_OBJS)

.PHONY: fclean
fclean: clean
	rm -f $(NAME)

.PHONY: re
re: fclean all

