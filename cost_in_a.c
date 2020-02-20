/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_in_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhugo <bhugo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 17:25:33 by bhugo             #+#    #+#             */
/*   Updated: 2020/02/20 21:00:08 by bhugo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int 	extreme_cases(int element,int middle_a, t_stack *tmp3, t_stacks *s)
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

void 	count_cost(int element, int middle_a, t_stack *tmp3, t_stacks *s, t_stack *tmp, t_stack *tmp2, int k, int len2)
{
	while (len2--)
	{
		if (extreme_cases(element, middle_a, tmp3, s) == 1)
			break ;
		if ((tmp->element > element) && (element > tmp2->element))
		{
                if (tmp->i < middle_a)
                    k++;
				(tmp->i < middle_a) ? (tmp3->cost->direction_a = 1) : (tmp3->cost->direction_a = -1);
				tmp3->cost->oper_a =  tmp3->cost->oper_a + k;
				break ;
		}
		else
		{
			(tmp->i < middle_a) ? k++ : k--;
			tmp2 = tmp2->next;
			tmp = tmp->next;
		}
	}
}

void	odd_length(int len,int element, int middle_a, t_stack *tmp3, t_stacks *s)
{
	int     k;
	int     len2;
	t_stack *tmp;
	t_stack *tmp2;

	while (len--)
	{
		tmp = s->a;
		tmp2 = s->top_a;
		len2 = s->len_a - s->len_b;
		k = -1;
		count_cost(element, middle_a, tmp3, s, tmp, tmp2, k, len2);
		tmp3 = tmp3->next;
		element = tmp3->element;
	}
}

void	even_length(int len,int element, int middle_a, t_stack *tmp3, t_stacks *s)
{
	int     k;
	int     len2;
	t_stack *tmp;
	t_stack *tmp2;
	
	while (len--)
		{
			tmp = s->a;
			tmp2 = s->top_a;
			len2 = s->len_a - s->len_b;
			k = -1;
			while (len2--)
			{
				if (element < s->stat->min)
				{
					cost_for_min(s, middle_a, tmp3);
					break ;
				}
				if (element > s->stat->max)
				{
					cost_for_max(s, middle_a, tmp3);
					break ;
				}
				if ((tmp->element > element) && (element > tmp2->element))
				{
                    if (tmp->i < middle_a)
                        k++;
                    else
                        k--;
					(tmp->i < middle_a) ? (tmp3->cost->direction_a = 1) : (tmp3->cost->direction_a = -1);
					tmp3->cost->oper_a =  tmp3->cost->oper_a + k;
					break ;
				}
				else
				{
					(tmp->i < middle_a) ? k++ : k--;
					tmp2 = tmp2->next;
					tmp = tmp->next;
				}
			}
			tmp3 = tmp3->next;
			element = tmp3->element;
		}
}

void	cost_in_a(t_stacks *s)
{
	int     element;
	int     len;
	int     middle_a;
	t_stack *tmp3;

	len = s->len_b;
	tmp3 = s->b;
	element = tmp3->element;
	middle_a = (s->len_a - s->len_b) / 2 + 1;
	if ((s->len_a - s->len_b) % 2 == 0)
		even_length(len, element, middle_a, tmp3, s);
	else
	{
		odd_length(len, element, middle_a, tmp3, s);
	}
}
