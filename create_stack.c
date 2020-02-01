# include "ft_push_swap.h"

/* 
** This functions  - implement a stack in terms of a linked list
**                 - varify data (only integers).
*/ 

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
  temporary -> element = ft_atoi(p);
  temporary -> i = k;
  temporary -> for_max_seq = 1;
  temporary -> next = NULL;
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

t_stacks *create_stacks(char **argc)
{
  t_stacks *s;

  if (!(s = (t_stacks*)malloc(sizeof(t_stacks))))
    exit(error());
  s->a = NULL;
  s->b = NULL;
  s->len_a = 0;
  s->top_a = NULL;
  s->top_b = NULL;
  create_stack_a(argc, s);
  return(s);
}