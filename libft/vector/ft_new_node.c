/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new_node.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnancy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/26 18:14:03 by fnancy            #+#    #+#             */
/*   Updated: 2019/04/26 18:14:03 by fnancy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"

t_node		*ft_new_node(char *content, int content_size)
{
	t_node	*ptr;

	if (!(ptr = (t_node*)malloc(sizeof(t_node))))
		return (NULL);
	ptr->content = ft_strnew(content_size + 1);
	ft_strcpy(ptr->content, content);
	ptr->content_size = content_size;
	ptr->matrix = NULL;
	ptr->next = NULL;
	ptr->symbol = '0';
	return (ptr);
}
