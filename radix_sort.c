/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbernard <jbernard@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 08:45:53 by jbernard          #+#    #+#             */
/*   Updated: 2022/02/15 10:01:02 by jbernard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_nb_byte(t_stack *s)
{
	int		i;

	i = 0;
	while (s->size >> i != 0)
		i++;
	return (i);
}

void	radix_sort(t_stack *s_a, t_stack *s_b)
{
	int		i;
	int		j;
	int		k;
	int		len;
	int		nb_byte;

	i = -1;
	len = s_a->size;
	nb_byte = find_nb_byte(s_a);
	while (++i < nb_byte)
	{
		j = -1;
		while (++j < len)
		{
			k = s_a->stack[0];
			if (((k >> i) & 1) == 1)
				rotate(s_a);
			else
				push_b(s_a, s_b);
		}
		while (s_b->stack[0] != 0)
			push_a(s_a, s_b);
	}
}
