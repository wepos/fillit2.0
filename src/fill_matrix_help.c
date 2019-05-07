/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_matrix_help.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnancy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 22:30:58 by fnancy            #+#    #+#             */
/*   Updated: 2019/05/07 22:30:58 by fnancy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

void	clear_matrix_line(t_node **node, int i)
{
	ft_strdel(&(*node)->matrix[i]);
	(*node)->matrix[i] = NULL;
}

int		check_tetra_matrix(int st, int size, t_node **node, int i)
{
	int j;

	j = -1;
	while (++j < 4)
	{
		if ((((*node)->tetr[j] + st) % size) == 0 && j > 0)
		{
			if (((*node)->tetr[j] + st) - ((*node)->tetr[j - 1] + st) != 1
					&& (*node)->tetr[j] + st < (size * size))
				(*node)->matrix[i][(*node)->tetr[j] + st] = (*node)->symbol;
			else
			{
				clear_matrix_line(&(*node), i);
				return (-1);
			}
		}
		else if ((*node)->tetr[j] + st < (size * size))
			(*node)->matrix[i][(*node)->tetr[j] + st] = (*node)->symbol;
		else
		{
			clear_matrix_line(&(*node), i);
			return (-1);
		}
	}
	return (-1);
}
