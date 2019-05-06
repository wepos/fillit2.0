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
# include "../vector/ft_vector.h"

#define BUF_SIZE 546

int				is_valid_file(char *buf);
char			*read_file(char *file_name);
void			fillit(char *file_filit);
int				main_function(t_vector **vec, int c, char **str, int size);
int				check_tetr(char *buf);
void			move_to_vec(t_vector **vec, char *buf);
void			make_matrix(t_vector **vec, int size);
void			write_tetr(t_vector **vec, int size);
int				size_map(int size);
int				get_fill_map(t_vector **vec, char **str);

#endif
