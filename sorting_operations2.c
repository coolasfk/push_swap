/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_operations2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eprzybyl <eprzybyl@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 22:59:44 by eprzybyl          #+#    #+#             */
/*   Updated: 2024/03/24 22:32:17 by eprzybyl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_loop(t_v *v)
{
	v->rounds = 0;
	v->index = 0;
	v->ptr = v->a;
	v->smallest = v->ptr->n;
	while (v->ptr != NULL)
	{
		if (v->ptr->n < v->smallest)
		{
			v->smallest = v->ptr->n;
			v->index = v->rounds;
		}
		v->rounds++;
		v->ptr = v->ptr->next;
	}
	v->ptr = v->a;
	operations_sort_five(v);
	push_b(v);
}

void	operations_sort_five(t_v *v)
{
	if (v->index <= v->rounds / 2)
	{
		while (v->index-- && !is_sorted(v))
			rotate_a(v);
	}
	else
	{
		while (v->rounds - v->index > 0 && !is_sorted(v))
		{
			rrotate_a(v);
			v->index++;
		}
	}
}

void	sort_five(t_v *v)
{
	v->sort_five = 1;
	sort_loop(v);
	v->ptr = v->a;
	while (v->count-- > 4)
		sort_loop(v);
	v->ptr = v->a;
	sort_three(v);
}

void	sadly_put_it_back(t_v *v)
{
	while (v->b->next != NULL)
		push_a(v);
	push_a(v);
}
