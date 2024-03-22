/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eprzybyl <eprzybyl@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 17:17:52 by eprzybyl          #+#    #+#             */
/*   Updated: 2024/03/22 19:24:51 by eprzybyl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	append_to_list(t_glist **m_list, char *buffer, t_glist **rem)
{
	t_glist	*temp;
	t_glist	*last;

	temp = (t_glist *)malloc(sizeof(t_glist));
	if (!temp)
		return (-1);
	if (ft_strchr(buffer, '\n'))
		temp->content = find_n(buffer, rem);
	else
		temp->content = ft_substr2(buffer, 0, ft_strlen2(buffer));
	if (!temp->content)
		return (-1);
	temp->next = NULL;
	last = *m_list;
	if (!last)
		*m_list = temp;
	else
	{
		while (last->next)
			last = last->next;
		last->next = temp;
	}
	return (0);
}

char	*extract_line(t_glist **m_list, char *line, int i, int len)
{
	t_glist	*temp;

	temp = *m_list;
	while (temp)
	{
		len += ft_strlen2(temp->content);
		temp = temp->next;
	}
	line = (char *)malloc(sizeof(char) * (len + 1));
	if (!line)
	{
		free_list(m_list);
		return (NULL);
	}
	temp = *m_list;
	while (temp)
	{
		len = 0;
		while (temp->content[len] != '\0')
			line[i++] = temp->content[len++];
		temp = temp->next;
	}
	line[i] = '\0';
	free_list(m_list);
	return (line);
}

void	free_list(t_glist **list)
{
	t_glist	*temp;

	while (*list)
	{
		temp = (*list)->next;
		free((*list)->content);
		free(*list);
		*list = temp;
	}
}

char	*get_next_line(int fd)
{
	static t_glist	*m_list = NULL;
	char			*line;
	static t_glist	*reminder = NULL;
	char			*temp;

	temp = NULL;
	if (reminder)
	{
		m_list = reminder;
		reminder = NULL;
	}
	line = NULL;
	if (fd < 0 || fd > 4095 || BUFFER_SIZE <= 0)
		return (NULL);
	line = find_line(fd, &m_list, &reminder, temp);
	return (line);
}

char	*find_line(int fd, t_glist **m, t_glist **rem, char *temp)
{
	char	buf[BUFFER_SIZE + 1];
	int		b;

	while (1)
	{
		if (*m != NULL && ft_strchr((*m)->content, '\n'))
		{
			temp = find_n((*m)->content, rem);
			free((*m)->content);
			(*m)->content = temp;
			break ;
		}
		b = read(fd, buf, BUFFER_SIZE);
		if (b < 0)
		{
			free_list(m);
			return (NULL);
		}
		buf[b] = '\0';
		if ((b < 1 && *m == NULL) || append_to_list(m, buf, rem) < 0)
			return (NULL);
		if (ft_strchr(buf, '\n') || b < BUFFER_SIZE)
			break ;
	}
	return (extract_line(m, temp, 0, 0));
}
