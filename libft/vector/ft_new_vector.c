/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new_vector.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnancy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/26 18:03:32 by fnancy            #+#    #+#             */
/*   Updated: 2019/04/26 18:03:32 by fnancy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"

t_vector		*ft_new_vector(void)
{
	t_vector	*ptr;

	if (!(ptr = (t_vector *)malloc(sizeof(t_vector))))
		return (NULL);
	ptr->size = 0;
	ptr->node = NULL;
	return (ptr);
}
