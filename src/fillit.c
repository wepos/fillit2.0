/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdaemoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 15:39:32 by gdaemoni          #+#    #+#             */
/*   Updated: 2019/05/03 15:39:37 by gdaemoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

void	paint_map(int size, char **str)
{
	int i;

	i = 0;
	while ((*str)[i])
	{
		if (ft_isalpha((*str)[i]))
			ft_putchar((*str)[i]);
		else
			ft_putchar('.');
		if ((i + 1) % size == 0 && i != 0)
			ft_putchar('\n');
		i++;
	}
}

void	fillit(char *file_filit)
{
	char		*buf;
	t_vector	*vec;
	char		*str;
	int			size;

	buf = read_file(file_filit);
	if (is_valid_file(buf) == 0)
		return (ft_putstr("error\n"));
	move_to_vec(&vec, buf);
	size = size_map(vec->size);
	str = ft_memalloc((size * size) + 1);
	ft_memset(str, '0', (size * size));
	write_tetr(&vec, size);
	make_matrix(&vec, size);
	while (main_function(&vec, 0, &str, size) != 1)
	{
		ft_strdel(&str);
		size += 1;
		str = ft_memalloc((size * size) + 1);
		ft_memset(str, '0', (size * size));
		write_tetr(&vec, size);
		make_matrix(&vec, size);
	}
	paint_map(size, &str);
}
