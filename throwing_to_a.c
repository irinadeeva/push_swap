/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   throwing_to_a.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhugo <bhugo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 17:29:00 by bhugo             #+#    #+#             */
/*   Updated: 2020/02/20 18:11:41 by bhugo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	optimization_from_begin_to_top(t_stack *tmp, t_stacks *s)
{
	while (tmp->cost->oper_a != 0 && tmp->cost->oper_b != 0)
	{
		rr(s, 0);
		tmp->cost->oper_a--;
		tmp->cost->oper_b--;
	}
	while (tmp->cost->oper_a--)
		ra(s, 0);
	while (tmp->cost->oper_b--)
		rb(s, 0);
}

void	optimization_from_top_to_begin(t_stack *tmp, t_stacks *s)
{
	while (tmp->cost->oper_a != 0 && tmp->cost->oper_b != 0)
	{
		rrr(s, 0);
		tmp->cost->oper_a--;
		tmp->cost->oper_b--;
	}
	while (tmp->cost->oper_a--)
		rra(s, 0);
	while (tmp->cost->oper_b--)
		rrb(s, 0);
}

void	optimization(t_stack *tmp, t_stacks *s)
{
	if (tmp->cost->direction_a == 1)
		optimization_from_begin_to_top(tmp, s);
	else if (tmp->cost->direction_a == -1)
		optimization_from_top_to_begin(tmp, s);
}

void	without_optimization(t_stack *tmp, t_stacks *s)
{
	if (tmp->cost->direction_a == 1)
	{
		while (tmp->cost->oper_a--)
			ra(s, 0);
	}
	if (tmp->cost->direction_a == -1)
	{
		while (tmp->cost->oper_a--)
			rra(s, 0);
	}
	if (tmp->cost->direction_b == 1)
	{
		while (tmp->cost->oper_b--)
			rb(s, 0);
	}
	if (tmp->cost->direction_b == -1)
	{
		while (tmp->cost->oper_b--)
			rrb(s, 0);
	}
}

void	throw_to_stack_a(t_stacks *s, int i)
{
	t_stack	*tmp;

	tmp = s->b;
	while (tmp->i != i)
		tmp = tmp->next;
	if (tmp->cost->direction_a == tmp->cost->direction_b)
		optimization(tmp, s);
	else
		without_optimization(tmp, s);
	pa(s, 0);
	s->len_b--;
	indexation(s->a);
	if (s->b != NULL)
		indexation(s->b);
}
