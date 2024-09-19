# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sarherna <sarait.hernandez@novateva.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/19 09:24:49 by sarherna          #+#    #+#              #
#    Updated: 2024/09/19 13:31:56 by sarherna         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = push_swap

CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRCDIR = push_swap_lib
OBJDIR = obj

SRC = $(SRCDIR)/error.c $(SRCDIR)/stack_aux_ft.c $(SRCDIR)/push_swap.c $(SRCDIR)/push_swap_aux_ft.c $(SRCDIR)/push_swap_ft.c $(SRCDIR)/stack.c $(SRCDIR)/turk.c  $(SRCDIR)/turk_aux_ft.c $(SRCDIR)/stack_checkers.c $(SRCDIR)/turk_aux_sort.c main.c

OBJ = $(SRC:$(SRCDIR)/%.c=$(OBJDIR)/%.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJDIR)

fclean: clean
	rm -f $(NAME)

re: fclean all
