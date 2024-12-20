# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jingwu <jingwu@student.hive.fi>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/04 10:50:10 by arissane          #+#    #+#              #
#    Updated: 2024/12/19 15:50:46 by arissane         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = miniRT

CC = cc
CFLAGS = -Wall -Werror -Wextra

LIBFT = libft/libft.a
MLX = minilibx-linux/libmlx.a
LIBS = -lXext -lX11 -lm
HEADER = -I./include -I./libft -I ./minilibx-linux

SRCS = main.c \
       read.c \
       render.c \
       camera_ray.c \
       free.c \
       input.c \
       vector_math.c\

OBJS_DIR = ./obj
OBJS = $(patsubst %.c, $(OBJS_DIR)/%.o, $(SRCS))

all: $(NAME)

$(NAME): $(OBJS_DIR) $(OBJS)
	@$(MAKE) -C ./libft
	@$(MAKE) -C ./minilibx-linux
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MLX) $(LIBS) -o $(NAME)

$(OBJS_DIR):
	@mkdir -p $(OBJS_DIR)

$(OBJS_DIR)/%.o: %.c
	@$(CC) $(CFLAGS) $(HEADER) -c $< -o $@

clean:
	@$(MAKE) -C ./libft clean
	@$(MAKE) -C ./minilibx-linux clean
	@rm -rf $(OBJS_DIR)

fclean: clean
	@rm -f $(NAME) ./libft/libft.a

re: fclean all

.PHONY: all clean fclean re
