#include "ft_push_swap.h"

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
    printf("conseq = %d ", temporary->for_max_seq);
    //printf("i = \t%d  cost %d", temporary->i, temporary->_cost);
    yellow();
    temporary = temporary->next;
    while(temporary != s->a)
    {
      printf("\t%d ", temporary->element);
      reset();
      printf("conseq = %d ", temporary->for_max_seq);
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

