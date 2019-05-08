/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_node.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnancy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/26 18:21:43 by fnancy            #+#    #+#             */
/*   Updated: 2019/04/26 18:21:43 by fnancy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"

void	ft_add_node(t_node **node, t_vector **vec)
{
	(*node)->index = (*vec)->size;
	if (!((*vec)->node))
		(*node)->next = NULL;
	else
		(*node)->next = (*vec)->node;
	(*vec)->node = (*node);
	(*vec)->size += 1;
}
