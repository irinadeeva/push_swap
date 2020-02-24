/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commads_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhugo <bhugo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 14:11:40 by bhugo             #+#    #+#             */
/*   Updated: 2020/02/24 14:26:47 by bhugo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	first_node(t_stacks *s)
{
	s->top_b = s->a;
	s->b = s->a;
	if (s->a == s->top_a)
	{
		s->a = NULL;
		s->top_a = NULL;
	}
	else
	{
		s->a = s->a->next;
		s->top_a->next = s->a;
	}
	s->b->next = s->b;
	s->top_b->next = s->b;
}

void	pb(t_stacks *s, int print)
{
	t_stack	*tmp;

	if (s->a == NULL)
		return ;
	else if (s->b == NULL)
		first_node(s);
	else if (s->b != NULL)
	{
		tmp = s->b;
		s->b = s->a;
		if (s->a == s->top_a)
		{
			s->a = NULL;
			s->top_a = NULL;
		}
		else
		{
			s->a = s->a->next;
			s->top_a->next = s->a;
		}
		s->top_b->next = s->b;
		s->b->next = tmp;
	}
	(print == 0) ? ft_printf("pb\n") : 0;
}

void	sb(t_stacks *s, int print)
{
	t_stack	*tmp;

	if (s->b == NULL || s->b == s->top_b)
		return ;
	else if (s->b->next == s->top_b)
	{
		tmp = s->b;
		s->b = s->top_b;
		s->top_b = tmp;
		s->b->next = s->top_b;
		s->top_b->next = s->b;
		if (print == 0)
			ft_printf("sb\n");
		return ;
	}
	tmp = s->b->next;
	s->top_b->next = tmp;
	s->b->next = tmp->next;
	tmp->next = s->b;
	s->b = tmp;
	if (print == 0)
		ft_printf("sa\n");
}

void	rb(t_stacks *s, int print)
{
	if (s->b == NULL || s->b == s->top_b)
		return ;
	s->top_b = s->b;
	s->b = s->b->next;
	if (print == 0)
		ft_printf("rb\n");
}

void	rrb(t_stacks *s, int print)
{
	t_stack	*tmp;

	if (s->b == NULL || s->b == s->top_b)
		return ;
	tmp = s->b;
	while (tmp->next != s->top_b)
		tmp = tmp->next;
	s->b = s->top_b;
	s->top_b = tmp;
	s->top_b->next = s->b;
	if (print == 0)
		ft_printf("rrb\n");
}
