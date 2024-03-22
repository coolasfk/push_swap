/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_actions_part2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eprzybyl <eprzybyl@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 13:05:32 by eprzybyl          #+#    #+#             */
/*   Updated: 2024/03/22 17:51:09 by eprzybyl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	rrotate_b2(t_ch *ch)
{
	ch->ptr = ch->b;
	ch->temp = ch->b;
	while (ch->temp->next != NULL)
		ch->temp = ch->temp->next;
	ch->node = ch->temp;
	ch->node->next = NULL;
	ch->b = ch->ptr;
	ch->temp = ch->b;
	while (ch->temp->next->next != NULL)
		ch->temp = ch->temp->next;
	ch->temp->next = NULL;
	ch->node->next = ch->b;
	ch->node->prev = NULL;
	ch->b = ch->node;
	ch->counter++;
	ch->b->prev = NULL;
	ft_printf("%s\n", "rrb");
}

void	rrr2(t_ch *ch)
{
	rrotate_b2(ch);
	rrotate_a2(ch);
	ft_printf("%s\n", "rrr");
}

void	rr2(t_ch *ch)
{
	rotate_b2(ch);
	rotate_a2(ch);
	ft_printf("%s\n", "rr");
}

void	rrotate_a2(t_ch *ch)
{
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
	ft_printf("%s\n", "rra");
	ch->counter++;
	ch->a->prev = NULL;
}
