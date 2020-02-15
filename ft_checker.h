/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhugo <bhugo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/15 14:57:03 by bhugo             #+#    #+#             */
/*   Updated: 2020/02/15 15:45:22 by bhugo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CHECKER_H
# define FT_CHECKER_H

# include "ft_push_swap.h"

# define STDIN 0

typedef struct s_operations
{
    char *commad;
    struct s_operations *next;
}               t_operations;

#endif