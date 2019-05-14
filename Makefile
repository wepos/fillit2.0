# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gdaemoni <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/08 19:02:50 by gdaemoni          #+#    #+#              #
#    Updated: 2019/05/08 19:28:35 by gdaemoni         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME    =   fillit

FLAGS   =   -Wall -Werror -Wextra

SRC     =   src/main.c src/check_file.c src/check_tetr.c src/fill_matrix_help.c src/fillit.c src/logic.c src/matrix.c src/matrix_for_3.c src/move_to_vec.c src/move_to_vec_help.c src/size.c src/get_const.c

FOR3    =   ./filesfor3

LIBDIR  =   ./libft

all: $(NAME)

$(NAME) : $(OBJ)
			make -C $(LIBDIR)
			gcc $(FLAGS) $(SRC) -L$(LIBDIR) -lft -o $(NAME)


clean:
		rm -f $(OBJ) 
		make clean -C $(LIBDIR)

fclean: clean
		rm -f $(NAME)
		make fclean -C $(LIBDIR)

re:	fclean all
