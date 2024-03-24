/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_part1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eprzybyl <eprzybyl@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 08:49:16 by eprzybyl          #+#    #+#             */
/*   Updated: 2024/03/24 22:33:15 by eprzybyl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/push_swap.h"

void	push_b(t_v *v)
{
	t_lst	*ptr;

	ptr = v->a;
	if (ptr->next != NULL)
		v->a = ptr->next;
	else
		v->a = NULL;
	if (v->a != NULL)
		v->a->prev = NULL;
	if (v->b == NULL)
	{
		v->b = ptr;
		v->b->next = NULL;
	}
	else if (v->b != NULL)
	{
		ptr->next = v->b;
		v->b->prev = ptr;
		v->b = ptr;
		v->b->prev = NULL;
	}
	v->counter++;
	ft_printf("%s\n", "pb");
}

void	push_a(t_v *v)
{
	v->ptr = v->b;
	if (v->b->next != NULL)
	{
		v->b = v->b->next;
		v->b->prev = NULL;
	}
	else
	{
		v->b = NULL;
	}
	v->ptr->next = v->a;
	v->ptr->prev = NULL;
	v->a = v->ptr;
	v->counter++;
	ft_printf("%s\n", "pa");
}

void	rotate_a(t_v *v)
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
	v->counter++;
	ft_printf("%s\n", "ra");
}

void	rotate_b(t_v *v)
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
	v->counter++;
	ft_printf("%s\n", "rb");
}

void	swap_a(t_v *v)
{
	int	temp;

	temp = v->a->n;
	v->a->n = v->a->next->n;
	v->a->next->n = temp;
	v->counter++;
	ft_printf("%s\n", "sa");
}
