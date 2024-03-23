/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_part3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eprzybyl <eprzybyl@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 15:14:48 by eprzybyl          #+#    #+#             */
/*   Updated: 2024/03/23 16:59:20 by eprzybyl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rrotate_a1(t_v *v)
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
	v->a->prev = NULL;
}

void	rrotate_b1(t_v *v)
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
	v->b->prev = NULL;
}

void	rotate_a1(t_v *v)
{
	if (v->a == NULL || v->a->next == NULL)
		return ;
	v->temp = v->a;
	v->ptr = v->a;
	v->a = v->a->next;
	while (v->temp->next != NULL)
		v->temp = v->temp->next;
	v->temp->next = v->ptr;
	v->temp->next->next = NULL;
}

void	rotate_b1(t_v *v)
{
	if (v->b == NULL || v->b->next == NULL)
		return ;
	v->temp = v->b;
	v->ptr = v->b;
	v->b = v->b->next;
	while (v->temp->next != NULL)
		v->temp = v->temp->next;
	v->temp->next = v->ptr;
	v->temp->next->next = NULL;
}
