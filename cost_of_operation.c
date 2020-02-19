/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_of_operation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhugo <bhugo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 17:32:11 by bhugo             #+#    #+#             */
/*   Updated: 2020/02/19 19:29:02 by bhugo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

/* 
** count of costs for putting to
** - the beginning of the stack b
** - the beginning of the stack a and keep stack a sorted
*/

void	cost_for_min(t_stacks *s, int middle_a, t_stack *tmp3)
{
	if (s->a->element == s->stat->min)
	{
		tmp3->cost->oper_a = 0;
		tmp3->cost->direction_a = 0;
	}
	else if (s->stat->i_min < middle_a)
	{
		tmp3->cost->oper_a = s->stat->i_min;
		tmp3->cost->direction_a = 1;
	}
	else
	{
		tmp3->cost->oper_a = s->top_a->i - s->stat->i_min + 1;
		tmp3->cost->direction_a = -1;
	}
}

void	cost_for_max(t_stacks *s, int middle_a, t_stack *tmp3)
{
	if (s->top_a->element == s->stat->max)
	{
		tmp3->cost->oper_a = 0;
		tmp3->cost->direction_a = 0;
	}
	else if (s->stat->i_max < middle_a)
	{
		tmp3->cost->oper_a = s->stat->i_max + 1;
		tmp3->cost->direction_a = 1;
	}
	else
	{
		tmp3->cost->oper_a = s->top_a->i - s->stat->i_max + 1; 
		tmp3->cost->direction_a = -1;
	}
}

void	cost_in_b(t_stacks *s)
{
	t_stack *tmp;
	int middle_b;
	int k;

	k = 0;
	middle_b = s->len_b / 2 + 1;
	tmp = s->b;
	tmp->cost->oper_b = k;
	tmp = tmp->next;
	while (tmp != s->b)
	{
		if (tmp->i < middle_b)
		{
			tmp->cost->oper_b = ++k;
			tmp->cost->direction_b = 1;
		}
		else
		{
			(s->len_b % 2) ? tmp->cost->oper_b = k-- : (tmp->cost->oper_b = --k);
			tmp->cost->direction_b = -1;
		}
		tmp = tmp->next;
	}
}

void	cost_in_a(t_stacks *s)
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
		while (len--)
		{
			tmp = s->a;
			tmp2 = s->top_a;
			len2 = s->len_a - s->len_b;
			k = -1;
			while (len2--)
			{
				if (element < s->stat->min)
				{
					cost_for_min(s, middle_a, tmp3);
					break ;
				}
				if (element > s->stat->max)
				{
					cost_for_max(s, middle_a, tmp3);
					break ;
				}
				if ((tmp->element > element) && (element > tmp2->element))
				{
					(tmp->i < middle_a) ? k++ : k--;
					(tmp->i < middle_a) ? (tmp3->cost->direction_a = 1) : (tmp3->cost->direction_a = -1);
					tmp3->cost->oper_a =  tmp3->cost->oper_a + k;
					break ;
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
				if (element < s->stat->min)
				{
					cost_for_min(s, middle_a, tmp3);
					break ;
				}
				if (element > s->stat->max)
				{
					cost_for_max(s, middle_a, tmp3);
					break ;
				}
				if ((tmp->element > element) && (element > tmp2->element))
				{
					(tmp->i < middle_a) ? k++ : k;
					(tmp->i < middle_a) ? (tmp3->cost->direction_a = 1) : (tmp3->cost->direction_a = -1);
					tmp3->cost->oper_a =  tmp3->cost->oper_a + k;
					break ;
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

int		find_min_cost(t_stacks *s)
{
	t_stack *tmp;
	t_stack *tmp2;
	int  min;
	int k;
	int i;

	i = 0;
	if (s->top_b != NULL)
	{
		tmp = s->b;
		tmp2 = tmp->next;
		min = tmp->cost->oper_a + tmp->cost->oper_b;
		k = tmp2->cost->oper_a + tmp2->cost->oper_b;
		i = tmp->i;
		while (tmp2 != s->b)
		{
			if (min > k) 
			{
				min = k;
				i = tmp2->i;
			}
			tmp2 = tmp2->next;
			k = tmp2->cost->oper_a + tmp2->cost->oper_b;
		}
	}
	return(i);
}

void	throw_to_stack_a(t_stacks *s, int i)
{
    t_stack *tmp;

    tmp = s->b;
    while (tmp->i != i)
        tmp = tmp->next;
    if (tmp->cost->direction_a == tmp->cost->direction_b)
    {
        if (tmp->cost->direction_a == 1)
        {
            while (tmp->cost->oper_a != 0 && tmp->cost->oper_b != 0)
            {
                rr(s, 0);
                tmp->cost->oper_a--;
                tmp->cost->oper_b--;
            }
            while (tmp->cost->oper_a--)
                    ra(s, 0);
            while (tmp->cost->oper_b--)
                    rb(s, 0); 
        }
        else if (tmp->cost->direction_a == -1)
        {
           while (tmp->cost->oper_a !=0  && tmp->cost->oper_b != 0)
           {    
               rrr(s, 0);
               tmp->cost->oper_a--;
                tmp->cost->oper_b--;
           }
            while (tmp->cost->oper_a--)
                rra(s, 0);        
            while (tmp->cost->oper_b--)
                rrb(s, 0); 
        }
    }
    else
    {
        if (tmp->cost->direction_a == 1)
        {
            while (tmp->cost->oper_a--)
                    ra(s, 0); 
        }
        if (tmp->cost->direction_a == -1)
        {
            while (tmp->cost->oper_a--)
                rra(s, 0); 
        }
        if (tmp->cost->direction_b == 1)
        {
            while (tmp->cost->oper_b--)
                    rb(s, 0); 
        }
        if (tmp->cost->direction_b == -1)
        {
            while (tmp->cost->oper_b--)
                rrb(s, 0); 
        }
    }
    pa(s, 0);
    s->len_b--;
    indexation(s->a);
    if (s->b != NULL)
        indexation(s->b);
}

/*void    find_new_begin_top(t_stacks *s)
{
    t_stack *tmp;
    t_stack *tmp2;
    
    min_max(s);
    tmp = s->a;
    tmp2 = tmp->next; 
    
    while (tmp2 != tmp)
    {
        if (s->stat->max == tmp2->element)
            s->top_a = tmp2;
        else if (s->stat->min == tmp2->element)
            s->a = tmp2;
        tmp2 = tmp2->next;
    }      
}*/

void    throw_to_begin(t_stacks *s)
{
    int middle;
    int k;
    
    middle = s->len_a /2 + 1;
    min_max(s);
    if (s->stat->i_min < middle)
    {
        while (s->stat->i_min--)
            ra(s, 0);
    }
    else
    {
        k = s->len_a - s->stat->i_min;
        while (k--)
            rra(s, 0);
    }
}

void    cost_of_operation(t_stacks *s)
{
    int i;
    t_stack *tmp;
    
    i = s->len_b;
    while(i--)
    {
        min_max(s);
        cost_in_b(s);
        cost_in_a(s);
        //displayStack(s);
        throw_to_stack_a(s, find_min_cost(s));
        if (s->b != NULL)
        {
            s->b->cost->direction_a = 0;
            s->b->cost->direction_b = 0;
            s->b->cost->oper_a = 0;
            s->b->cost->oper_b = 0;
            tmp = s->b->next;
            while (tmp != s->b)
            {
                tmp->cost->direction_a = 0;
                tmp->cost->direction_b = 0;
                tmp->cost->oper_a = 0;
                tmp->cost->oper_b = 0;
                tmp = tmp->next;
            }   
        }
    }
   // displayStack(s);
    throw_to_begin(s);
    //find_new_begin_top(s);
}
