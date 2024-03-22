/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_actions_part1.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eprzybyl <eprzybyl@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 08:49:16 by eprzybyl          #+#    #+#             */
/*   Updated: 2024/03/22 17:50:25 by eprzybyl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	push_b2(t_ch *ch)
{
	
	t_chl	*ptr;

ptr = ch->a;
	if (ptr->next != NULL)
		ch->a = ptr->next;
	else
		ch->a = NULL;
	if (ch->a != NULL)
		ch->a->prev = NULL;
	if (ch->b == NULL)
	{
		ch->b = ptr;
		ch->b->next = NULL;
	}
	else if (ch->b != NULL)
	{
		ptr->next = ch->b;
		ch->b->prev = ptr;
		ch->b = ptr;
		ch->b->prev = NULL;
	}
	ch->counter++;
	ft_printf("%s\n", "pb");
}

void	push_a2(t_ch *ch)
{
	ch->ptr = ch->b;
	if (ch->b->next != NULL)
	{
		ch->b = ch->b->next;
		ch->b->prev = NULL;
	}
	else
	{
		ch->b = NULL;
	}
	ch->ptr->next = ch->a;
	ch->ptr->prev = NULL;
	ch->a = ch->ptr;
	ch->counter++;
	ft_printf("%s\n", "pa");
}

void	rotate_a2(t_ch *ch)
{
	if (ch->a == NULL || ch->a->next == NULL)
		return ;
	ch->temp = ch->a;
	ch->ptr = ch->a;
	ch->a = ch->a->next;
	while (ch->temp->next != NULL)
		ch->temp = ch->temp->next;
	ch->temp->next = ch->ptr;
	ch->temp->next->next = NULL;
	ch->counter++;
	ft_printf("%s\n", "ra");
}

void	rotate_b2(t_ch *ch)
{
	if (ch->b == NULL || ch->b->next == NULL)
		return ;
	ch->temp = ch->b;
	ch->ptr = ch->b;
	ch->b = ch->b->next;
	while (ch->temp->next != NULL)
		ch->temp = ch->temp->next;
	ch->temp->next = ch->ptr;
	ch->temp->next->next = NULL;
	ch->counter++;
	ft_printf("%s\n", "rb");
}

void	swap_a2(t_ch *ch)
{
	int	temp;

	temp = ch->a->n;
	ch->a->n = ch->a->next->n;
	ch->a->next->n = temp;
	ch->counter++;
	ft_printf("%s\n", "sa");
}
