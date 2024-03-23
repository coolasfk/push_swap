/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_top_level.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eprzybyl <eprzybyl@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 12:18:00 by eprzybyl          #+#    #+#             */
/*   Updated: 2024/03/23 23:04:08 by eprzybyl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/push_swap.h"

void	choose_sort(t_v *v)
{
	if (is_sorted(v))
		return ;
	if (v->count <= 3)
		sort_three(v);
	else if (v->count <= 5)
		sort_five(v);
	else if (v->count > 5)
		sort_more(v);
	if (v->a != NULL)
		free_leaks(&v->a);
}

void	sort_three(t_v *v)
{
	while (!is_sorted(v))
	{
		v->ptr = v->a;
		if (v->ptr->n > v->ptr->next->n && !is_sorted(v))
			swap_a(v);
		if (is_sorted(v))
			return ;
		v->ptr = v->a;
		if ((v->ptr->n > v->ptr->next->next->n
				|| v->ptr->next->n > v->ptr->next->next->n) && !is_sorted(v))
			rrotate_a(v);
	}
}

void	sort_five(t_v *v)
{
	sort_loop(v);
	v->ptr = v->a;
	if (is_sorted(v))
		return ;
	while (v->count-- > 4)
		sort_loop(v);
	v->ptr = v->a;
	sort_three(v);
	while (v->b != NULL)
		push_a(v);
	print_list(v->a);
}

void	sort_more(t_v *v)
{
	v->ptr = v->a;
	push_b(v);
	while (list_length(v->a) > 1)
	{
		v->temp_index_a = 0;
		calc_cost(v);
		operations(v);	
		push_b(v);
	
	}
	v->temp_index_a = 0;
	calc_cost(v);
	operations(v);
	push_b(v);
	push_last_and_sort(v);
	sadly_put_it_back(v);
	is_sorted(v);
}

void	sadly_put_it_back(t_v *v)
{
	
	while (v->b->next != NULL)
	{
		push_a(v);
	}
	push_a(v);
	
}

void	calc_cost(t_v *v)
{
	v->ptr = v->a;
	v->total_cost = 2147483647;
	while (v->ptr != NULL)
	{
		if (v->temp_index_a <= list_length(v->a) / 2)
			v->cost_a = v->temp_index_a;
		else
			v->cost_a = list_length(v->a) - v->temp_index_a;
		v->diff = 2147483647;
		inner_loop(v);
		if (v->temp_index_b <= list_length(v->b) / 2)
			v->cost_b = v->temp_index_b;
		else if (v->temp_index_b > list_length(v->b) / 2)
			v->cost_b = list_length(v->b) - v->temp_index_b;
		v->temp_cost = v->cost_b + v->cost_a;
		if (v->total_cost >= v->temp_cost || v->total_cost == 2147483647)
		{
			v->total_cost = v->temp_cost;
			v->index_b = v->temp_index_b;
			v->index_a = v->temp_index_a;
		}
		v->temp_index_a++;
		v->ptr = v->ptr->next;
	}
}

void	inner_loop(t_v *v)
{
	v->biggest = 0;
	v->index_b_loop = 0;
	v->temp = v->b;
	v->diff = 2147483647;
	while (v->temp != NULL)
	{
		if (v->temp->n <= v->ptr->n)
		{
			if (v->diff == 2147483647 ||  v->ptr->n - v->temp->n <= v->diff)
			{
				v->diff = v->ptr->n - v->temp->n;
				v->temp_index_b = v->index_b_loop;
			}
		}
		v->index_b_loop++;
		v->temp = v->temp->next;
	}
	// ft_printf("****v->temp_index_b %d\n", v->temp_index_b);
	if (v->diff == 2147483647)
		number_is_smaller(v);
}
