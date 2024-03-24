/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eprzybyl <eprzybyl@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 14:24:12 by eprzybyl          #+#    #+#             */
/*   Updated: 2024/03/24 23:12:06 by eprzybyl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "ft_printf.h"
# include "get_next_line.h"
# include "libft.h"
# include <limits.h>
# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>

typedef struct a_checker
{
	long long			n;
	struct a_checker	*prev;
	struct a_checker	*next;
}						t_chl;

typedef struct s_check
{
	int					i;
	t_chl				*a;
	t_chl				*b;
	t_chl				*ptr;
	t_chl				*temp;
	t_chl				*node;
	int					counter;
	int					count;
	char				**actions_a;
	char				*old_line;
	char				*new_line;
	char				*temp_line;
	char				**action_line;
	int					check;
}						t_ch;

int						main(int argc, char *argv[]);
void					swap_a2(t_ch *ch);
void					ss2(t_ch *ch);
void					swap_b2(t_ch *ch);
void					rotate_a2(t_ch *ch);
void					rotate_b2(t_ch *ch);
void					push_b2(t_ch *ch);
void					push_a2(t_ch *ch);
void					rrotate_a2(t_ch *ch);
void					rrotate_b2(t_ch *ch);
void					sort_more2(t_ch *ch);
void					rr2(t_ch *ch);
void					rrr2(t_ch *ch);
void					build_b2(long long el, t_ch *ch);
void					one_arg_only2(char *argv[], t_ch *ch);
void					build_a2(int argc, char *argv[], t_ch *ch);
void					initialize_var2(t_ch *ch);
int						check_for_duplicates_one_arg2(char **s, t_ch *ch);
int						check_for_duplicates2(int argc, char *argv[], t_ch *ch);
int						check_errors2(char *arg, t_chl *a);
void					free_leaks2(t_chl **a);
void					perform_operations(char *line, t_ch *ch);
int						is_sorted2(t_ch *ch);
void					print_list2(t_chl *a);
void					error_handling2(int code);
void					read_from_terminal(t_ch *ch);
void					perform_operations(char *line, t_ch *ch);
void					free_line(t_ch *ch);
void					exit_message(char *str, int code);
int						list_length2(t_chl *l);
void					loop_action_line(t_ch *ch);

#endif