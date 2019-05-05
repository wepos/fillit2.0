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

all: $(NAME)
	
$(NAME):
	gcc -o $(NAME) src/*.c -L./libft -lft -L./vector -lvector -I ./includes/fillit.h

clean:
	@rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all
