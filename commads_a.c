/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commads_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhugo <bhugo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 14:07:48 by bhugo             #+#    #+#             */
/*   Updated: 2020/02/20 14:10:36 by bhugo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	pa(t_stacks *s, int print)
{
	t_stack	*tmp;
	t_stack	*tmp2;

	if (s->b == NULL)
		return ;
	if (s->top_b == s->b)
	{
		tmp = s->a;
		s->a = s->b;
		s->top_a->next = s->a;
		s->a->next = tmp;
		s->b = NULL;
		s->top_b = NULL;
	}
	else
	{
		tmp = s->b;
		s->top_b->next = s->b->next;
		s->b = s->b->next;
		tmp2 = s->a;
		s->a = tmp;
		s->top_a->next = s->a;
		s->a->next = tmp2;
	}
	(print == 0) ? ft_printf("pa\n") : 0;
}

void	sa(t_stacks *s, int print)
{
	t_stack	*tmp;

	if (s->a == NULL || s->a == s->top_a)
		return ;
	tmp = s->a->next;
	s->top_a->next = tmp;
	s->a->next = tmp->next;
	tmp->next = s->a;
	s->a = tmp;
	if (print == 0)
		ft_printf("sa\n");
}

void	ra(t_stacks *s, int print)
{
	if (s->a == NULL)
		return ;
	s->top_a = s->a;
	s->a = s->a->next;
	if (print == 0)
		ft_printf("ra\n");
}

void	rra(t_stacks *s, int print)
{
	t_stack *tmp;

	if (s->a == NULL)
		return ;
	tmp = s->a;
	while (tmp->next != s->top_a)
		tmp = tmp->next;
	s->a = s->top_a;
	s->top_a = tmp;
	s->top_a->next = s->a;
	if (print == 0)
		ft_printf("rra\n");
}
