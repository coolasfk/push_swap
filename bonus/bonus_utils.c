/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eprzybyl <eprzybyl@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 14:58:29 by eprzybyl          #+#    #+#             */
/*   Updated: 2024/03/23 22:39:02 by eprzybyl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	check_errors2(char *arg, t_chl *a)
{
	int	i;

	i = 0;
	while (arg[i] != '\0')
	{
		if ((arg[i] < 48 && arg[0] != '-') || (arg[i] > 57 && arg[0] != '-'))
		{
			ft_printf("%s\n", "Error");
			if (a != NULL)
				free_leaks2(&a);
			exit (1);
		}
		i++;
	}
	return (0);
}

int	check_for_duplicates2(int argc, char *argv[], t_ch *ch)
{
	int	count;

	ch->i = 1;
	ch->count = argc - 1;
	while (ch->i < argc)
	{
		ch->ptr = ch->a;
		count = 0;
		while (ch->ptr != NULL)
		{
			if (ch->ptr->n == ft_atoi(argv[ch->i]))
				count++;
			if (count == 2)
			{
				free_leaks2(&ch->a);
				ft_printf("%s\n", "Error");
				exit(0);
			}
			ch->ptr = ch->ptr->next;
		}
		ch->i++;
	}
	return (0);
}

int	check_for_duplicates_one_arg2(char **s, t_ch *ch)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i] != NULL)
	{
		count = 0;
		ch->ptr = ch->a;
		while (ch->ptr != NULL)
		{
			if (ch->ptr->n == ft_atoi(s[i]))
				count++;
			if (count == 2)
			{
				free_leaks2(&ch->a);
				ft_printf("%s\n", "Error");
				exit(0);
			}
			ch->ptr = ch->ptr->next;
		}
		i++;
	}
	return (0);
}
