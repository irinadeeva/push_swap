/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_extreme_cases.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhugo <bhugo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 13:34:26 by bhugo             #+#    #+#             */
/*   Updated: 2020/02/21 13:37:03 by bhugo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	cost_for_min(t_stacks *s, int middle_a, t_stack *tmp3)
{
	if (s->a->element == s->stat->min)
	{
		tmp3->cost->oper_a = 0;
		tmp3->cost->direction_a = 0;
	}
	else if (s->stat->i_min < middle_a)
	{
		tmp3->cost->oper_a = s->stat->i_min;
		tmp3->cost->direction_a = 1;
	}
	else
	{
		tmp3->cost->oper_a = s->top_a->i - s->stat->i_min + 1;
		tmp3->cost->direction_a = -1;
	}
}

void	cost_for_max(t_stacks *s, int middle_a, t_stack *tmp3)
{
	if (s->top_a->element == s->stat->max)
	{
		tmp3->cost->oper_a = 0;
		tmp3->cost->direction_a = 0;
	}
	else if (s->stat->i_max < middle_a)
	{
		tmp3->cost->oper_a = s->stat->i_max + 1;
		tmp3->cost->direction_a = 1;
	}
	else
	{
		tmp3->cost->oper_a = s->top_a->i - s->stat->i_max + 1;
		tmp3->cost->direction_a = -1;
	}
}

int		extreme_cases(int element, int middle_a, t_stack *tmp3, t_stacks *s)
{
	if (element < s->stat->min)
	{
		cost_for_min(s, middle_a, tmp3);
		return (1);
	}
	if (element > s->stat->max)
	{
		cost_for_max(s, middle_a, tmp3);
		return (1);
	}
	return (0);
}
