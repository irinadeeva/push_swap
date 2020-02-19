
#include "ft_push_swap.h"

void  compare_elements(t_stacks *s, int *max)
{
  t_stack  *tmp;
  t_stack  *tmp_2;

  tmp = s->a;
  tmp_2 = tmp->next;
  while (tmp_2 != s->a)
   {
     tmp = s->a;
     while (tmp->i < tmp_2->i)
     {
       if (tmp->element < tmp_2->element)
       {
         if (tmp_2->for_max_seq <= tmp->for_max_seq)
          { 
            tmp_2->for_max_seq = tmp->for_max_seq + 1;
            *max < tmp_2->for_max_seq ? *max = tmp_2->for_max_seq : 0;
          }
       }
      tmp = tmp->next;
     }
     tmp_2 = tmp_2->next;
   }
}

int  look_for_max_sequence(t_stacks *s)
{
  int      max;

  if (s->a == s->top_a) 
    return (0);
  max = 1;
  compare_elements(s, &max);
  displayStack(s);
  
    return(max);
}


int   main(int argv, char **argc)
{
  t_stacks   *s;
  //int  max_sequence;

  if (argv > 1)
  {
    s = create_stacks(argv, argc);
   // printf("\n max %d\n", max_sequence = look_for_max_sequence(s));
    s->len_b = throw_to_stack_b(s);
    cost_of_operation(s);
    free_stack(s);
  }
  return(1);
}