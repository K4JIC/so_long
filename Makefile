# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tozaki <tozaki@student.42tokyo.jp>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/29 20:38:07 by tozaki            #+#    #+#              #
#    Updated: 2025/12/04 20:42:44 by tozaki           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	so_long
CFLAGS	=	-Wall -Werror -Wextra # -fsanitize=address -g
LIB_DIR	=	minilibx-linux
LIBS	=	-lmlx -lXext -lX11

SRCS_DIR	= ./srcs/
OBJS_DIR	= ./objs/

SRCS_NAME	=	load_map.c	\
			launch_window.c \
			close_mlx.c	\
			so_long.c \
			draw_window.c \
			celltype.c \
			validate_map \
			celltype.c \
			deal_key.c

SRCS	=	$(addprefix $(SRCS_DIR), $(SRCS_NAME))
OBJS	=	$(addprefix $(OBJS_DIR), $(SRCS_NAME:.c=.o))
# OBJS	=	$(SRCS:$(SRCS_DIR)/%.c=$(OBJS_DIR)/%.o)
INCLUDES	=	-I minilibx-linux -I libft/includes -I includes

.PHONY: all
all: $(NAME)

$(NAME): $(OBJS) libft/libft.a mlx
	$(CC)  $(CFLAGS) $(OBJS) -L $(LIB_DIR) $(LIBS) -o $(NAME) libft/libft.a

$(OBJS_DIR)%.o: $(SRCS_DIR)%.c
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
	rm -rf $(OBJS_DIR)

.PHONY: fclean
fclean: clean
	$(RM) libft/libft.a
	$(RM) minilibx-linux/minilibx.a
	$(RM) minilibx-linux/minilibx_linux.a
	$(RM) $(NAME)

.PHONY: re
re: fclean all
