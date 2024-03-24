/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_actions_part3.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eprzybyl <eprzybyl@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 20:19:20 by eprzybyl          #+#    #+#             */
/*   Updated: 2024/03/24 23:29:07 by eprzybyl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ss2(t_ch *ch)
{
	if (!ch->b || ch->b->next == NULL || !ch->a || ch->a->next == NULL)
	{
		ft_printf("Error: %s\n", "Operation cannot be performed!");
		exit(1);
	}
	swap_b2(ch);
	swap_a2(ch);
}

void	perform_operations(char *line, t_ch *ch)
{
	if (ft_strcmp(line, "pb") == 0)
		push_b2(ch);
	else if (ft_strcmp(line, "pa") == 0)
		push_a2(ch);
	else if (ft_strcmp(line, "ra") == 0)
		rotate_a2(ch);
	else if (ft_strcmp(line, "rb") == 0)
		rotate_b2(ch);
	else if (ft_strcmp(line, "rra") == 0)
		rrotate_a2(ch);
	else if (ft_strcmp(line, "rrb") == 0)
		rrotate_b2(ch);
	else if (ft_strcmp(line, "rr") == 0)
		rr2(ch);
	else if (ft_strcmp(line, "rrr") == 0)
		rrr2(ch);
	else if (ft_strcmp(line, "sb") == 0)
		swap_b2(ch);
	else if (ft_strcmp(line, "sa") == 0)
		swap_a2(ch);
	else if (ft_strcmp(line, "ss") == 0)
		ss2(ch);
	else
		exit_message("KO: an instruction doesn’t exist", 1);
}

void	exit_message(char *str, int code)
{
	ft_printf("%s\n", str);
	exit(code);
}
