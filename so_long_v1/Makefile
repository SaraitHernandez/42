# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sarherna <sarherna@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/25 13:43:09 by sarherna          #+#    #+#              #
#    Updated: 2024/09/26 17:10:44 by sarherna         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = gcc
CFLAGS = -Wall -Wextra -Werror -O3
MLX_FLAGS = -I/usr/include -Imlx_linux

LIBS = -Lmlx_linux -lmlx_Linux -L/usr/lib -lXext -lX11 -lm -lz

LIBFT_DIR = lib/libft
FT_PRINTF_DIR = lib/ft_printf
GNL_DIR = lib/get_next_line
MAP_DIR = map_validator
OBJ_DIR = obj

# Añade los archivos fuente de get_next_line
GNL_SRCS = $(GNL_DIR)/get_next_line.c $(GNL_DIR/get_next_line_utils.c) # Asegúrate de que el nombre del archivo sea correcto
SRCS = main.c $(MAP_DIR)/map_validator.c $(MAP_DIR)/path_validator.c \
		$(MAP_DIR)/utils.c $(GNL_SRCS)

OBJS = $(SRCS:%.c=$(OBJ_DIR)/%.o)

all: $(LIBFT_DIR)/libft.a $(FT_PRINTF_DIR)/libftprintf.a $(NAME)

$(LIBFT_DIR)/libft.a:
	$(MAKE) -C $(LIBFT_DIR)

$(FT_PRINTF_DIR)/libftprintf.a:
	$(MAKE) -C $(FT_PRINTF_DIR)

# Regla para compilar el ejecutable
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(MLX_FLAGS) $(OBJS) $(LIBFT_DIR)/libft.a $(FT_PRINTF_DIR)/libftprintf.a $(LIBS) -o $(NAME)

# Regla para compilar los archivos objeto
$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(dir $@)    # Crea los subdirectorios necesarios
	$(CC) $(CFLAGS) $(MLX_FLAGS) -c $< -o $@

# Limpiar archivos objetos
clean:
	rm -f $(OBJS)
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(FT_PRINTF_DIR) clean
	# Limpia los archivos de objeto de get_next_line
	rm -f $(OBJ_DIR)/get_next_line/*.o

# Elimina los archivos generados y binarios
fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(MAKE) -C $(FT_PRINTF_DIR) fclean
	rm -rf $(OBJ_DIR)

# Reconstruir todo
re: fclean all

.PHONY: all clean fclean re
