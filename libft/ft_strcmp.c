/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eprzybyl <eprzybyl@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 23:30:21 by eprzybyl          #+#    #+#             */
/*   Updated: 2024/03/24 23:30:36 by eprzybyl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(char *s1, char *s2)
{
	const unsigned char	*s;
	const unsigned char	*p;

	s = (const unsigned char *)s1;
	p = (const unsigned char *)s2;
	while ((*s == *p) && *s)
	{
		s++;
		p++;
	}
	return (*s - *p);
}
