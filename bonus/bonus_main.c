/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eprzybyl <eprzybyl@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 14:58:32 by eprzybyl          #+#    #+#             */
/*   Updated: 2024/03/24 23:32:02 by eprzybyl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	is_sorted2(t_ch *ch)
{
	t_chl	*check;

	if (ch->count != list_length2(ch->a))
	{
		printf("%s\n", "KO");
		exit(1);
	}
	check = ch->a;
	while (check->next != NULL)
	{
		if (check->n > check->next->n)
		{
			printf("%s\n", "KO");
			exit(1);
		}
		check = check->next;
	}
	printf("%s\n", "OK");
	exit(1);
	return (0);
}

int	main(int argc, char *argv[])
{
	t_ch	ch;

	if (argc == 1 || (argc == 2 && !argv[1][0]))
	{
		return (1);
	}
	else if (argc > 2)
	{
		initialize_var2(&ch);
		build_a2(argc, argv, &ch);
	}
	else if (argc == 2)
	{
		initialize_var2(&ch);
		one_arg_only2(argv, &ch);
	}
}

void	free_line(t_ch *ch)
{
	while (*ch->action_line)
	{
		free(*ch->action_line);
		ch->action_line++;
	}
}

void	read_from_terminal(t_ch *ch)
{
	while (1)
	{
		ch->new_line = get_next_line(0);
		if (!ch->new_line)
			break ;
		if (ch->old_line == NULL)
			ch->old_line = ch->new_line;
		else
		{
			ch->temp_line = ft_strjoin(ch->old_line, ch->new_line);
			free(ch->new_line);
			free(ch->old_line);
			ch->old_line = ch->temp_line;
		}
	}
	close(0);
	if (!ch->old_line)
		is_sorted2(ch);
	loop_action_line(ch);
	is_sorted2(ch);
}

void	loop_action_line(t_ch *ch)
{
	ch->action_line = ft_split(ch->old_line, '\n');
	free(ch->old_line);
	while (*ch->action_line)
	{
		perform_operations(*ch->action_line, ch);
		free(*ch->action_line);
		ch->action_line++;
	}
	free(*ch->action_line);
}
