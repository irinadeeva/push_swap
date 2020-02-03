/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhugo <bhugo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 18:55:29 by bhugo             #+#    #+#             */
/*   Updated: 2020/02/03 20:15:39 by bhugo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void  sort_3(t_stacks *s)
{
    int x;
    int y;
    int z;
    
    x = s->a->element; 
    y = s->a->next->element;
    z = s->a->next->next->element;
    //if (x < y && x < z && y < z) // case 1
    
    if (x < y && x < z && z < y) // case 2
    {
        sa(s->a);
        ra(s->a);
    }
    else if (x > y && x < z && y < z) // case 3
        sa(s->a);
    else if (x < y && x > z && y > x)
        rra(s->a);
    else if (x > y && x > z && y < z)
        ra(s->a);
    else if (x > y && x > z && y > z)
    {
        sa(s->a);
        rra(s->a); 
    }
}