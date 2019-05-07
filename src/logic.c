/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logic.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdaemoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/04 18:12:52 by gdaemoni          #+#    #+#             */
/*   Updated: 2019/05/04 18:12:54 by gdaemoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

int		cmp_matr_line(char **str, char *str2)
{
	int i;

	i = 0;
	while ((*str)[i])
	{
		if (ft_isalpha((*str)[i]) && ft_isalpha(str2[i]))
			return (0);
		i++;
	}
	i = 0;
	while (str2 != NULL && str2[i])
	{
		if (ft_isalpha(str2[i]))
			(*str)[i] = str2[i];
		i++;
	}
	return (1);
}

int		free_and_return(char **str)
{
	ft_memdel((void *)&(*str));
	return (1);
}

int		main_function(t_vector **vec, int c, char **str, int size)
{
	t_node	*node;
	int		i;
	char	*str2;

	str2 = ft_memalloc((size * size) + 1);
	str2 = ft_memmove(str2, (*str), size * size);
	i = 0;
	if (c != (*vec)->size)
		node = ft_get_index(c, &(*vec));
	else
		return (0);
	while (node->matrix[i])
	{
		if (cmp_matr_line(&(*str), node->matrix[i]) == 1)
		{
			if (c + 1 == (*vec)->size)
				return (free_and_return(&str2));
			if ((main_function(&(*vec), c + 1, &(*str), size) == 1))
				return (free_and_return(&str2));
			(*str) = ft_memmove((*str), str2, size * size);
		}
		i++;
	}
	ft_memdel((void *)&str2);
	return (0);
}
