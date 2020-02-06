
#include "ft_push_swap.h"

t_stack *begin = NULL;
t_stack *top = NULL;

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
   // printf("i = \t%d  cost %d", temporary->i, temporary->oper_cost);
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


/*void popItem()
{
 t_stack *temporary;
  
    if (top == NULL)
    {
        printf("\nStack is Exhausted");
        return;
    }
    temporary = begin;
    if (begin -> next == NULL)
    {
        printf("\nPopped Element is: %d ", top -> element);
        begin = NULL;
        free(top);
        top = NULL;
    }
    else 
    {   
        while(temporary -> next != top)
            temporary = temporary -> next;
        temporary -> next = NULL;
        printf("\n Popped Element is: %d ", top -> element);
        free(top);
        top = temporary;
    } 
}

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
    return (1);
  max = 1;
  compare_elements(s, &max);
  return(1);
}*/

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
  printf("max %d and i %d\n", s->stat->max, s->stat->i_max);
  printf("min %d and i %d\n", s->stat->min, s->stat->i_min);
}

int   main(int argv, char **argc)
{
  t_stacks   *s;

  if (argv == 2)
  {
    s = create_stacks(argc);
    s->len_b = throw_to_stack_b(s);
    printf("length a %d\n", s->len_a);
    printf("length b %d\n", s->len_b);
    cost_of_operation(s);
    //look_for_max_sequence(s);
    printf("\n");
    displayStack(s);
  }
  else 
    exit(error());
  return(1);
}