# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sarherna <sarherna@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/19 09:24:49 by sarherna          #+#    #+#              #
#    Updated: 2024/09/23 14:26:14 by sarherna         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = push_swap

CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRCDIR = push_swap_lib
OBJDIR = obj
LIBFTDIR = libft

SRC = $(SRCDIR)/error.c $(SRCDIR)/stack_aux_ft.c $(SRCDIR)/push_swap.c \
      $(SRCDIR)/push_swap_aux_ft.c $(SRCDIR)/push_swap_ft.c $(SRCDIR)/stack.c \
      $(SRCDIR)/turk.c $(SRCDIR)/turk_aux_ft.c $(SRCDIR)/stack_checkers.c \
      $(SRCDIR)/turk_aux_sort.c main.c

OBJ = $(SRC:$(SRCDIR)/%.c=$(OBJDIR)/%.o)

LIBFT = $(LIBFTDIR)/libft.a

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) -L$(LIBFTDIR) -lft

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	$(MAKE) -C $(LIBFTDIR)

clean:
	rm -rf $(OBJDIR)
	$(MAKE) -C $(LIBFTDIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFTDIR) fclean

re: fclean all

.PHONY: all clean fclean re