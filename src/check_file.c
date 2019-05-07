/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdaemoni <gdaemoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 13:13:05 by gdaemoni          #+#    #+#             */
/*   Updated: 2019/04/24 13:36:25 by gdaemoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

int		check_symbol(char c)
{
	if (c == '.')
		return (1);
	if (c == '#')
		return (1);
	if (c == '\n')
		return (1);
	return (0);
}

int		check_file(char *buf)
{
	int i;
	int dot;
	int sharp;
	int newstr;

	i = 0;
	dot = 0;
	sharp = 0;
	newstr = 0;
	while (buf[i])
	{
		if (!check_symbol(buf[i]))
			return (0);
		if (buf[i] == '.')
			dot++;
		if (buf[i] == '#')
			sharp++;
		if (buf[i++] == '\n')
			newstr++;
	}
	if ((i + 1) % 21 != 0)
		return (0);
	if (dot % 12 != 0 || sharp % 4 != 0 || (newstr + 1) % 5 != 0)
		return (0);
	return (1);
}

int		is_valid_file(char *buf)
{
	if (!buf)
		return (0);
	if (!check_file(buf))
		return (0);
	if (!check_tetr(buf))
		return (0);
	return (1);
}

char	*read_file(char *file_name)
{
	char	buf[BUF_SIZE];
	int		fd;
	int		rd;
	char	*dest;

	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		return (NULL);
	rd = read(fd, buf, BUF_SIZE);
	if (rd == 0)
	{
		close(fd);
		return (NULL);
	}
	close(fd);
	dest = (char*)malloc(sizeof(char) * (rd + 1));
	buf[rd] = '\0';
	ft_strcpy(dest, buf);
	return (dest);
}
