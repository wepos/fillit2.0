/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdaemoni <gdaemoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 13:26:07 by gdaemoni          #+#    #+#             */
/*   Updated: 2019/04/26 19:45:22 by gdaemoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <fcntl.h>
# include <unistd.h>
# include "../libft/libft.h"
# include "../libft/vector/ft_vector.h"

# define BUF_SIZE 546
# define B_0123 "111100000\n000111100\n"
# define B_0124 "111010000\n000111010\n"
# define B_0125 "111001000\n000111001\n"
# define B_0134 "110110000\n011011000\n000110110\n000011011\n"
# define B_0136 "110100100\n011010010\n"
# define B_0145 "110011000\n000110011\n"
# define B_0147 "110010010\n011001001\n"
# define B_0345 "100111000\n000100111\n"
# define B_0346 "100110100\n010011010\n"
# define B_0347 "100110010\n010011001\n"
# define B_0367 "100100110\n010010011\n"
# define B_1234 "011110000\n000011110\n"
# define B_1345 "010111000\n000010111\n"
# define B_1346 "010110100\n001011010\n"
# define B_1347 "010110010\n001011001\n"
# define B_1476 "010010110\n001001011\n"
# define B_2345 "001111000\n000001111\n"

int				is_valid_file(char *buf);
char			*read_file(char *file_name);
void			fillit(char *file_filit);
int				main_function(t_vector **vec, int c, char **str, int size);
int				check_tetr(char *buf);
void			sharp_to_char(char **buf);
char			*dell_slash_n(const char *content);
void			clear_matrix_line(t_node **node, int i);
int				check_tetra_matrix(int st, int size, t_node **node, int i);
char			*create_path(t_node **node);
void			null_for_matr_3(int i, t_node **node);
void			create_matr_for3(t_node **node, char ch);
void			move_to_up(char **new);
void			move_to_left(char **new);
void			move_to_vec(t_vector **vec, char *buf);
void			make_matrix(t_vector **vec, int size);
void			write_tetr(t_vector **vec, int size);
int				size_map(int size);
int				get_fill_map(t_vector **vec, char **str);
int				ft_sqrt(int n);
int				size_map(int size);
void			get_const(char **str, char *name);

#endif
