/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eprzybyl <eprzybyl@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 20:39:31 by eprzybyl          #+#    #+#             */
/*   Updated: 2024/01/25 20:41:53 by eprzybyl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	find_len(char *s1, char *s2)
{
	size_t	len;

	len = 0;
	if (s1 != NULL)
		len = ft_strlen(s1) + ft_strlen(s2);
	else
		len = ft_strlen(s2);
	return (len);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	len;
	char	*new;
	size_t	i;
	size_t	c;

	i = 0;
	c = 0;
	if (!s2)
		return (NULL);
	len = find_len(s1, s2);
	new = (char *)malloc(len * sizeof(char) + 1);
	if (!new)
		return (NULL);
	if (s1 != NULL)
		while (i < ft_strlen(s1))
		{
			new[i] = s1[i];
			i++;
		}
	while (i < len)
		new[i++] = s2[c++];
	new[i] = '\0';
	return (new);
}
