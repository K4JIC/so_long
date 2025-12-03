# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tozaki <tozaki@student.42tokyo.jp>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/29 20:38:07 by tozaki            #+#    #+#              #
#    Updated: 2025/12/03 21:06:32 by tozaki           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	so_long
CFLAGS	=	-Wall -Werror -Wextra
LIB_DIR	=	minilibx-linux
LIBS	=	-lmlx -lXext -lX11

SRCS_DIR	= srcs
OBJS_DIR	= objs

SRCS	=	$(SRCS_DIR)/load_map.c	\
			$(SRCS_DIR)/launch_window.c \
			$(SRCS_DIR)/close_mlx.c	\
			$(SRCS_DIR)/so_long.c
OBJS	=	$(SRCS:$(SRCS_DIR)/%.c=$(OBJS_DIR)/%.o)
INCLUDES	=	-I minilibx-linux -I libft/includes -I includes

.PHONY: all
all: $(NAME)

$(NAME): $(OBJS) libft/libft.a mlx
	$(CC)  $(OBJS) -L $(LIB_DIR) $(LIBS) -o $(NAME) libft/libft.a

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

.PHONY: libft/libft.a
libft/libft.a:
	make -C libft all

.PHONY: mlx
mlx:
	make -C minilibx-linux all

.PHONY: clean
clean:
	make -C libft clean
	make -C minilibx-linux clean
	$(RM) $(OBJS_DIR)

.PHONY: fclean
fclean: clean
	$(RM) libft/libft.a
	$(RM) minilibx-linux/minilibx.a
	$(RM) minilibx-linux/minilibx_linux.a
	$(RM) $(NAME)

.PHONY: re
re: fclean all
