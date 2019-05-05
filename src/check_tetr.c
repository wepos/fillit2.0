/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_tetr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdaemoni <gdaemoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 13:19:22 by gdaemoni          #+#    #+#             */
/*   Updated: 2019/04/24 13:21:19 by gdaemoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

int		first_check_tetr(int i, int count, char *buf, int res_second)
{
	if (count == 0 && (buf[i + 1] == '#'))
		res_second++;
	if (count == 0 && (buf[i + 5] == '#'))
		res_second++;
	if ((count != 0 && count < 4) && (buf[i - 1] == '#'))
		res_second++;
	if ((count != 0 && count < 4) && (buf[i + 1] == '#'))
		res_second++;
	if ((count != 0 && count < 4) && (buf[i + 5] == '#'))
		res_second++;
	if ((count > 4 && count < 14) && (buf[i - 1] == '#'))
		res_second++;
	if ((count > 4 && count < 14) && (buf[i + 1] == '#'))
		res_second++;
	if ((count > 4 && count < 14) && (buf[i - 5] == '#'))
		res_second++;
	if ((count > 4 && count < 14) && (buf[i + 5] == '#'))
		res_second++;
	if ((count > 14 && count < 19) && (buf[i - 1] == '#'))
		res_second++;
	if ((count > 14 && count < 19) && (buf[i + 1] == '#'))
		res_second++;
	if ((count > 14 && count < 19) && (buf[i - 5] == '#'))
		res_second++;
	return (res_second);
}

int		check_tetr(char *buf)
{
	int i;
	int count;
	int res_first;
	int res_second;

	i = -1;
	count = -1;
	res_first = 0;
	res_second = 12;
	while (buf[++i])
	{
		if (++count == 21)
		{
			if ((res_first != 6 && res_first != 8) || res_second == 0)
				return (0);
			count = 0;
			res_first = 0;
			res_second = 12;
		}
		if (buf[i] == '#')
			res_first = first_check_tetr(i, count, buf, res_first);
	}
	return (1);
}
