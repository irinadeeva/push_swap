/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_in_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhugo <bhugo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 17:28:00 by bhugo             #+#    #+#             */
/*   Updated: 2020/02/21 13:35:42 by bhugo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

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
