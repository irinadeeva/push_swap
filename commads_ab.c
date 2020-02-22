/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commads_ab.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhugo <bhugo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 18:28:40 by bhugo             #+#    #+#             */
/*   Updated: 2020/02/22 16:07:59 by bhugo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	ss(t_stacks *s, int print)
{
	if (s->b != NULL || s->b != s->top_b)
		sb(s, 1);
	if (s->a != NULL || s->a != s->top_a)
		sa(s, 1);
	if (print == 0)
		ft_printf("ss\n");
}

void	rr(t_stacks *s, int print)
{
	if (s->a != NULL || s->a != s->top_a)
		ra(s, 1);
	if (s->b != NULL || s->b != s->top_b)
		rb(s, 1);
	if (print == 0)
		ft_printf("rr\n");
}

void	rrr(t_stacks *s, int print)
{
	if (s->a != NULL || s->a != s->top_a)
		rrb(s, 1);
	if (s->b != NULL || s->b != s->top_b)
		rra(s, 1);
	if (print == 0)
		ft_printf("rrr\n");
}
