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

	result = ft_strnew(7);
	result = ft_strcat(result, "B_");
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
	char	*name;
	int		i;
	int		j;
	int		k;

	i = -1;
	j = 0;
	k = 0;
	name = create_path(&(*node));
	get_const(&file, name);
	while (file[++i])
	{
		(*node)->matrix[j][10] = '\0';
		if (file[i] != '\n')
			if (file[i] == '1')
				(*node)->matrix[j][k] = ch;
			else
				(*node)->matrix[j][k] = '.';
		else if ((k = -1))
			j++;
		k++;
	}
	return (null_for_matr_3(j, &(*node)));
}
