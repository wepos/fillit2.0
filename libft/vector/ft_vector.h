/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnancy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/26 17:54:37 by fnancy            #+#    #+#             */
/*   Updated: 2019/04/26 17:54:37 by fnancy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_FT_VECTOR_H
# define FILLIT_FT_VECTOR_H

# include "../libft.h"

typedef struct			s_node
{
	char				*content;
	int					content_size;
	int					tetr[4];
	char				**matrix;
	char				symbol;
	int					index;
	struct s_node		*next;
}						t_node;

typedef struct			s_vector
{
	struct s_node		*node;
	int					size;
}						t_vector;

t_vector				*ft_new_vector();
t_node					*ft_new_node(char *content, int content_size);
t_node					*ft_get_index(int index, t_vector **vec);
void					ft_add_node(t_node **node, t_vector **vec);

#endif
