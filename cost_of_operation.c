/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_of_operation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhugo <bhugo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 17:32:11 by bhugo             #+#    #+#             */
/*   Updated: 2020/02/05 13:59:09 by bhugo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"


/* 
** count of costs for putting to
** - the beginning of the stack b
** - the beginning of the stack a and keep stack a sorted
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
    int len;
    int len2;
    int middle_a;
    t_stack *tmp;
    t_stack *tmp2;
    t_stack *tmp3;
    
    len = s->len_b;
    tmp3 = s->b;
    element = tmp3->element;
    middle_a = (s->len_a - s->len_b)/ 2 + 1;
    if ((s->len_a - s->len_b) % 2 == 0)
    {
        while(len--)
        {
            tmp = s->a;
            tmp2 = s->top_a;
            len2 = s->len_a - s->len_b;
            k = -1;
            while (len2--)
            {
                if ((tmp->element > element) && (element > tmp2->element))
                {   
                    (tmp->i < middle_a) ? k++ : k--;
                    tmp3->oper_cost =  tmp3->oper_cost + k;
                    break;
                }
                else
                {
                    (tmp->i < middle_a) ? k++ : k--;
                    tmp2 = tmp2->next;
                    tmp = tmp->next;
                }
            }
            tmp3 = tmp3->next;
            element = tmp3->element;
        }
    }
    else
    {
        while(len--)
        {
            tmp = s->a;
            tmp2 = s->top_a;
            len2 = s->len_a - s->len_b;
            k = -1;
            while (len2--)
            {
                if ((tmp->element > element) && (element > tmp2->element))
                {   
                    (tmp->i < middle_a) ? k++ : k;
                    tmp3->oper_cost =  tmp3->oper_cost + k;
                    break;
                }
                else
                {
                    (tmp->i < middle_a) ? k++ : k--;
                    tmp2 = tmp2->next;
                    tmp = tmp->next;
                }
            }
            tmp3 = tmp3->next;
            element = tmp3->element;
        }
    }
    
}

void    cost_of_operation(t_stacks *s)
{
    cost_in_b(s);
    cost_in_a(s);
    //find_min(s);
}