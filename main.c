/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eprzybyl <eprzybyl@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 11:57:39 by eprzybyl          #+#    #+#             */
/*   Updated: 2024/03/08 13:04:45 by eprzybyl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/push_swap.h"

void	initialize_var(t_v *v)
{
	v->check = 0;
	v->counter = 0;
	v->a = NULL;
	v->b = NULL;
	v->node = NULL;
	v->cost = 0;
	v->cost_a = 0;
	v->cost_b = 0;
	v->index_b = 0;
	v->index_a = 0;
	v->i = 1;
	v->diff = 2147483647;
	v->count = 0;
}

void	build_a(int argc, char *argv[], t_v *v)
{
	v->ptr = v->a;
	v->count = argc - 1;
	while (v->i < argc)
	{
		if (check_errors(argv[v->i], v->a))
			return ;
		v->node = (t_lst *)malloc(sizeof(t_lst));
		if (!v->node)
			return ;
		v->node->n = ft_atoi(argv[v->i]);
		v->node->next = NULL;
		if (v->a == NULL)
			v->a = v->node;
		else
		{
			v->node->prev = v->ptr;
			v->ptr->next = v->node;
		}
		v->ptr = v->node;
		v->i++;
	}
	if (check_for_duplicates(argc, argv, v))
		return ;
	choose_sort(v);
}

int	main(int argc, char *argv[])
{
	t_v	v;

	if (argc == 1 || (argc == 2 && !argv[1][0]))
	{
		return (1);
	}
	else if (argc > 2)
	{
		initialize_var(&v);
		build_a(argc, argv, &v);
	}
	else if (argc == 2)
	{
		initialize_var(&v);
		one_arg_only(argv, &v);
	}
}

void	one_arg_only(char *argv[], t_v *v)
{
	int			i;
	char		**s;
	long long	element;

	v->ptr = v->a;
	i = 0;
	element = 0;
	s = ft_split(argv[1], ' ');
	while (s[i] != NULL)
	{
		if (check_errors(s[i], v->a))
			return ;
		element = ft_atoi(s[i]);
		build_b(element, v);
		i++;
	}
	if (check_for_duplicates_one_arg(s, v))
		return ;
	v->count = i;
	choose_sort(v);
}

void	build_b(long long el, t_v *v)
{
	v->node = (t_lst *)malloc(sizeof(t_lst));
	if (!v->node)
		return ;
	v->node->n = el;
	v->node->next = NULL;
	if (v->a == NULL)
		v->a = v->node;
	else
	{
		v->node->prev = v->ptr;
		v->ptr->next = v->node;
	}
	v->ptr = v->node;
}
