/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnancy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 22:02:05 by fnancy            #+#    #+#             */
/*   Updated: 2019/05/07 22:02:05 by fnancy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

int		ft_sqrt(int n)
{
	int i;
	int iter;

	i = 1;
	iter = n / 2;
	while (i < iter)
	{
		if ((i * i) >= n)
			return (i);
		i++;
	}
	return (i);
}

int		size_map(int size)
{
	int rez;

	rez = size * 4;
	return (ft_sqrt(rez));
}
