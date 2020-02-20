/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_of_operation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhugo <bhugo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 17:32:11 by bhugo             #+#    #+#             */
/*   Updated: 2020/02/20 17:45:00 by bhugo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

/*
** count of costs for putting to
** - the beginning of the stack b
** - the beginning of the stack a and keep stack a sorted
*/

int		find_min_cost(t_stacks *s, int i)
{
	t_stack	*tmp;
	t_stack	*tmp2;
	int		min;
	int		k;

	if (s->top_b != NULL)
	{
		tmp = s->b;
		tmp2 = tmp->next;
		min = tmp->cost->oper_a + tmp->cost->oper_b;
		k = tmp2->cost->oper_a + tmp2->cost->oper_b;
		i = tmp->i;
		while (tmp2 != s->b)
		{
			if (min > k)
			{
				min = k;
				i = tmp2->i;
			}
			tmp2 = tmp2->next;
			k = tmp2->cost->oper_a + tmp2->cost->oper_b;
		}
	}
	return (i);
}

void	throw_to_begin(t_stacks *s)
{
	int	middle;
	int	k;

	middle = s->len_a / 2 + 1;
	min_max(s);
	if (s->stat->i_min < middle)
	{
		while (s->stat->i_min--)
			ra(s, 0);
	}
	else
	{
		k = s->len_a - s->stat->i_min;
		while (k--)
			rra(s, 0);
	}
}

void	min_max(t_stacks *s)
{
	t_stack	*tmp;

	tmp = s->a;
	s->stat->i_max = tmp->i;
	s->stat->max = tmp->element;
	s->stat->i_min = tmp->i;
	s->stat->min = tmp->element;
	tmp = tmp->next;
	while (tmp != s->a)
	{
		if (tmp->element > s->stat->max)
		{
			s->stat->i_max = tmp->i;
			s->stat->max = tmp->element;
		}
		else if (tmp->element < s->stat->min)
		{
			s->stat->i_min = tmp->i;
			s->stat->min = tmp->element;
		}
		tmp = tmp->next;
	}
}

void	clean_costs(t_stack *tmp)
{
	tmp->cost->direction_a = 0;
	tmp->cost->direction_b = 0;
	tmp->cost->oper_a = 0;
	tmp->cost->oper_b = 0;
}

void	cost_of_operation(t_stacks *s)
{
	int		i;
	int		k;
	t_stack	*tmp;

	i = s->len_b;
	k = 0;
	while (i--)
	{
		min_max(s);
		cost_in_b(s, k);
		cost_in_a(s);
		throw_to_stack_a(s, find_min_cost(s, k));
		if (s->b != NULL)
		{
			clean_costs(s->b);
			tmp = s->b->next;
			while (tmp != s->b)
			{
				clean_costs(tmp);
				tmp = tmp->next;
			}
		}
	}
	throw_to_begin(s);
}
