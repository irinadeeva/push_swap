/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhugo <bhugo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 18:28:40 by bhugo             #+#    #+#             */
/*   Updated: 2020/02/20 14:12:15 by bhugo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	ss(t_stacks *s, int print)
{
	sb(s, 0);
	sa(s, 0);
	if (print == 0)
		ft_printf("ss\n");
}

void	rr(t_stacks *s, int print)
{
	ra(s, 1);
	rb(s, 1);
	if (print == 0)
		ft_printf("rr\n");
}

void	rrr(t_stacks *s, int print)
{
	rrb(s, 1);
	rra(s, 1);
	if (print == 0)
		ft_printf("rrr\n");
}
