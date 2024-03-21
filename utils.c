/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eprzybyl <eprzybyl@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 12:22:36 by eprzybyl          #+#    #+#             */
/*   Updated: 2024/03/21 19:33:09 by eprzybyl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/push_swap.h"

int	is_sorted(t_v *v)
{
	t_lst	*check;

	check = v->a;
	while (check->next != NULL)
	{
		if (check->n > check->next->n)
		{
			check = v->a;
			return (0);
		}
		check = check->next;
	}
	printf("--------counter: %d\n", v->counter);
	printf("--------count: %d\n", v->count);
	//print_list(v->a);
	exit(0);
	return (1);
}

void	free_leaks(t_lst **a)
{
	t_lst	*ptr;
	t_lst	*temp;

	if (a == NULL || *a == NULL)
		return ;
	ptr = *a;
	while (ptr->next != NULL)
	{
		temp = ptr;
		ptr = ptr->next;
		free(temp);
	}
	free(ptr);
	*a = NULL;
}

void	print_list(t_lst *a)
{
	t_lst	*ptr;

	ptr = a;
	ft_printf("print list %d\n", ptr->n);
	while (ptr->next != NULL)
	{
		ptr = ptr->next;
		ft_printf("print list %d\n", ptr->n);
	}
}

int	search_for_biggest(t_v *v)
{
	t_lst		*ptr;
	long long	biggest;
	int			index;
	int			temp_index;

	ptr = v->b;
	biggest = ptr->n;
	index = 0;
	temp_index = 0;
	while (ptr != NULL)
	{
		if (ptr->n <= biggest)
		{
			biggest = ptr->n;
			index = temp_index;
		}
		ptr = ptr->next;
		temp_index++;
	}
	return (index);
}

int	list_length(t_lst *l)
{
	int		length;
	t_lst	*ptr;

	length = 1;
	ptr = l;
	while (ptr->next != NULL)
	{
		length++;
		ptr = ptr->next;
	}
	return (length);
}
