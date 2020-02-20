/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scan.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhugo <bhugo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 15:50:24 by bhugo             #+#    #+#             */
/*   Updated: 2020/02/20 16:31:10 by bhugo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_checker.h"

t_operations	*free_commad(t_operations *tmp)
{
	free(tmp);
	return (NULL);
}

void			cycle(t_operations *tmp, t_operations *tmp2, int i, int *k)
{
	while (i > 0)
	{
		((tmp2 = (t_operations*)malloc(sizeof(t_operations))) == NULL) ?
			exit(error()) : 0;
		((i = get_next_line(STDIN, &tmp2->commad)) == -1) ? exit(error()) : 0;
		if (i < 1)
		{
			free(tmp2);
			break ;
		}
		*k = *k + 1;
		check_operations(tmp2->commad);
		tmp->next = tmp2;
		tmp = tmp->next;
		tmp->next = NULL;
	}
}

t_operations	*read_commands(int *k)
{
	t_operations	*operations;
	t_operations	*tmp;
	t_operations	*tmp2;
	int				i;

	if (!(tmp = (t_operations*)malloc(sizeof(t_operations))))
		exit(error());
	tmp->commad = NULL;
	tmp->next = NULL;
	((i = get_next_line(STDIN, &tmp->commad)) == -1) ? exit(error()) : 0;
	*k = *k + 1;
	if (!tmp->commad)
		return (free_commad(tmp));
	check_operations(tmp->commad);
	operations = tmp;
	tmp2 = NULL;
	cycle(tmp, tmp2, i, k);
	return (operations);
}
