/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_linked_list.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhugo <bhugo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 19:48:24 by bhugo             #+#    #+#             */
/*   Updated: 2020/02/20 16:06:06 by bhugo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

/*
** These functions  - implement a stack in terms of a linked list
**                 - varify data (only integers).
*/

void	push(t_stacks *s, t_stack *temporary)
{
	if (s->top_a == NULL)
	{
		s->top_a = temporary;
		s->a = temporary;
	}
	else if (s->top_a->next == NULL)
	{
		s->top_a->next = temporary;
		s->top_a = s->top_a->next;
	}
}

t_stack	*getlist(char *p, int k)
{
	t_stack	*temporary;
	int		i;

	i = 0;
	(ft_strlen(p) == 1 && (p[i] == '-' || p[i] == '+')) ? exit(error()) : 0;
	(ft_strlen(p) > 11) ? exit(error()) : 0;
	(ft_strlen(p) == 10 || (ft_strlen(p) == 11 &&
	(p[i] == '-' || p[i] == '+'))) ? varify_integer(p) : 0;
	p[0] == '-' || p[0] == '+' ? i++ : 0;
	while (p[i])
		ft_isdigit(p[i]) ? i++ : exit(error());
	if (!(temporary = (t_stack *)malloc(sizeof(t_stack))))
		exit(error());
	temporary->element = ft_atoi(p);
	temporary->for_max_seq = 0;
	temporary->i = k;
	temporary->cost = create_cost();
	temporary->next = NULL;
	free(p);
	return (temporary);
}

char	**ptrjoin(char **tmp1, char **tmp2)
{
	char	**p;
	int		i;
	int		k;
	int		j;

	i = 0;
	k = 0;
	j = 0;
	while (tmp1[i] != NULL)
		i++;
	while (tmp2[k] != NULL)
		k++;
	if (!(p = (char**)malloc(sizeof(char *) * (k + i + 1))))
		exit(error());
	p[k + i] = NULL;
	i = 0;
	while (tmp1[i] != NULL)
		p[j++] = tmp1[i++];
	k = 0;
	while (tmp2[k] != NULL)
		p[j++] = tmp2[k++];
	return (p);
}

char	**arguments(int argv, char **argc)
{
	char	**p;
	char	**tmp1;
	char	**tmp2;
	int		k;

	k = 1;
	if (!(p = (char**)malloc(sizeof(char *) * 1)))
		exit(error());
	p[0] = NULL;
	while (k < argv)
	{
		tmp1 = p;
		if (!(tmp2 = ft_strsplit(argc[k], ' ')))
			exit(error());
		p = ptrjoin(tmp1, tmp2);
		k++;
		free(tmp1);
		free(tmp2);
	}
	return (p);
}
