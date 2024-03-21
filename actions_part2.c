/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_part2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eprzybyl <eprzybyl@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 13:05:32 by eprzybyl          #+#    #+#             */
/*   Updated: 2024/03/21 13:36:05 by eprzybyl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/push_swap.h"

void	rrotate_b(t_v *v)
{
	v->ptr = v->b;
	v->temp = v->b;
	while (v->temp->next != NULL)
		v->temp = v->temp->next;
	v->node = v->temp;
	v->node->next = NULL;
	v->b = v->ptr;
	v->temp = v->b;
	while (v->temp->next->next != NULL)
		v->temp = v->temp->next;
	v->temp->next = NULL;
	v->node->next = v->b;
	v->node->prev = NULL;
	v->b = v->node;
	v->counter++;
	v->b->prev = NULL;
	ft_printf("%s\n", "rrb");
}

void	rrr(t_v *v)
{
	rrotate_b(v);
	rrotate_a(v);
	ft_printf("%s\n", "rrr");
}

void	rr(t_v *v)
{
	rotate_b(v);
	rotate_a(v);
	ft_printf("%s\n", "rr");
}

void	rrotate_a(t_v *v)
{
	v->ptr = v->a;
	v->temp = v->a;
	while (v->temp->next != NULL)
		v->temp = v->temp->next;
	v->node = v->temp;
	v->node->next = NULL;
	v->a = v->ptr;
	v->temp = v->a;
	while (v->temp->next->next != NULL)
		v->temp = v->temp->next;
	v->temp->next = NULL;
	v->a->prev = v->node;
	v->node->next = v->a;
	v->node->prev = NULL;
	v->a = v->node;
	ft_printf("%s\n", "rra");
	v->counter++;
	v->a->prev = NULL;
}
