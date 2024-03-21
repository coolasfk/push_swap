/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eprzybyl <eprzybyl@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 14:13:41 by eprzybyl          #+#    #+#             */
/*   Updated: 2024/03/07 23:34:57 by eprzybyl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long long	ft_atoi(const char *s)
{
	int			minus;
	long long	num;

	num = 0;
	minus = 1;
	while ((*s >= 9 && *s <= 13) || *s == ' ')
		s++;
	if (*s == '+' || *s == '-')
	{
		if (*s == '-')
			minus *= -1;
		s++;
	}
	while (ft_isdigit(*s))
	{
		num = (num * 10) + (*s - 48);
		s++;
	}
	num *= minus;
	is_min_max(num);
	return (num);
}

void	is_min_max(long long num)
{
	if (num > 2147483647 || num < -2147483648)
	{
		printf("%s\n", "Error");
		exit(0);
	}
}
