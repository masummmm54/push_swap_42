# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: muhakose <muhakose@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/13 12:23:18 by muhakose          #+#    #+#              #
#    Updated: 2023/12/03 17:24:44 by muhakose         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g
SRC = src/main.c src/swap.c src/push.c src/newmethod.c src/babasort.c src/100sort.c src/middlepivot.c src/middlesort.c src/rotate.c src/reverserotate.c src/sortalgorithm.c utils/lists.c utils/utils.c utils/utils2.c utils/checkfunctions.c
OBJ = $(SRC:.c=.o)
NAME = ./push_swap
LIBFTDIR = ft_libft
LIBFT   = $(LIBFTDIR)/libft.a

all:	$(NAME)

$(NAME):	$(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ) -L$(LIBFTDIR) -lft -o $@

$(LIBFT):
	$(MAKE) -C $(LIBFTDIR)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)
	make fclean -C $(LIBFTDIR)

fclean:	clean
	rm -f $(NAME)

re:	fclean all

.PHONY:	all clean fclean re