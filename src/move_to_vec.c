/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_to_vec.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdaemoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 17:54:26 by gdaemoni          #+#    #+#             */
/*   Updated: 2019/05/03 17:54:29 by gdaemoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

void	sharp_to_char(char	**buf)
{
	int		i;
	int		count;
	char	liter;

	i = 0;
	count = 0;
	liter = 'A';
	while ((*buf)[i])
	{
		if ((*buf)[i] == '#')
		{
			(*buf)[i] = liter;
			count++;
		}
		if (count == 4)
		{
			count = 0;
			liter++;
		}
		i++;
	}
}

char	*dell_slash_n(const char *content)
{
	int 	i;
	int 	i2;
	char *new;

	i = 0;
	i2 = 0;
	new = ft_strnew(17);
	while (content[i])
	{
		if (content[i] != '\n')
		{
			new[i2] = content[i];
			i2++;
		}
		i++;
	}
	return (new);
}

void	move_to_up(char **new)
{
	int i;

	i = 0;
	while ((*new)[i])
	{
		if (ft_isalpha((*new)[i]) && (i - 4) < 0)
			return ;
		if (ft_isalpha((*new)[i]) && (i - 4) >= 0)
		{
			(*new)[i - 4] = (*new)[i];
			(*new)[i] = '.';
		}
		i++;
	}
}

void	move_to_left(char **new)
{
	int i;
	int fl;

	i = 0;
	fl = 1;
	while ((*new)[i])
	{
		if (ft_isalpha((*new)[i]) && (i == 0 || i == 4 || i == 8 || i == 12))
			fl = 0;
		i++;
	}
	i = 0;
	if (fl)
		while ((*new)[i])
		{
			if (ft_isalpha((*new)[i]))
			{
				(*new)[i - 1] = (*new)[i];
				(*new)[i] = '.';
			}

			i++;
		}
}

void	write_tetr(t_vector **vec, int size)
{
	int i;
	int k;
	int	c;

	c = -1;
	while (++c < (*vec)->size && (k = 0) == 0 && (i = 0) == 0)
	{
		while (i < 16)
		{
			if (ft_isalpha(ft_get_index(c, &(*vec))->content[i]))
			{
				if (i < 4)
					ft_get_index(c, &(*vec))->tetr[k] = i;
				if (i >= 4 && i <= 7)
					ft_get_index(c, &(*vec))->tetr[k] = i + (size - 4);
				if (i >= 8 && i <= 11)
					ft_get_index(c, &(*vec))->tetr[k] = i + ((size - 4) * 2);
				if (i >= 12 && i <= 15)
					ft_get_index(c, &(*vec))->tetr[k] = i + ((size - 4) * 3);
				k++;
			}
			if (k == 4)
				break ;
			i++;
		}
	}
}

void	move_to_left_and_up(t_node **node)
{
	int 	i;
	char *new;

	i = 0;
	new = dell_slash_n((*node)->content);
	while (i < 4)
	{
		move_to_up(&new);
		move_to_left(&new);
		i++;
	}
	ft_strdel(&(*node)->content);
	(*node)->content = new;
}

void	move_to_vec(t_vector **vec, char *buf)
{
	int		i;
	char 	*str;
	t_node	*node;

	i = 0;
	sharp_to_char(&buf);
	(*vec) = ft_new_vector();
	while (buf[i])
	{
		if (i % 21 == 0 && i != 0)
		{
			str = ft_strsub(buf, i - 21, 19);
			node = ft_new_node(str, 21);
			move_to_left_and_up(&node);
			ft_add_node(&node, &(*vec));
			ft_strdel(&str);
		}
		i++;
	}
	str = ft_strsub(buf, i - 20, 19);
	node = ft_new_node(str, 21);
	move_to_left_and_up(&node);
	ft_add_node(&node, &(*vec));
	ft_strdel(&str);
}
