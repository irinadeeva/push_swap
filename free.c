/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhugo <bhugo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 14:55:07 by bhugo             #+#    #+#             */
/*   Updated: 2020/02/20 15:01:44 by bhugo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_checker.h"

void			free_a(t_stack *a, t_stack *top_a)
{
	t_stack			*tmp;
	t_stack			*tmp2;
	int				i;

	if (a == NULL)
		return ;
	i = 1;
	tmp = a;
	while (tmp != top_a)
	{
		if (tmp->next == NULL)
			tmp = NULL;
		else
			tmp = tmp->next;
		i++;
	}
	tmp = a;
	tmp2 = tmp->next;
	while (i--)
	{
        free(tmp->cost);
		free(tmp);
		tmp = tmp2;
		(tmp2 != top_a) ? tmp2 = tmp->next : 0;
	}
}

void			free_stacks(t_stacks *s)
{
	free_a(s->a, s->top_a);
	free_a(s->b, s->top_b);
	free(s->stat);
	free(s);
}

void			free_operations(t_operations *operations, int i)
{
	t_operations	*tmp;
	t_operations	*tmp2;

	if (operations == NULL)
	{
		free(operations);
		return ;
	}
	tmp = operations;
	tmp2 = tmp->next;
	while (i)
	{
		free(tmp->commad);
		free(tmp);
		tmp = tmp2;
		if (tmp2 && tmp2->next != NULL)
			tmp2 = tmp2->next;
		else
			tmp2 = NULL;
		i--;
	}
}
