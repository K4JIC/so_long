# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tozaki <tozaki@student.42tokyo.jp>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/03 14:09:35 by tozaki            #+#    #+#              #
#    Updated: 2025/12/04 21:02:30 by tozaki           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libft.a

CC			= cc
CFLAGS		= -Wall -Wextra -Werror
AR			= ar rcs
RM			= rm -f

SRCS_DIR	= srcs
OBJS_DIR	= objs
INCS_DIR	= includes

INCLUDES	= -I$(INCS_DIR)

SRCS		= $(SRCS_DIR)/convert/ft_atoi.c \
			  $(SRCS_DIR)/convert/ft_itoa.c \
			  $(SRCS_DIR)/convert/ft_split.c \
			  $(SRCS_DIR)/convert/get_next_line.c \
			  $(SRCS_DIR)/convert/get_next_line_utils.c \
			  $(SRCS_DIR)/ctype/ft_isalnum.c \
			  $(SRCS_DIR)/ctype/ft_isalpha.c \
			  $(SRCS_DIR)/ctype/ft_isascii.c \
			  $(SRCS_DIR)/ctype/ft_isdigit.c \
			  $(SRCS_DIR)/ctype/ft_isprint.c \
			  $(SRCS_DIR)/ctype/ft_tolower.c \
			  $(SRCS_DIR)/ctype/ft_toupper.c \
			  $(SRCS_DIR)/initalize/ft_bzero.c \
			  $(SRCS_DIR)/initalize/ft_calloc.c \
			  $(SRCS_DIR)/list/ft_lstadd_back.c \
			  $(SRCS_DIR)/list/ft_lstadd_front.c \
			  $(SRCS_DIR)/list/ft_lstclear.c \
			  $(SRCS_DIR)/list/ft_lstdelone.c \
			  $(SRCS_DIR)/list/ft_lstiter.c \
			  $(SRCS_DIR)/list/ft_lstlast.c \
			  $(SRCS_DIR)/list/ft_lstmap.c \
			  $(SRCS_DIR)/list/ft_lstnew.c \
			  $(SRCS_DIR)/list/ft_lstsize.c \
			  $(SRCS_DIR)/put/ft_putchar_fd.c \
			  $(SRCS_DIR)/put/ft_putendl_fd.c \
			  $(SRCS_DIR)/put/ft_putnbr_base_fd.c \
			  $(SRCS_DIR)/put/ft_putnbr_base_ui_fd.c \
			  $(SRCS_DIR)/put/ft_putnbr_fd.c \
			  $(SRCS_DIR)/put/ft_putnbr_hex_fd.c \
			  $(SRCS_DIR)/put/ft_putnbr_ui_fd.c \
			  $(SRCS_DIR)/put/ft_putptr_fd.c \
			  $(SRCS_DIR)/put/ft_putstr_fd.c \
			  $(SRCS_DIR)/put/ft_printf.c \
			  $(SRCS_DIR)/string/ft_memchr.c \
			  $(SRCS_DIR)/string/ft_memcmp.c \
			  $(SRCS_DIR)/string/ft_memcpy.c \
			  $(SRCS_DIR)/string/ft_memmove.c \
			  $(SRCS_DIR)/string/ft_memset.c \
			  $(SRCS_DIR)/string/ft_strchr.c \
			  $(SRCS_DIR)/string/ft_strdup.c \
			  $(SRCS_DIR)/string/ft_striteri.c \
			  $(SRCS_DIR)/string/ft_strjoin.c \
			  $(SRCS_DIR)/string/ft_strlcat.c \
			  $(SRCS_DIR)/string/ft_strlcpy.c \
			  $(SRCS_DIR)/string/ft_strlen.c \
			  $(SRCS_DIR)/string/ft_strmapi.c \
			  $(SRCS_DIR)/string/ft_strncmp.c \
			  $(SRCS_DIR)/string/ft_strnstr.c \
			  $(SRCS_DIR)/string/ft_strrchr.c \
			  $(SRCS_DIR)/string/ft_strtrim.c \
			  $(SRCS_DIR)/string/ft_substr.c

OBJS		= $(SRCS:$(SRCS_DIR)/%.c=$(OBJS_DIR)/%.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	$(RM) -r $(OBJS_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re test