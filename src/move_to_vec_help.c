/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_to_vec_help.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnancy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 20:19:14 by fnancy            #+#    #+#             */
/*   Updated: 2019/05/07 20:19:14 by fnancy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

void		sharp_to_char(char **buf)
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

char		*dell_slash_n(const char *content)
{
	int		i;
	int		i2;
	char	*new;

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

void		move_to_up(char **new)
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

void		move_to_left(char **new)
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
