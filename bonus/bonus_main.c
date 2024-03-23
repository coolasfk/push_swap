/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eprzybyl <eprzybyl@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 14:58:32 by eprzybyl          #+#    #+#             */
/*   Updated: 2024/03/23 14:04:14 by eprzybyl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	is_sorted2(t_ch *ch)
{
	t_chl	*check;

	check = ch->a;
	while (check->next != NULL)
	{
		if (check->n > check->next->n)
		{
			check = ch->a;
			printf("your list is not sorted: %s\n", "KO");
			print_list2(ch->a);
			return (0);
		}
		check = check->next;
	}
	printf("--------counter: %d\n", ch->counter);
	printf("--------count: %d\n", ch->count);
	printf("Your list is sorted: %s\n", "OK");
	print_list2(ch->a);
	exit(0);
	return (1);
}

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

void	perform_operations(char *line, t_ch *ch)
{
	printf("im here 99");
	if (ft_strcmp(line, "pb") == 0)
		push_b2(ch);
	if (ft_strcmp(line, "pa") == 0)
		push_a2(ch);
	if (ft_strcmp(line, "ra") == 0)
		rotate_a2(ch);
	if (ft_strcmp(line, "rb") == 0)
		rotate_b2(ch);
	if (ft_strcmp(line, "rra") == 0)
		rrotate_a2(ch);
	if (ft_strcmp(line, "rrb") == 0)
		rrotate_b2(ch);
	if (ft_strcmp(line, "rr") == 0)
		rr2(ch);
	if (ft_strcmp(line, "rrr") == 0)
		rrr2(ch);
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
	ch->action_line = ft_split(ch->old_line, '\n');
	free(ch->old_line);
	while (*ch->action_line)
	{
		perform_operations(*ch->action_line, ch);
		ch->action_line++;
	}
	is_sorted2(ch);
}