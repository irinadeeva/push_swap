/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhugo <bhugo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 19:37:21 by bhugo             #+#    #+#             */
/*   Updated: 2020/02/20 13:55:40 by bhugo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

t_cost		*create_cost(void)
{
	t_cost	*temporary;

	if (!(temporary = (t_cost *)malloc(sizeof(t_cost))))
		exit(error());
	temporary->direction_a = 0;
	temporary->direction_b = 0;
	temporary->oper_a = 0;
	temporary->oper_b = 0;
	return (temporary);
}

t_stat		*create_statistic(void)
{
	t_stat	*temporary;

	if (!(temporary = (t_stat *)malloc(sizeof(t_stat))))
		exit(error());
	temporary->i_max = 0;
	temporary->i_min = 0;
	temporary->max = 0;
	temporary->min = 0;
	return (temporary);
}

void		create_stack_a(int argv, char **argc, t_stacks *s)
{
	t_stack	*temporary;
	char	**p;
	int		i;
	int		k;

	i = -1;
	k = 0;
	p = arguments(argv, argc);
	check_duplicates(p, s, k);
	while (p[++i])
	{
		temporary = getlist(p[i], k);
		k++;
		push(s, temporary);
	}
	s->top_a->next = s->a;
	free(p);
}

t_stacks	*create_stacks(int argv, char **argc)
{
	t_stacks	*s;

	if (!(s = (t_stacks*)malloc(sizeof(t_stacks))))
		exit(error());
	s->a = NULL;
	s->b = NULL;
	s->len_a = 0;
	s->len_b = 0;
	s->top_a = NULL;
	s->top_b = NULL;
	s->stat = create_statistic();
	create_stack_a(argv, argc, s);
	check_duplicates2(s);
	return (s);
}
