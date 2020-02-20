/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verification.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhugo <bhugo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 13:49:10 by bhugo             #+#    #+#             */
/*   Updated: 2020/02/20 13:56:46 by bhugo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

/*
** check the data:
** arguments aren’t integers,
** arguments are bigger or smaller than an integer => varify_integer(char *p)
** there are duplicates =>check_duplicates, check_duplicates2
** check_duplicates(char **p) helps to detect cases like "01" or "" as well
*/

void	check_duplicates2(t_stacks *s)
{
	t_stack	*tmp;
	t_stack	*tmp_2;

	tmp = s->a;
	tmp_2 = tmp->next;
	while (tmp_2 != s->a)
	{
		tmp = s->a;
		while (tmp->i < tmp_2->i)
		{
			if (tmp->element == tmp_2->element)
				exit(error());
			tmp = tmp->next;
		}
		tmp_2 = tmp_2->next;
	}
}

void	check_duplicates(char **p, t_stacks *s, int i)
{
	int		k;
	int		len;

	while (p[s->len_a])
		s->len_a++;
	((len = s->len_a) == 0) ? exit(error()) : 0;
	if (len == 1)
	{
		p[0][i] == '-' || p[0][i] == '+' ? i++ : 0;
		p[0][i] == '0' && p[0][++i] != '\0' ? exit(error()) : 0;
	}
	while (--len)
	{
		i = 0;
		k = len;
		while (i < k)
		{
			(p[k][0] == '0' && p[k][1] != '\0') ? exit(error()) : 0;
			if (ft_strlen(p[i]) == ft_strlen(p[k]))
				ft_strcmp(p[i], p[k]) == 0 ? exit(error()) : i++;
			else
				i++;
		}
	}
}

int		varify_integer(char *p)
{
	int		i;

	i = 0;
	p[0] == '-' || p[0] == '+' ? i++ : 0;
	if (p[i] >= '3')
		exit(error());
	else if (p[i] == '2')
	{
		i++;
		p[i] == '0' || p[i] == '1' ? i++ : exit(error());
		p[i] >= '0' && p[i] <= '4' ? i++ : exit(error());
		p[i] >= '0' && p[i] <= '7' ? i++ : exit(error());
		p[i] >= '0' && p[i] <= '4' ? i++ : exit(error());
		p[i] >= '0' && p[i] <= '8' ? i++ : exit(error());
		p[i] >= '0' && p[i] <= '3' ? i++ : exit(error());
		p[i] >= '0' && p[i] <= '6' ? i++ : exit(error());
		p[i] >= '0' && p[i] <= '4' ? i++ : exit(error());
		if (p[0] == '-')
			p[i] >= '0' && p[i] <= '8' ? i++ : exit(error());
		else
			p[i] >= '0' && p[i] <= '7' ? i++ : exit(error());
	}
	return (1);
}
