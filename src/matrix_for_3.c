/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_for_3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnancy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 22:00:13 by fnancy            #+#    #+#             */
/*   Updated: 2019/05/07 22:00:13 by fnancy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

char	*create_path(t_node **node)
{
	char	*result;
	int		j;

	result = ft_strnew(18);
	result = ft_strcat(result, "./filesfor3/");
	j = 0;
	while (j < 4)
	{
		result = ft_strcat(result, ft_itoa((*node)->tetr[j]));
		j++;
	}
	return (result);
}

void	null_for_matr_3(int i, t_node **node)
{
	while (i < 9)
	{
		(*node)->matrix[i] = NULL;
		i++;
	}
}

void	create_matr_for3(t_node **node, char ch)
{
	char	*file;
	char	buf[10];
	int		i;
	int		j;
	int		fd;

	i = 0;
	file = create_path(&(*node));
	if ((fd = open(file, O_RDONLY)) > 0)
	{
		while (read(fd, buf, 9) > 0)
		{
			j = -1;
			while (++j < 9)
				if (buf[j] == '1')
					(*node)->matrix[i][j] = ch;
			(*node)->matrix[i][10] = '\0';
			read(fd, buf, 1);
			i++;
		}
		null_for_matr_3(i, &(*node));
	}
	else
		null_for_matr_3(i, &(*node));
	close(fd);
}
