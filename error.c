/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhugo <bhugo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/15 15:18:54 by bhugo             #+#    #+#             */
/*   Updated: 2020/02/18 15:49:22 by bhugo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_push_swap.h"

int		error(void)
{
  write(1, "Error\n", 6);
	exit(1);
}

void yellow()
{
  printf("\033[1;33m");
}

void reset () 
{
  printf("\033[0m");
}

void displayStack(t_stacks *s)
{
  t_stack *temporary;

    temporary = s->a;
    
    printf("stack a \t%d " , temporary->element);
    reset();
    //printf("i = \t%d  cost %d", temporary->i, temporary->_cost);
    yellow();
    temporary = temporary->next;
    while(temporary != s->a)
    {
      printf("\t%d ", temporary->element);
      reset();
    // printf("i = \t%d  cost %d", temporary->i, temporary->oper_cost);
      yellow();
      temporary = temporary->next;
    }
    if (s->b != NULL)
    {
      temporary = s->b;
      printf("\n stack b \n\t%3d ", temporary->element);
      reset();
      printf("i = %d  cost all %d cost a %d  direction a %d cost b %d direction a %d\n", temporary->i, temporary->cost->oper_a + temporary->cost->oper_b,  temporary->cost->oper_a, temporary->cost->direction_a, temporary->cost->oper_b, temporary->cost->direction_b);
      yellow();
      temporary = temporary->next;
      while(temporary != s->b)
      {
        printf("\t%3d ", temporary->element);
        reset();
        printf("i = %d  cost all %d cost a %d  direction a %d cost b %d direction a %d\n", temporary->i, temporary->cost->oper_a + temporary->cost->oper_b,  temporary->cost->oper_a, temporary->cost->direction_a, temporary->cost->oper_b, temporary->cost->direction_b);
        yellow();
        temporary = temporary->next;
      }
    }
    else 
      printf("\n stack b empty");
 }

 void  free_stacks(t_stacks *s)
{
  t_stack *tmp;
  t_stack *tmp2;

  tmp = s->a;
  tmp2 = tmp->next;
  while (s->len_a--)
  {
    free(tmp);
    free(tmp->cost);
    tmp = tmp2;
    tmp2 = tmp2->next; 
  }
  free(s->stat);
  free(s);
}

void min_max(t_stacks *s)
{
	t_stack  *tmp;

  tmp = s->a;
  s->stat->i_max = tmp->i;
  s->stat->max = tmp->element;
  s->stat->i_min = tmp->i;
	s->stat->min = tmp->element;
  tmp = tmp->next;
  while (tmp != s->a)
  {
    if (tmp->element > s->stat->max)
    {
      s->stat->i_max = tmp->i;
      s->stat->max = tmp->element;
    }
    else if (tmp->element < s->stat->min)
    {
      s->stat->i_min = tmp->i;
	    s->stat->min = tmp->element;
    }
    tmp = tmp->next;
  }
  //printf("max %d and i %d\n", s->stat->max, s->stat->i_max);
  //printf("min %d and i %d\n", s->stat->min, s->stat->i_min);
}