/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhugo <bhugo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/15 14:57:03 by bhugo             #+#    #+#             */
/*   Updated: 2020/02/20 16:35:52 by bhugo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CHECKER_H
# define FT_CHECKER_H

# include "ft_push_swap.h"

# define STDIN 0

typedef struct			s_operations
{
	char				*commad;
	struct s_operations	*next;
}						t_operations;

void					free_stacks(t_stacks *s);
void					free_a(t_stack *a, t_stack *top_a);
void					free_operations(t_operations *operations, int i);
t_operations			*read_commands(int *k);
void					check_operations(char *str);

#endif
