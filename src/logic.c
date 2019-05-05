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

int 	cmp_matr_line(char **str, char *str2)
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

/*
int     x_algoritm(t_vector **vec, char **str)
{
    int		i;
    t_node	*node;
    char 	**main_matrix;
    char	**matrix;
    int		count;

    main_matrix = (char**)malloc(sizeof(char*) * (*vec)->size * (*vec)->size);
    get_main_matrix(ft_get_index(0, &(*vec))->matrix, &main_matrix);
    i = 0;
    count = 0;
    while (i < (*vec)->size - 1)
    {
        node = ft_get_index(i, &(*vec));
        count +=
    }
}*/


int		main_function(t_vector **vec, int c, char **str)
{
	t_node  *node;
	int     i;
	char	*str2;

	str2 = ft_strnew(((*vec)->size * (*vec)->size) + 1);
	str2 = ft_strcpy(str2, (*str));
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
				return (1);
			if ((main_function(&(*vec), c + 1, &(*str)) == 1))
				return (1);
			(*str) = ft_strcpy((*str),str2);
		}
		i++;
	}
	return (0);
}
