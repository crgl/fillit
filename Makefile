# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cgleason <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/11 10:43:52 by cgleason          #+#    #+#              #
#    Updated: 2018/07/13 15:02:04 by cgleason         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

CC = gcc

CFLAGS = -Wall -Wextra -Werror -I libft -o $(NAME)

DBFLAGS = -Wall -Wextra -Werror -I libft -o villdebug -g

SRC = dr_fill.c robin.c

OBJS = $(SRC:.c=.o)

LIBDIR = libft

LIB = $(LIBDIR)/libft.a

$(NAME): $(OBJS) $(LIB)
	$(CC) $(CFLAGS) $(OBJS) $(LIB)

$(LIB):
	@cd $(LIBDIR) && make

.PHONY: clean fclean all re debug

debug:
	$(CC) $(DBFLAGS) $(SRC) $(LIB)

clean:
	rm -f $(OBJS)
	@cd $(LIBDIR) && make clean

fclean: clean
	rm -f $(NAME)
	@cd $(LIBDIR) && make fclean

all: $(NAME)

re: fclean all
