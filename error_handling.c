/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eprzybyl <eprzybyl@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 12:13:50 by eprzybyl          #+#    #+#             */
/*   Updated: 2024/03/21 15:23:36 by eprzybyl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/push_swap.h"

int	check_errors(char *arg, t_lst *a)
{
	int	i;

	i = 0;
	while (arg[i] != '\0')
	{
		if ((arg[i] < 48 && arg[0] != '-') || (arg[i] > 57 && arg[0] != '-'))
		{
			ft_printf("%s\n", "Error");
			if (a != NULL)
				free_leaks(&a);
			return (1);
		}
		i++;
	}
	return (0);
}

int	check_for_duplicates(int argc, char *argv[], t_v *v)
{
	int	count;

	v->i = 1;
	v->count = argc - 1;
	while (v->i < argc)
	{
		v->ptr = v->a;
		count = 0;
		while (v->ptr != NULL)
		{
			if (v->ptr->n == ft_atoi(argv[v->i]))
				count++;
			if (count == 2)
			{
				free_leaks(&v->a);
				ft_printf("%s\n", "Error");
				exit(0);
			}
			v->ptr = v->ptr->next;
		}
		v->i++;
	}
	return (0);
}

int	check_for_duplicates_one_arg(char **s, t_v *v)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i] != NULL)
	{
		count = 0;
		v->ptr = v->a;
		while (v->ptr != NULL)
		{
			if (v->ptr->n == ft_atoi(s[i]))
				count++;
			if (count == 2)
			{
				free_leaks(&v->a);
				ft_printf("%s\n", "Error");
				exit(0);
			}
			v->ptr = v->ptr->next;
		}
		i++;
	}
	return (0);
}
