/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_operations.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eprzybyl <eprzybyl@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 12:18:47 by eprzybyl          #+#    #+#             */
/*   Updated: 2024/03/24 22:31:28 by eprzybyl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/push_swap.h"

void	push_last_and_sort(t_v *v)
{
	int	index;

	index = search_for_biggest(v);
	if (index <= list_length(v->b) / 2)
	{
		while (index > 0)
		{
			rotate_b(v);
			index--;
		}
	}
	else
	{
		while (list_length(v->b) - index > 0)
		{
			rrotate_b(v);
			index++;
		}
	}
}

void	number_is_smaller(t_v *v)
{
	v->temp = v->b;
	v->index_b_loop = 0;
	v->biggest = v->temp->n;
	while (v->temp != NULL)
	{
		if (v->temp->n > v->biggest)
		{
			v->biggest = v->temp->n;
			v->temp_index_b = v->index_b_loop;
			v->diff = 0;
		}
		v->index_b_loop++;
		v->temp = v->temp->next;
	}
	if (v->diff != 0)
		v->temp_index_b = 0;
}

void	rrr_rr_check(t_v *v)
{
	if ((v->index_a <= list_length(v->a) / 2)
		&& (v->index_b <= list_length(v->b) / 2))
	{
		while (v->index_a > 0 && v->index_b > 0)
		{
			rr(v);
			v->index_a--;
			v->index_b--;
		}
	}
	if ((v->index_a > list_length(v->a) / 2) && (v->index_b > list_length(v->b)
			/ 2))
	{
		while ((list_length(v->b) - v->index_b > 0) && (list_length(v->a)
				- v->index_a > 0))
		{
			rrr(v);
			v->index_a++;
			v->index_b++;
		}
	}
}

void	v_a_operations(t_v *v)
{
	if (v->index_a <= list_length(v->a) / 2)
	{
		while (v->index_a > 0)
		{
			rotate_a(v);
			v->index_a--;
		}
	}
	else
	{
		while (list_length(v->a) - v->index_a > 0)
		{
			rrotate_a(v);
			v->index_a++;
		}
	}
}

void	operations(t_v *v)
{
	rrr_rr_check(v);
	v_a_operations(v);
	if (v->index_b <= list_length(v->b) / 2)
	{
		while (v->index_b > 0)
		{
			rotate_b(v);
			v->index_b--;
		}
	}
	else
	{
		while (list_length(v->b) - v->index_b > 0)
		{
			rrotate_b(v);
			v->index_b++;
		}
	}
}
