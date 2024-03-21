/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eprzybyl <eprzybyl@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 09:14:18 by eprzybyl          #+#    #+#             */
/*   Updated: 2024/03/08 18:00:40 by eprzybyl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int strt, size_t len)
{
	size_t			i;
	char			*new;
	unsigned int	s_len;

	i = 0;
	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (s[i] == '\0' || strt > s_len)
		return (ft_strdup(""));
	if (s_len - strt < len)
		len = s_len - strt;
	new = (char *)malloc(len * sizeof(char) + 1);
	if (!new)
		return (NULL);
	while (len > i)
	{
		new[i] = s[strt + i];
		i++;
	}
	new[i] = '\0';
	return (new);
}
