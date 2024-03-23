/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eprzybyl <eprzybyl@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 11:43:24 by eprzybyl          #+#    #+#             */
/*   Updated: 2024/03/23 20:35:37 by eprzybyl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "checker.h"
# include "ft_printf.h"
# include "get_next_line.h"
# include "libft.h"
# include <stdio.h>
# include <stdlib.h>

typedef struct at_lst
{
	long long		n;
	struct at_lst	*prev;
	struct at_lst	*next;
}					t_lst;

typedef struct s_v
{
	int				i;
	t_lst			*a;
	t_lst			*b;
	t_lst			*node;
	t_lst			*ptr;
	t_lst			*last;
	t_lst			*temp;
	int				count;
	int				check;
	int				counter;
	int				cost;
	int				cost_a;
	int				cost_b;
	int				index_a;
	int				temp_index_a;
	int				index_b;
	int				temp_cost;
	int				total_cost;
	long long		diff;
	int				temp_index_b;
	long long		biggest;
	int				index_b_loop;
}					t_v;

void				print_list(t_lst *a);
void				build_a(int argc, char *argv[], t_v *v);
void				initialize_var(t_v *v);
int					main(int argc, char *argv[]);
void				sort_three(t_v *v);
void				swap_a(t_v *v);
void				rotate_a(t_v *v);
void				rotate_b(t_v *v);
void				push_b(t_v *v);
void				push_a(t_v *v);
void				rrotate_a(t_v *v);
void				rrotate_b(t_v *v);
void				sort_more(t_v *v);
void				rr(t_v *v);
void				one_arg_only(char *argv[], t_v *v);
void				calc_cost(t_v *v);
int					list_length(t_lst *l);
int					list_length_c(t_lst *l);
void				operations(t_v *v);
void				rrr(t_v *v);
void				rrr_rr_check(t_v *v);
void				v_a_operations(t_v *v);
void				push_last_and_sort(t_v *v);
int					is_sorted(t_v *v);
void				choose_sort(t_v *v);
void				free_leaks(t_lst **a);
int					check_errors(char *arg, t_lst *a);
int					search_for_biggest(t_v *v);
int					check_for_duplicates(int argc, char *argv[], t_v *v);
int					check_for_duplicates_one_arg(char **s, t_v *v);
void				inner_loop(t_v *v);
void				number_is_smaller(t_v *v);
void				build_b(long long el, t_v *v);
void				sadly_put_it_back(t_v *v);
void				rrotate_b1(t_v *v);
void				rrotate_a1(t_v *v);
void				rotate_a1(t_v *v);
void				rotate_b1(t_v *v);

#endif /* SO_LONG_H */