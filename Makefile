# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cgaspart <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/04 15:26:56 by cgaspart          #+#    #+#              #
#    Updated: 2017/12/04 15:44:59 by cgaspart         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

all:
	make -C libft/ fclean && make -C libft
	clang -Wall -Wextra -Werror -I libft/includes -o get_next_line.o -c get_next_line.c
	clang -Wall -Wextra -Werror -I libft/includes -o main.o -c main.c
	clang -o test_gnl main.o get_next_line.o -I libft/includes -L libft/ -lft

fclean:
	make -C libft/ fclean
	rm *.o
