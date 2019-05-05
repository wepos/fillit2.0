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


void	error(int er)
{
	ft_putstr("error ");
	ft_putnbr(er);
	ft_putchar('\n');
}

void	put_tetr(char *content)
{
	int i;

	i = 0;
	while (content[i])
	{
		if ((i % 4) == 0 && i >= 4)
			ft_putchar('\n');
		ft_putchar(content[i]);
		i++;
	}
	ft_putchar('\n');
	ft_putchar('\n');
}

void	paint_map(int size, char **str)
{
	int i;

	i = 0;
	while((*str)[i])
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

	if (is_valid_file((buf = read_file(file_filit, buf))) == 0)
	{
		error(1);
		ft_strdel(&buf);
	}
	move_to_vec(&vec, buf);
	size = size_map(vec->size);
	str = ft_strnew((size * size) + 1);
	ft_memset(str, '0', (size * size));
	write_tetr(&vec, size);
	make_matrix(&vec, size);

//	while(main_function(&vec, 0, &str) != 1)
//	{
//		free(str);
//		size += 1;
//		str = ft_strnew((size * size) + 1);
//		ft_memset(str, '0', (size * size));
//		write_tetr(&vec, size);
//		make_matrix(&vec, size);
//	}
//	printf("%s\n", str);
//	paint_map(size, &str);
//	ft_put_double_array(ft_get_index(0, &vec)->matrix);

//	printf("\n%d - %d - %d - %d\n", ft_get_index(2, &vec)->tetr[0],ft_get_index(2, &vec)->tetr[1],ft_get_index(2, &vec)->tetr[2],ft_get_index(2, &vec)->tetr[3]);
//	put_tetr(ft_get_index(2, &vec)->content);
//	printf("\n%d - %d - %d - %d\n", ft_get_index(1, &vec)->tetr[0],ft_get_index(1, &vec)->tetr[1],ft_get_index(1, &vec)->tetr[2],ft_get_index(1, &vec)->tetr[3]);
//	put_tetr(ft_get_index(1, &vec)->content);
//	printf("\n%d - %d - %d - %d\n", ft_get_index(0, &vec)->tetr[0],ft_get_index(0, &vec)->tetr[1],ft_get_index(0, &vec)->tetr[2],ft_get_index(0, &vec)->tetr[3]);
//	put_tetr(ft_get_index(0, &vec)->content);

}