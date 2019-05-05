# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wvenita <wvenita@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/03 19:46:56 by wvenita           #+#    #+#              #
#    Updated: 2019/05/05 18:50:38 by wvenita          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
FLAGS = -Wall -Wextra -Werror
LIB = ./libft/
OBJ = ./src/ft_main.o\
		./src/ft_read.o\
		./src/ft_solve.o

all: $(NAME)

%.o: %.c
	make -C libft/
	$(CC) $(FLAGS) -I libft/includes -o $@ -c $<

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME) -L libft/ -lft

clean:
	rm -f $(OBJ)
	make -C libft/ clean

fclean: clean
	rm -f $(NAME)
	make -C libft/ fclean

re: fclean all

.PHONY: all clean fclean re