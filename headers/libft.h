/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eprzybyl <eprzybyl@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 13:41:50 by eprzybyl          #+#    #+#             */
/*   Updated: 2024/03/22 19:12:54 by eprzybyl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <limits.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	void			*n;
	struct s_list	*next;
}					t_list;

int					ft_isdigit(int digit);
size_t				ft_strlen(const char *str);
long long			ft_atoi(const char *s);
char				*ft_substr(char const *s, unsigned int strt, size_t len);
char				**ft_split(char *s, char c);
char				*ft_strdup(const char *s1);
void				is_min_max(long long num);
char	*ft_strjoin(char *s1, char *s2);

#endif
