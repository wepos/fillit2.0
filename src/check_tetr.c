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

int		first_check_tetr(int i, int count, const char *buf, int res_second)
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
	int dot;
	int count;
	int res_first;

	i = -1;
	dot = 0;
	count = -1;
	res_first = 0;
	while (buf[++i])
	{
		if (++count == 21)
		{
			if ((res_first != 6 && res_first != 8) || (dot % 12) != 0)
				return (0);
			count = 0;
			res_first = 0;
		}
		if (buf[i] == '#')
			res_first = first_check_tetr(i, count, buf, res_first);
		(buf[i] == '.' ? dot++ : dot);
	}
	if ((res_first != 6 && res_first != 8))
		return (0);
	return (1);
}
