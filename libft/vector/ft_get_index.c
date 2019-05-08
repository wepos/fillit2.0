/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_index.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnancy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/26 19:15:17 by fnancy            #+#    #+#             */
/*   Updated: 2019/04/26 19:15:17 by fnancy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"

t_node		*ft_get_index(int index, t_vector **vec)
{
	t_node	*tmp;

	tmp = (*vec)->node;
	if (index > (*vec)->size - 1)
		return (NULL);
	while (tmp->index != index)
		tmp = tmp->next;
	return (tmp);
}
