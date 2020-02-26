/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhugo <bhugo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 18:25:19 by bhugo             #+#    #+#             */
/*   Updated: 2020/02/22 14:22:12 by bhugo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSH_SWAP_H
# define FT_PUSH_SWAP_H

# include "ft_printf/ft_print.h"

/*
** direction_a, direction_b
** 0 - no action
** 1 = скидывать с begin to top, -1 = поднимать с топа наверх
*/

typedef struct		s_cost
{
	int				oper_b;
	int				oper_a;
	int				direction_a;
	int				direction_b;
}					t_cost;

typedef struct		s_stack
{
	int				element;
	int				i;
	int				for_max_seq;
	t_cost			*cost;
	struct s_stack	*next;
}					t_stack;

typedef struct		s_statistic
{
	int				min;
	int				max;
	int				i_min;
	int				i_max;
}					t_stat;

typedef struct		s_stacks
{
	t_stack			*a;
	t_stack			*b;
	t_stack			*top_a;
	t_stack			*top_b;
	t_stat			*stat;
	int				len_a;
	int				len_b;
}					t_stacks;

typedef struct		s_algoth
{
	int				element;
	int				len;
	int				middle_a;
	int				k;
	int				len2;
	t_stack			*tmp;
	t_stack			*tmp2;
	t_stack			*tmp3;
}					t_algoth;

void				check_duplicates(char **p, t_stacks *s, int i);
void				check_duplicates2(t_stacks *s);
int					varify_integer(char *p);
int					error(void);
t_stacks			*create_stacks(int argv, char **argc);
t_cost				*create_cost(void);
void				push(t_stacks *s, t_stack *temporary);
int					throw_to_stack_b(t_stacks *s);

void				sa(t_stacks *s, int print);
void				sb(t_stacks *s, int print);
void				ss(t_stacks *s, int print);

void				ra(t_stacks *s, int print);
void				rb(t_stacks *s, int print);
void				rr(t_stacks *s, int print);

void				rra(t_stacks *s, int print);
void				rrb(t_stacks *s, int print);
void				rrr(t_stacks *s, int print);

void				pb(t_stacks *s, int print);
void				pa(t_stacks *s, int print);

void				sort_3(t_stacks *s);
void				cost_of_operation(t_stacks *s);
void				indexation(t_stack *a);
void				min_max(t_stacks *s);
int					check_sort(t_stacks *s, int quality);
void				display_stack(t_stacks *s);
void				free_stack(t_stacks *s);
void				min_max(t_stacks *s);

void				push(t_stacks *s, t_stack *temporary);
t_stack				*getlist(char *p, int k);
char				**arguments(int argv, char **argc);
void				throw_to_stack_a(t_stacks *s, int i);
void				cost_in_b(t_stacks *s, int k);
void				cost_in_a(t_stacks *s);
void				cost_for_max(t_stacks *s, int middle_a, t_stack *tmp3);
void				cost_for_min(t_stacks *s, int middle_a, t_stack *tmp3);
int					extreme_cases(int element, int middle_a,
		t_stack *tmp3, t_stacks *s);

#endif
