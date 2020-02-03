/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   throwing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhugo <bhugo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 18:39:47 by bhugo             #+#    #+#             */
/*   Updated: 2020/02/03 18:55:40 by bhugo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

/* 
** throwing elements of stack a to stack b until
** - they are sorted or
** - they are 3 
*/

int check_sort(t_stacks *s, int quality)
{
  t_stack  *tmp;
  t_stack  *tmp_2;
  int i;

  i = 1;
  tmp = s->a;
  tmp_2 = tmp->next;
  while (tmp_2 != s->a)
  {
    if (tmp_2->element > tmp->element)
      i++;
    tmp = tmp->next;
    tmp_2 = tmp->next;
  }
  if (i == quality)
    return (1);
  return (0);
}

void  throw_to_stack_b(t_stacks *s)
{
  t_stack  *tmp;
  int quality;
  
  quality = s->len_a;
  printf("sort: %d\n", check_sort(s, quality));
  tmp = s->a;
  while (quality > 3 && check_sort(s, quality) == 0)
  {
    pb(s);
    quality--;   
  }
  if (quality != s->len_a)
      s->top_b->next = s->b;
  if (quality == 3)
    sort_3(s->a);
}