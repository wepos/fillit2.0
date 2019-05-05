/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnormdel.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdaemoni <gdaemoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 15:22:50 by gdaemoni          #+#    #+#             */
/*   Updated: 2019/04/23 13:20:41 by gdaemoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstnormdel(t_list *lst)
{
	t_list *p;

	while (lst->content)
	{
		p = lst->next;
		ft_lstnormdel(lst);
		lst = p->next;
	}
}
