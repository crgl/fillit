# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cgleason <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/11 10:43:52 by cgleason          #+#    #+#              #
#    Updated: 2018/07/11 19:33:12 by cgleason         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

CC = gcc

CFLAGS = -Wall -Wextra -Werror -I libft -o $(NAME)

SRC = dr_fill.c

OBJS = $(SRC:.c=.o)

LIBDIR = libft

LIB = $(LIBDIR)/libft.a

$(NAME): $(OBJS) $(LIB)
	$(CC) $(CFLAGS) $(OBJS) $(LIB)

$(LIB):
	@cd $(LIBDIR) && make

.PHONY: clean fclean all re

clean:
	rm -f $(OBJS)
	@cd $(LIBDIR) && make clean

fclean: clean
	rm -f $(NAME)
	@cd $(LIBDIR) && make fclean

all: $(NAME)

re: fclean all
