/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhugo <bhugo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 18:28:40 by bhugo             #+#    #+#             */
/*   Updated: 2020/02/05 18:09:55 by bhugo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void  pa(t_stacks *s)
{
  t_stack *tmp;
  t_stack *tmp2;
  
  if (s->top_b == s->b)
    {
      tmp = s->a;
      s->a = s->b;
      s->top_a->next = s->a;
      s->a->next = tmp;
      s->b = NULL;
      s->top_b = NULL;
    }
  else
  {
    tmp = s->b;
    s->top_b->next = s->b->next;
    s->b = s->b->next;
    tmp2 = s->a;
    s->a = tmp;
    s->top_a->next = s->a;
    s->a->next = tmp2;
  }
}

void  pb(t_stacks *s)
{
  t_stack *tmp;
  
  if (s->top_b == NULL)
    {
      s->top_b = s->a;
      s->b = s->a;
      s->a = s->a->next;
      s->top_a->next = s->a;
      s->b->next = NULL;
    }
  else if(s->top_b->next == NULL) 
  {
    tmp = s->b;
    s->b = s->a;
    s->a = s->a->next;
    s->top_a->next = s->a;
    s->b->next = tmp;
  }
}

void sa(t_stacks *s)
{
  t_stack *tmp;

  tmp = s->a;
  s->a = s->a->next;
  s->top_a->next = s->top_a->next->next;
  tmp->next = s->top_a;
  s->a->next = tmp;
}

void sb(t_stacks *s)
{
  t_stack *tmp;

  tmp = s->b;
  s->b = s->b->next;
  s->top_b->next = s->top_b->next->next;
  tmp->next = s->top_b;
  s->b->next = tmp;
}

void ss(t_stacks *s)
{
  sb(s);
  sa(s);
}


void ra(t_stacks *s)
{
  s->top_a = s->a;
  s->a = s->a->next;
}

void rb(t_stacks *s)
{
  s->top_b = s->b;
  s->b = s->b->next;
}

void  rr(t_stacks *s)
{
  ra(s);
  rb(s);
}

void rra(t_stacks *s)
{
  s->a = s->top_a;
  s->top_a = s->a->next->next;
}

void rrb(t_stacks *s)
{
  s->b = s->top_b;
  s->top_b = s->b->next->next;
}

void  rrr(t_stacks *s)
{
  rrb(s);
  rra(s);
}