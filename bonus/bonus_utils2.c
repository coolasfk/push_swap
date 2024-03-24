/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eprzybyl <eprzybyl@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 22:39:07 by eprzybyl          #+#    #+#             */
/*   Updated: 2024/03/24 23:31:54 by eprzybyl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	free_leaks2(t_chl **a)
{
	t_chl	*ptr;
	t_chl	*temp;

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

void	print_list2(t_chl *a)
{
	t_chl	*ptr;

	ptr = a;
	ft_printf("print list %d\n", ptr->n);
	while (ptr->next != NULL)
	{
		ptr = ptr->next;
		ft_printf("print list %d\n", ptr->n);
	}
}

void	error_handling2(int code)
{
	if (code == 1)
		ft_printf("%s\n", "wrong number of arguments");
	exit(0);
}

int	list_length2(t_chl *l)
{
	int		length;
	t_chl	*ptr;

	length = 1;
	ptr = l;
	while (ptr->next != NULL)
	{
		length++;
		ptr = ptr->next;
	}
	return (length);
}
