/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_actions_part2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eprzybyl <eprzybyl@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 13:05:32 by eprzybyl          #+#    #+#             */
/*   Updated: 2024/03/24 23:26:03 by eprzybyl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	rrotate_b2(t_ch *ch)
{
	if (!ch->b || ch->b->next == NULL)
	{
		ft_printf("Error: %s\n", "Operation cannot be performed!");
		exit(1);
	}
	ch->ptr = ch->b;
	ch->temp = ch->b;
	while (ch->temp->next != NULL)
		ch->temp = ch->temp->next;
	ch->node = ch->temp;
	ch->node->next = NULL;
	ch->b = ch->ptr;
	ch->temp = ch->b;
	if (ch->temp->next->next)
	{
		while (ch->temp->next->next != NULL)
			ch->temp = ch->temp->next;
	}
	ch->temp->next = NULL;
	ch->node->next = ch->b;
	ch->node->prev = NULL;
	ch->b = ch->node;
	ch->b->prev = NULL;
}

void	rrr2(t_ch *ch)
{
	rrotate_b2(ch);
	rrotate_a2(ch);
}

void	rr2(t_ch *ch)
{
	if (!ch->b || ch->b->next == NULL)
	{
		ft_printf("Error: %s\n", "Operation cannot be performed!");
		exit(1);
	}
	rotate_b2(ch);
	rotate_a2(ch);
}

void	rrotate_a2(t_ch *ch)
{
	if (ch->a == NULL || ch->a->next == NULL)
	{
		ft_printf("Error: %s\n", "You cannot rra, it has only one element!");
		exit(1);
	}
	ch->ptr = ch->a;
	ch->temp = ch->a;
	while (ch->temp->next != NULL)
		ch->temp = ch->temp->next;
	ch->node = ch->temp;
	ch->node->next = NULL;
	ch->a = ch->ptr;
	ch->temp = ch->a;
	while (ch->temp->next->next != NULL)
		ch->temp = ch->temp->next;
	ch->temp->next = NULL;
	ch->a->prev = ch->node;
	ch->node->next = ch->a;
	ch->node->prev = NULL;
	ch->a = ch->node;
	ch->a->prev = NULL;
}

void	swap_b2(t_ch *ch)
{
	int	temp;

	if (!ch->b || ch->b->next == NULL)
	{
		ft_printf("Error: %s\n", "You cannot sb!");
		exit(1);
	}
	temp = ch->b->n;
	ch->b->n = ch->b->next->n;
	ch->b->next->n = temp;
}
