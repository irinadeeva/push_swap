/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhugo <bhugo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 18:28:40 by bhugo             #+#    #+#             */
/*   Updated: 2020/02/03 20:15:53 by bhugo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void  pb(t_stacks *s)
{
  if (s->top_b == NULL)
    {
      s->top_b = s->a;
      s->b = s->a;
      s->a = s->a->next;
      s->b->next = NULL;
      s->top_a->next = s->a;
    }
  else if(s->top_b->next == NULL) 
  {
    s->top_b->next = s->a;
    s->a = s->a->next;
    s->top_b = s->top_b->next;
    s->top_b->next = NULL;
    s->top_a->next = s->a;
  }
}

void sa(t_stacks *s)
{
    
}

void ra(t_stacks *s)
{
    
}

void rra(t_stacks *s)
{
    
}