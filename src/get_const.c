/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_const.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnancy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/14 14:42:06 by fnancy            #+#    #+#             */
/*   Updated: 2019/05/14 14:42:06 by fnancy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

void	get_const_2(char **str, char *name)
{
	if (ft_strcmp(name, "B_0367") == 0)
		*str = B_0367;
	if (ft_strcmp(name, "B_1234") == 0)
		*str = B_1234;
	if (ft_strcmp(name, "B_1345") == 0)
		*str = B_1345;
	if (ft_strcmp(name, "B_1346") == 0)
		*str = B_1346;
	if (ft_strcmp(name, "B_1347") == 0)
		*str = B_1347;
	if (ft_strcmp(name, "B_1467") == 0)
		*str = B_1467;
	if (ft_strcmp(name, "B_2345") == 0)
		*str = B_2345;
}

void	get_const(char **str, char *name)
{
	if (ft_strcmp(name, "B_0123") == 0)
		*str = B_0123;
	if (ft_strcmp(name, "B_0124") == 0)
		*str = B_0124;
	if (ft_strcmp(name, "B_0125") == 0)
		*str = B_0125;
	if (ft_strcmp(name, "B_0134") == 0)
		*str = B_0134;
	if (ft_strcmp(name, "B_0136") == 0)
		*str = B_0136;
	if (ft_strcmp(name, "B_0145") == 0)
		*str = B_0145;
	if (ft_strcmp(name, "B_0147") == 0)
		*str = B_0147;
	if (ft_strcmp(name, "B_0345") == 0)
		*str = B_0345;
	if (ft_strcmp(name, "B_0346") == 0)
		*str = B_0346;
	if (ft_strcmp(name, "B_0347") == 0)
		*str = B_0347;
	get_const_2(&(*str), name);
}
