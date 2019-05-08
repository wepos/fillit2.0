# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gdaemoni <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/02 16:05:22 by gdaemoni          #+#    #+#              #
#    Updated: 2019/05/02 16:50:41 by gdaemoni         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := fillit
NAME_LIB := libft.a
SRC_LIB := ./libft
INSLUDES_LIB = ./libft/libft.h ./libft/vector/ft_vector.h
FLAGS = -W -Wall -Wextra -Werror

all: $(NAME)

createlib:
	gcc -c ${SRC_LIB}/ft_*.c ${FLAGS} 
	gcc -c ${SRC_LIB}/vector/ft_*.c ${FLAGS}
	ar rc ${SRC_LIB}/$(NAME_LIB) ft_*.o
	ranlib ${SRC_LIB}/$(NAME_LIB)	

$(NAME): createlib
	gcc -o $(NAME) src/*.c -L./libft -lft -I ./includes/fillit.h ${FLAGS}

clean:
	@rm -f ft_*.o

fclean: clean
	rm -f $(NAME)
	rm -f $(SRC_LIB)/$(NAME_LIB)

re: fclean all
