/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhugo <bhugo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 16:31:38 by bhugo             #+#    #+#             */
/*   Updated: 2020/02/24 19:28:59 by bhugo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_checker.h"

void			run_operations(t_operations *operations, t_stacks *s)
{
	t_operations	*tmp;

	tmp = operations;
	while (tmp != NULL)
	{
		//display_stack(s);
		ft_strcmp(tmp->commad, "pa") == 0 ? pa(s, 1) : 0;
		ft_strcmp(tmp->commad, "pb") == 0 ? pb(s, 1) : 0;
		ft_strcmp(tmp->commad, "sa") == 0 ? sa(s, 1) : 0;
		ft_strcmp(tmp->commad, "sb") == 0 ? sb(s, 1) : 0;
		ft_strcmp(tmp->commad, "ss") == 0 ? ss(s, 1) : 0;
		ft_strcmp(tmp->commad, "ra") == 0 ? ra(s, 1) : 0;
		ft_strcmp(tmp->commad, "rb") == 0 ? rb(s, 1) : 0;
		ft_strcmp(tmp->commad, "rr") == 0 ? rr(s, 1) : 0;
		ft_strcmp(tmp->commad, "rra") == 0 ? rra(s, 1) : 0;
		ft_strcmp(tmp->commad, "rrb") == 0 ? rrb(s, 1) : 0;
		ft_strcmp(tmp->commad, "rrr") == 0 ? rrr(s, 1) : 0;
		tmp = tmp->next;
	}
}

void			check_operations(char *str)
{
	if (ft_strcmp(str, "pa") != 0 && ft_strcmp(str, "pb") != 0 &&
		ft_strcmp(str, "sa") != 0 && ft_strcmp(str, "sb") != 0 &&
		ft_strcmp(str, "ss") != 0 && ft_strcmp(str, "rr") != 0 &&
		ft_strcmp(str, "ra") != 0 && ft_strcmp(str, "rb") != 0 &&
		ft_strcmp(str, "rra") != 0 && ft_strcmp(str, "rrb") != 0 &&
		ft_strcmp(str, "rrr") != 0)
		exit(error());
}

int				main(int argv, char **argc)
{
	t_stacks		*s;
	t_operations	*operations;
	int				i;

	if (argv >= 2)
	{
		i = 0;
		s = create_stacks(argv, argc);
		operations = read_commands(&i);
		run_operations(operations, s);
		if (s->b == NULL && check_sort(s, s->len_a) == 1)
			write(1, "OK\n", 3);
		else
			write(1, "KO\n", 3);
		free_stacks(s);
		free_operations(operations, i);
	}
	return (1);
}
