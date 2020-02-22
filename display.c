#include "ft_push_swap.h"

void yellow()
{
  printf("\033[1;33m");
}

void reset () 
{
  printf("\033[0m");
}

void display_stack(t_stacks *s)
{
  t_stack *temporary;
    
    if (s->a != NULL)
    {
      temporary = s->a;
      printf("stack a \t%d " , temporary->element);
      if (temporary && temporary->next)
          temporary = temporary->next;
      while(temporary != s->a)
      {
        printf("\t%d ", temporary->element);
        reset();
        yellow();
        temporary = temporary->next;
      }
    }
    if (s->b != NULL)
    {
      temporary = s->b;
      printf("\nstack b \n\t%3d ", temporary->element);
      reset();
      yellow();
      if (temporary->next != NULL)
          temporary = temporary->next;
      while(temporary != s->b)
      {
        printf("\t%d ", temporary->element);
        reset();
        yellow();
        if (temporary->next != NULL)
          temporary = temporary->next;
      }
    }
    else 
      printf("\nstack b empty\n");
 }

