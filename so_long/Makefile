# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sarherna <sarherna@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/25 13:43:09 by sarherna          #+#    #+#              #
#    Updated: 2024/10/08 13:37:33 by sarherna         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = gcc
INCLUDES = -I/usr/include -Imlx
CFLAGS = -Wall -Wextra -Werror -O3 -g
MLX_FLAGS = -Lmlx -lmlx -L/usr/lib/X11 -lXext -lX11

LIBFT_DIR = utils/lib/libft
FT_PRINTF_DIR = utils/lib/ft_printf
GNL_DIR = utils/lib/get_next_line
MAP_DIR = utils/map
GAME_DIR = utils/game
UTILS_DIR = utils
OBJ_DIR = obj

GNL_SRCS = $(GNL_DIR)/get_next_line.c $(GNL_DIR)/get_next_line_utils.c
UTILS_SRCS = $(UTILS_DIR)/error.c $(UTILS_DIR)/file_reader.c $(UTILS_DIR)/free.c $(UTILS_DIR)/print.c
MAP_SRCS = $(MAP_DIR)/map_validator.c $(MAP_DIR)/path_validator.c $(MAP_DIR)/map_constructor.c
GAME_SRCS = $(GAME_DIR)/handler.c $(GAME_DIR)/graphic.c $(GAME_DIR)/game.c
SRCS = so_long.c $(GNL_SRCS) $(UTILS_SRCS) $(MAP_SRCS) $(GAME_SRCS)

OBJS = $(addprefix $(OBJ_DIR)/, $(SRCS:%.c=%.o))

all: $(LIBFT_DIR)/libft.a $(FT_PRINTF_DIR)/libftprintf.a $(NAME)

$(LIBFT_DIR)/libft.a:
	$(MAKE) -C $(LIBFT_DIR)

$(FT_PRINTF_DIR)/libftprintf.a:
	$(MAKE) -C $(FT_PRINTF_DIR)

clone:
	if [ ! -d "mlx" ]; then \
		git clone https://github.com/42Paris/minilibx-linux.git mlx; \
	fi
	
$(NAME): clone $(OBJS)
	make -C mlx
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT_DIR)/libft.a $(FT_PRINTF_DIR)/libftprintf.a $(LIBS) -o $(NAME) $(MLX_FLAGS)

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES)

clean:
	rm -f $(OBJS)
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(FT_PRINTF_DIR) clean
	make clean -C mlx

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(MAKE) -C $(FT_PRINTF_DIR) fclean
	rm -rf mlx
	rm -rf $(OBJ_DIR)

re: fclean all

.PHONY: all clean fclean re