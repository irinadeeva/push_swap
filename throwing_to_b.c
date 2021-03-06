/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   throwing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhugo <bhugo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 18:39:47 by bhugo             #+#    #+#             */
/*   Updated: 2020/02/20 14:01:55 by bhugo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

/*
** throwing elements of stack a to stack b until
** - they are sorted (check_sort) or
** - they are 3
** new indexation in both stacks
*/

void	indexation(t_stack *a)
{
	int		i;
	t_stack	*tmp;

	tmp = a->next;
	i = 0;
	a->i = i++;
	while (tmp != a)
	{
		tmp->i = i++;
		tmp = tmp->next;
	}
}

int		check_sort(t_stacks *s, int quality)
{
	t_stack	*tmp;
	t_stack	*tmp_2;
	int		i;

	if (s->a == NULL)
		return (0);
	i = 1;
	tmp = s->a;
	tmp_2 = tmp->next;
	while (tmp_2 != s->a)
	{
		if (tmp_2->element > tmp->element)
			i++;
		tmp = tmp->next;
		tmp_2 = tmp->next;
	}
	if (i == quality)
		return (1);
	return (0);
}

int		throw_to_stack_b(t_stacks *s)
{
	t_stack	*tmp;
	int		quality;

	quality = s->len_a;
	tmp = s->a;
	while (quality > 3 && check_sort(s, quality) == 0)
	{
		pb(s, 0);
		quality--;
	}
	if (quality != s->len_a)
	{
		s->top_b->next = s->b;
		indexation(s->b);
	}
	if (quality == 3)
		sort_3(s);
	indexation(s->a);
	return (s->len_a - quality);
}
