/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdaemoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 19:38:19 by gdaemoni          #+#    #+#             */
/*   Updated: 2019/05/03 19:38:22 by gdaemoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

void	malloc_matrix(int size, t_node **node)
{
	int i;

	i = 0;
	(*node)->matrix = (char **)malloc(sizeof(char *) * ((size * size) + 1));
	while (i < (size * size))
	{
		(*node)->matrix[i] = ft_strnew((size * size) + 1);
		(*node)->matrix[i] = ft_memset((*node)->matrix[i], '0', size * size);
		i++;
	}
	(*node)->matrix[i] = NULL;
}

void	fill_matrix(int size, t_node **node, char ch)
{
	int i;
	int st;
	int j;

	if (size == 3)
		return (create_matr_for3(&(*node), ch));
	st = -1;
	i = 0;
	(*node)->symbol = ch;
	while (i < (size * size) && ++st > -1)
	{
		j = check_tetra_matrix(st, size, &(*node), i);
		i++;
	}
}

void	trim_matrix(t_node **node, int size)
{
	int	i;
	int	k;

	i = 0;
	k = -1;
	while (i < size)
	{
		if ((*node)->matrix[i] == NULL)
			k = i;
		if (k == i)
		{
			while (k + 1 < size)
			{
				if ((*node)->matrix[k] != NULL)
				{
					(*node)->matrix[i] = (*node)->matrix[k];
					(*node)->matrix[k] = NULL;
					k = -1;
					break ;
				}
				k++;
			}
		}
		i++;
	}
}

void	make_matrix(t_vector **vec, int size)
{
	int		k;
	t_node	*node;
	char	ch;

	ch = 'A';
	k = 0;
	while (k < (*vec)->size)
	{
		node = ft_get_index(k, &(*vec));
		malloc_matrix(size, &node);
		fill_matrix(size, &node, ch++);
		trim_matrix(&node, size * size);
		k++;
	}
}
