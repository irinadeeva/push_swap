/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_in_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhugo <bhugo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 17:28:00 by bhugo             #+#    #+#             */
/*   Updated: 2020/02/20 17:45:38 by bhugo            ###   ########.fr       */
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

void	cost_in_b(t_stacks *s, int k)
{
	t_stack	*tmp;
	int		middle_b;

	k = 0;
	middle_b = s->len_b / 2 + 1;
	tmp = s->b;
	tmp->cost->oper_b = k;
	tmp = tmp->next;
	while (tmp != s->b)
	{
		if (tmp->i < middle_b)
		{
			tmp->cost->oper_b = ++k;
			tmp->cost->direction_b = 1;
		}
		else
		{
			if (s->len_b % 2)
				tmp->cost->oper_b = k--;
			else
				tmp->cost->oper_b = --k;
			tmp->cost->direction_b = -1;
		}
		tmp = tmp->next;
	}
}
