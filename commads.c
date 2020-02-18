/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhugo <bhugo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 18:28:40 by bhugo             #+#    #+#             */
/*   Updated: 2020/02/18 19:11:53 by bhugo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void  pa(t_stacks *s, int print)
{
  t_stack *tmp;
  t_stack *tmp2;
  
  if (s->b == NULL)
    return;
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
  if (print == 0)
    ft_printf("pa\n");
}

void  pb(t_stacks *s, int print)
{
  t_stack *tmp;
  
  if (s->a == NULL)
    return;
  if (s->top_b == NULL)
    {
      s->top_b = s->a;
      s->b = s->a;
      if (s->a != s->top_a)
      {
          s->a = s->a->next;
          s->top_a->next = s->a;
      }
      else
      {
        s->a = NULL;
        s->top_a = NULL;
      }
      s->b->next = NULL;
    }
  else if(s->top_b->next == NULL) 
  {
    tmp = s->b;
    s->b = s->a;
    if (s->a != s->top_a)
    {
          s->a = s->a->next;
          s->top_a->next = s->a;
    }
    else
    {
      s->a = NULL;
      s->top_a = NULL;
    }
    s->b->next = tmp;
  }
  if (print == 0)
    ft_printf("pb\n");
}

void sa(t_stacks *s, int print)
{
  t_stack *tmp;

  if (s->a == NULL || s->a == s->top_a)
    return;
  tmp = s->a->next;
  s->top_a->next = tmp;
  s->a->next = tmp->next;
  tmp->next = s->a;
  s->a = tmp;
  if (print == 0)
    ft_printf("sa\n");
}

void sb(t_stacks *s, int print)
{
  t_stack *tmp;

  if (s->b == NULL || s->b == s->top_b)
    return;
  tmp = s->b->next;
  s->top_b->next = tmp;
  s->b->next = tmp->next;
  tmp->next = s->b;
  s->b = tmp;
  if (print == 0)
    ft_printf("sa\n");
}

void ss(t_stacks *s, int print)
{
  sb(s, 0);
  sa(s, 0);
  if (print == 0)
    ft_printf("ss\n");
}


void ra(t_stacks *s, int print)
{
  if (s->a == NULL)
    return;
  s->top_a = s->a;
  s->a = s->a->next;
  if (print == 0)
    ft_printf("ra\n");
}

void rb(t_stacks *s, int print)
{
  if (s->b == NULL)
    return;
  s->top_b = s->b;
  s->b = s->b->next;
  if (print == 0)
    ft_printf("rb\n");
}

void  rr(t_stacks *s, int print)
{
  ra(s, 1);
  rb(s, 1);
  if (print == 0)
    ft_printf("rr\n");
}

void rra(t_stacks *s, int print)
{
  t_stack *tmp;

  if (s->a == NULL)
    return;
  tmp = s->a;
  while (tmp->next != s->top_a)
    tmp = tmp->next;
  s->a = s->top_a;
  s->top_a = tmp;  
  s->top_a->next = s->a;
  if (print == 0)
    ft_printf("rra\n");
}

void rrb(t_stacks *s, int print)
{
  t_stack *tmp;

  if (s->b == NULL || s->b == s->top_b)
    return;
  tmp = s->b;
  while (tmp->next != s->top_b)
    tmp = tmp->next;
  s->b = s->top_b;
  s->top_b = tmp;  
  s->top_b->next = s->b;
  if (print == 0)
    ft_printf("rrb\n");
}

void  rrr(t_stacks *s, int print)
{
  rrb(s, 1);
  rra(s, 1);
  if (print == 0)
    ft_printf("rrr\n");
}