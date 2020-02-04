/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_of_operation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhugo <bhugo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 17:32:11 by bhugo             #+#    #+#             */
/*   Updated: 2020/02/04 20:29:04 by bhugo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"


/* 
** count of costs for putting to
** - the beginning of the stack b
** 
*/

void    cost_in_b(t_stacks *s)
{
    t_stack *tmp;
    int middle_b;
    int k;

    k = 0;
    middle_b = s->len_b / 2 + 1;
    tmp = s->b;
    tmp->oper_cost = k;
    tmp = tmp->next;
    while (tmp != s->b)
    {
        if (tmp->i < middle_b)
            tmp->oper_cost = ++k;
        else
            (s->len_b % 2) ? tmp->oper_cost = k-- : (tmp->oper_cost = --k);
        tmp = tmp->next;           
    }
}

void    cost_in_a(t_stacks *s)
{
    int k;
    int element;
    int leb_a
    t_stack *tmp;
    
    
    k = 0;
    tmp = s->b;
    len_a = s->len_a - s->len_b;
    element = tmp->element;
    while(len_a--) 
    {
        if ()
    }
}

void    cost_of_operation(t_stacks *s)
{
    cost_in_b(s);
    cost_in_a(s);
}