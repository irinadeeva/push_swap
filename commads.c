/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhugo <bhugo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 18:28:40 by bhugo             #+#    #+#             */
/*   Updated: 2020/02/04 19:54:24 by bhugo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

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

void ra(t_stacks *s)
{
  s->top_a = s->a;
  s->a = s->a->next;
}

void rra(t_stacks *s)
{
  s->a = s->top_a;
  s->top_a = s->a->next->next;
}