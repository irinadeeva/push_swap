/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_in_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhugo <bhugo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 17:25:33 by bhugo             #+#    #+#             */
/*   Updated: 2020/02/21 13:41:24 by bhugo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	count_cost(t_algoth *a, t_stacks *s)
{
	while (a->len2--)
	{
		if (extreme_cases(a->element, a->middle_a, a->tmp3, s) == 1)
			break ;
		if ((a->tmp->element > a->element) && (a->element > a->tmp2->element))
		{
			if (a->tmp->i < a->middle_a)
				a->k++;
			(a->tmp->i < a->middle_a) ?
			a->tmp3->cost->direction_a++ : (a->tmp3->cost->direction_a--);
			a->tmp3->cost->oper_a = a->tmp3->cost->oper_a + a->k;
			break ;
		}
		else
		{
			(a->tmp->i < a->middle_a) ? a->k++ : a->k--;
			a->tmp2 = a->tmp2->next;
			a->tmp = a->tmp->next;
		}
	}
}

void	odd_length(t_algoth *a, t_stacks *s)
{
	while (a->len--)
	{
		a->tmp = s->a;
		a->tmp2 = s->top_a;
		a->len2 = s->len_a - s->len_b;
		a->k = -1;
		count_cost(a, s);
		a->tmp3 = a->tmp3->next;
		a->element = a->tmp3->element;
	}
}

void	count_cost2(t_algoth *a, t_stacks *s)
{
	while (a->len2--)
	{
		if (extreme_cases(a->element, a->middle_a, a->tmp3, s) == 1)
			break ;
		if ((a->tmp->element > a->element) && (a->element > a->tmp2->element))
		{
			if (a->tmp->i < a->middle_a)
				a->k++;
			else
				a->k--;
			(a->tmp->i < a->middle_a) ?
			a->tmp3->cost->direction_a++ : (a->tmp3->cost->direction_a--);
			a->tmp3->cost->oper_a = a->tmp3->cost->oper_a + a->k;
			break ;
		}
		else
		{
			(a->tmp->i < a->middle_a) ? a->k++ : a->k--;
			a->tmp2 = a->tmp2->next;
			a->tmp = a->tmp->next;
		}
	}
}

void	even_length(t_algoth *a, t_stacks *s)
{
	while (a->len--)
	{
		a->tmp = s->a;
		a->tmp2 = s->top_a;
		a->len2 = s->len_a - s->len_b;
		a->k = -1;
		count_cost2(a, s);
		a->tmp3 = a->tmp3->next;
		a->element = a->tmp3->element;
	}
}

void	cost_in_a(t_stacks *s)
{
	t_algoth	*a;

	if (!(a = (t_algoth *)malloc(sizeof(t_algoth))))
		exit(error());
	a->len = s->len_b;
	a->tmp3 = s->b;
	a->element = a->tmp3->element;
	a->middle_a = (s->len_a - s->len_b) / 2 + 1;
	if ((s->len_a - s->len_b) % 2 == 0)
		even_length(a, s);
	else
		odd_length(a, s);
	free(a);
}
