/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhugo <bhugo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 18:55:29 by bhugo             #+#    #+#             */
/*   Updated: 2020/02/20 14:05:52 by bhugo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

/*
** This functions sort 5 case:
**  1 3 2, 2 1 3, 2 3 1, 3 1 2, 3 2 1
*/

void	sort_3(t_stacks *s)
{
	int x;
	int y;
	int z;

	x = s->a->element;
	y = s->a->next->element;
	z = s->a->next->next->element;
	(x > y && x < z && y < z) ? sa(s, 0) : 0;
	(x < y && x > z && y > x) ? rra(s, 0) : 0;
	(x > y && x > z && y < z) ? ra(s, 0) : 0;
	if (x < y && x < z && z < y)
	{
		sa(s, 0);
		ra(s, 0);
	}
	else if (x > y && x > z && y > z)
	{
		sa(s, 0);
		rra(s, 0);
	}
}
