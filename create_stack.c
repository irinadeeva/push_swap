# include "ft_push_swap.h"

/* 
** This functions  - implement a stack in terms of a linked list
**                 - varify data (only integers).
*/ 


void push(t_stacks *s, t_stack *temporary)
{
    //if (s->a == NULL)
    //{
    //   printf("\nThe Stack is Completely Fillled");
    //    return;
    //}
    if (s->top_a == NULL)
    {
      s->top_a = temporary;
      s->a = temporary;
    }
    else if(s->top_a->next == NULL) 
    {
      s->top_a->next = temporary;
      s->top_a = s->top_a->next;
    }
}

t_cost  *create_cost()
{
  t_cost     *temporary;
  
  temporary = (t_cost *)malloc(sizeof(t_cost));
  temporary->direction_a = 0;
  temporary->direction_b = 0;
  temporary->oper_a = 0;
  temporary->oper_b = 0;
  return (temporary);
}


 t_stack    *getlist(char *p, int k)
{
  t_stack     *temporary;
  int         i;

  i = 0;
  (ft_strlen(p) > 11) ? exit(error()) : 0;
  (ft_strlen(p) == 10 || (ft_strlen(p) == 11 && (p[i] == '-' || p[i] == '+'))) ? varify_integer(p) : 0;
  p[0] == '-' || p[0] == '+'  ? i++ : 0;
  while (p[i])
     ft_isdigit(p[i]) ? i++ : exit(error());
  temporary = (t_stack *)malloc(sizeof(t_stack));
  temporary->element = ft_atoi(p);
  temporary->i = k;
  temporary->cost = create_cost();
  temporary->next = NULL;
  free(p);
  return (temporary);
}

void  create_stack_a(char **argc, t_stacks *s)
{
  t_stack     *temporary;
  char      **p;
  int       i;
  int       k;

  i = -1;
  k = 0;
  if (!(p = ft_strsplit(argc[1], ' ')))
      exit(error());
  check_duplicates(p, s);
  while(p[++i]) 
  {
    temporary = getlist(p[i], k);
    k++;
    push(s, temporary);
  }
  s->top_a->next = s->a;
  free(p);
}

t_stat  *create_statistic()
{
  t_stat     *temporary;
  
  temporary = (t_stat *)malloc(sizeof(t_stat));
  temporary->i_max = 0;
  temporary->i_min = 0;
  temporary->max = 0;
  temporary->min = 0;
  return (temporary);
}

t_stacks *create_stacks(char **argc)
{
  t_stacks *s;

  if (!(s = (t_stacks*)malloc(sizeof(t_stacks))))
    exit(error());
  s->a = NULL;
  s->b = NULL;
  s->len_a = 0;
  s->len_b = 0;
  s->top_a = NULL;
  s->top_b = NULL;
  s->stat = create_statistic();
  create_stack_a(argc, s);
  return(s);
}