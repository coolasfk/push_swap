/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_make_list.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eprzybyl <eprzybyl@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 17:57:49 by eprzybyl          #+#    #+#             */
/*   Updated: 2024/03/23 12:57:58 by eprzybyl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	initialize_var2(t_ch *ch)
{
	ch->check = 0;
	ch->counter = 0;
	ch->a = NULL;
	ch->b = NULL;
	ch->node = NULL;
	ch->i = 1;
	ch->count = 0;
	ch->old_line = NULL;
	ch->temp_line = NULL;
	ch->new_line = NULL;
	ch->action_line = NULL;
}

void	build_a2(int argc, char *argv[], t_ch *ch)
{
	ch->ptr = ch->a;
	ch->count = argc - 1;
	while (ch->i < argc)
	{
		if (check_errors2(argv[ch->i], ch->a))
			return ;
		ch->node = (t_chl *)malloc(sizeof(t_chl));
		if (!ch->node)
			return ;
		ch->node->n = ft_atoi(argv[ch->i]);
		ch->node->next = NULL;
		if (ch->a == NULL)
			ch->a = ch->node;
		else
		{
			ch->node->prev = ch->ptr;
			ch->ptr->next = ch->node;
		}
		ch->ptr = ch->node;
		ch->i++;
	}
	if (check_for_duplicates2(argc, argv, ch))
		return ;
	read_from_terminal(ch);
}

void	one_arg_only2(char *argv[], t_ch *ch)
{
	int			i;
	char		**s;
	long long	element;

	ch->ptr = ch->a;
	i = 0;
	element = 0;
	s = ft_split(argv[1], ' ');
	while (s[i] != NULL)
	{
		if (check_errors2(s[i], ch->a))
			return ;
		element = ft_atoi(s[i]);
		build_b2(element, ch);
		i++;
	}
	if (check_for_duplicates_one_arg2(s, ch))
		return ;
	ch->count = i;
	read_from_terminal(ch);
}

void	build_b2(long long el, t_ch *ch)
{
	ch->node = (t_chl *)malloc(sizeof(t_chl));
	if (!ch->node)
		return ;
	ch->node->n = el;
	ch->node->next = NULL;
	if (ch->a == NULL)
		ch->a = ch->node;
	else
	{
		ch->node->prev = ch->ptr;
		ch->ptr->next = ch->node;
	}
	ch->ptr = ch->node;
}
