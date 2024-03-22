/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eprzybyl <eprzybyl@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 17:17:42 by eprzybyl          #+#    #+#             */
/*   Updated: 2024/03/22 19:11:17 by eprzybyl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H

# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000000
# endif
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

typedef struct g_list
{
	char			*content;
	struct g_list	*next;
}					t_glist;

char				*get_next_line(int fd);
char				*ft_substr2(char *s, unsigned int start, size_t len);
size_t				ft_strlen2(char *str);
char				*ft_strchr(const char *s, int c);
t_glist				*set_reminder(t_glist **reminder, int i, char *entire_buff);
char				*find_n(char *entire_buff, t_glist **reminder);
int					read_line(int fd, char *buffer, int *bytes_read);
int					append_to_list(t_glist **m_list, char *buffer,
						t_glist **reminder);
char				*find_line(int fd, t_glist **m, t_glist **rem, char *temp);
size_t				calculate_len(t_glist *m_list);
void				construct_line(char *line, t_glist *m_list);
char				*extract_line(t_glist **m_list, char *line, int i, int len);
void				free_list(t_glist **list);
char				*get_next_line(int fd);
size_t				ft_strlen2(char *str);
#endif