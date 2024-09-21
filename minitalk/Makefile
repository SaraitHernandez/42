# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sarherna <sarait.hernandez@novateva.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/01 12:21:24 by sarherna          #+#    #+#              #
#    Updated: 2024/09/21 16:51:38 by sarherna         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror

SERVER = server
CLIENT = client

SRCS = server.c client.c utils.c

OBJDIR = obj
OBJS = $(SRCS:%.c=$(OBJDIR)/%.o)

DEPS = minitalk.h

all: $(SERVER) $(CLIENT)

$(SERVER): $(OBJDIR)/server.o $(OBJDIR)/utils.o
	$(CC) $(CFLAGS) -o $(SERVER) $(OBJDIR)/server.o $(OBJDIR)/utils.o

$(CLIENT): $(OBJDIR)/client.o $(OBJDIR)/utils.o
	$(CC) $(CFLAGS) -o $(CLIENT) $(OBJDIR)/client.o $(OBJDIR)/utils.o

$(OBJDIR)/%.o: %.c $(DEPS)
	@mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJDIR)

fclean: clean
	rm -f $(SERVER) $(CLIENT)

re: fclean all

.PHONY: all clean fclean re
