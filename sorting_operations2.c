/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_operations2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eprzybyl <eprzybyl@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 22:59:44 by eprzybyl          #+#    #+#             */
/*   Updated: 2024/03/23 23:00:04 by eprzybyl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_loop(t_v *v)
{
	int	smallest;
	int	rounds;
	int	index;

	rounds = 0;
	index = 0;
	v->ptr = v->a;
	smallest = v->ptr->n;
	while (v->ptr != NULL)
	{
		if (v->ptr->n < smallest)
		{
			smallest = v->ptr->n;
			index = rounds;
		}
		rounds++;
		v->ptr = v->ptr->next;
	}
	v->ptr = v->a;
	if (index <= rounds / 2)
	{
		while (index-- && !is_sorted(v))
			rotate_a(v);
	}
	else
	{
		while (rounds - index > 0 && !is_sorted(v))
		{
			rrotate_a(v);
			index++;
		}
	}
	if (is_sorted(v))
		return ;
	push_b(v);
}
