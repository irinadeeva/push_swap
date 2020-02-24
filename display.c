#include "ft_push_swap.h"

void display_stack(t_stacks *s)
{
  t_stack *temporary;
    
    if (s->a != NULL)
    {
      temporary = s->a;
      ft_printf("\nstack a \t%d " , temporary->element);
      if (temporary && temporary->next)
          temporary = temporary->next;
      while (temporary != s->top_a)
      {
        ft_printf("\t%d ", temporary->element);
        if (temporary && temporary->next)
            temporary = temporary->next;
      }
      if (s->top_a != s->a)
        ft_printf("\t%d ",s->top_a->element);
    }
    if (s->b != NULL)
    {
      temporary = s->b;
      ft_printf("\nstack b \t%d ", temporary->element);
      if (temporary && temporary->next)
          temporary = temporary->next;
      while (temporary != s->top_b)
      {
        ft_printf("\t%d ", temporary->element);
        if (temporary && temporary->next)
          temporary = temporary->next;
      }
      if (s->top_b != s->b)
        ft_printf("\t%d ", s->top_b->element);
      write(1, "\n", 1);
    }
    else 
      ft_printf("\nstack b empty\n");
 }

