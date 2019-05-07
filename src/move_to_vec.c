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

void		do_it_write(t_node **node, int i, int size, int *k)
{
	if (ft_isalpha((*node)->content[i]))
	{
		if (i < 4)
			(*node)->tetr[*k] = i;
		if (i >= 4 && i <= 7)
			(*node)->tetr[*k] = i + (size - 4);
		if (i >= 8 && i <= 11)
			(*node)->tetr[*k] = i + ((size - 4) * 2);
		if (i >= 12 && i <= 15)
			(*node)->tetr[*k] = i + ((size - 4) * 3);
		(*k)++;
	}
}

void		write_tetr(t_vector **vec, int size)
{
	int		i;
	int		k;
	int		c;
	t_node	*node;

	c = -1;
	while (++c < (*vec)->size && (k = 0) == 0)
	{
		i = -1;
		while (++i < 16)
		{
			node = ft_get_index(c, &(*vec));
			do_it_write(&node, i, size, &k);
			if (k == 4)
				break ;
		}
	}
}

void		move_to_left_and_up(t_node **node)
{
	int		i;
	char	*new;

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

void		move_to_vec(t_vector **vec, char *buf)
{
	int		i;
	char	*str;
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
