/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_actions_part1.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eprzybyl <eprzybyl@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 08:49:16 by eprzybyl          #+#    #+#             */
/*   Updated: 2024/03/24 22:40:18 by eprzybyl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	push_b2(t_ch *ch)
{
	t_chl	*ptr;

	if (!ch->a)
		exit_message("Operation cannot be performed!", 1);
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
}

void	push_a2(t_ch *ch)
{
	if (!ch->b)
	{
		ft_printf("Error: %s\n", "Operation cannot be performed!");
		exit(1);
	}
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
}

void	rotate_a2(t_ch *ch)
{
	if (!ch->a || ch->a->next == NULL)
	{
		ft_printf("Error: %s\n", "You cannot ra, it has only one element!");
		exit(1);
	}
	if (ch->a == NULL || ch->a->next == NULL)
		return ;
	ch->temp = ch->a;
	ch->ptr = ch->a;
	ch->a = ch->a->next;
	while (ch->temp->next != NULL)
		ch->temp = ch->temp->next;
	ch->temp->next = ch->ptr;
	ch->temp->next->next = NULL;
}

void	rotate_b2(t_ch *ch)
{
	if (!ch->b || ch->b->next == NULL)
	{
		ft_printf("Error: %s\n", "You cannot rb!");
		exit(1);
	}
	if (ch->b == NULL || ch->b->next == NULL)
		return ;
	ch->temp = ch->b;
	ch->ptr = ch->b;
	ch->b = ch->b->next;
	while (ch->temp->next != NULL)
		ch->temp = ch->temp->next;
	ch->temp->next = ch->ptr;
	ch->temp->next->next = NULL;
}

void	swap_a2(t_ch *ch)
{
	int	temp;

	if (!ch->a || ch->a->next == NULL)
	{
		ft_printf("Error: %s\n", "You cannot sa!");
		exit(1);
	}
	temp = ch->a->n;
	ch->a->n = ch->a->next->n;
	ch->a->next->n = temp;
}
