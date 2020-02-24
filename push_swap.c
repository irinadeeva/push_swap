/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhugo <bhugo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 14:29:06 by bhugo             #+#    #+#             */
/*   Updated: 2020/02/24 14:50:20 by bhugo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	free_stack(t_stacks *s)
{
	t_stack	*tmp;
	t_stack	*tmp2;

	tmp = s->a;
	tmp2 = tmp->next;
	while (s->len_a--)
	{
		free(tmp);
		free(tmp->cost);
		tmp = tmp2;
		tmp2 = tmp2->next;
	}
	free(s->stat);
	free(s);
}

int		main(int argv, char **argc)
{
	t_stacks	*s;

	if (argv > 1)
	{
		s = create_stacks(argv, argc);
		s->len_b = throw_to_stack_b(s);
		cost_of_operation(s);
		//display_stack(s);
		free_stack(s);
	}
	return (1);
}
