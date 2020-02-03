
# include "ft_push_swap.h"

t_stack *begin = NULL;
t_stack *top = NULL;


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
    printf("\t%d", temporary->element);
    reset();
    printf("\t%d ", temporary->for_max_seq);
    yellow();
    temporary = temporary->next;
    while(temporary != s->a)
    {
      printf("\t%d ", temporary->element);
      reset();
      printf("\t%d ", temporary->for_max_seq);
      yellow();
      temporary = temporary->next;
    }
 }

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

void popItem()
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

int		error(void)
{
	write(1, "Error\n", 6);
	exit(1);
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


/*void  rra(t_stacks   *s)
{
  t_stack  *tmp;
  t_stack  *tmp2;
  int i;

  i = 1;
  tmp = begin;
  while (s->len_a - i > 1)
  {
    tmp = tmp->next;
    i++;
  }
  tmp->next = NULL;
  tmp2 = top;
  top = tmp;
  if (tmp2 != NULL)
	{
		tmp2->next = begin;
		begin = tmp2;
	}
}*/

/*void  indexation()
{
  t_stack  *tmp;
  int i;
  
  tmp = begin;
  i = 0;
  while(tmp->next != top)
  {
    tmp->i = i;
    tmp = tmp-> next;
    i++;
  }
}*/


int  look_for_max_sequence(t_stacks *s)
{
  int      max;

  if (s->a == s->top_a) 
    return (1);
  max = 1;
  compare_elements(s, &max);
  return(1);
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
  printf("max %d and i %d\n", s->stat->max, s->stat->i_max);
  printf("min %d and i %d\n", s->stat->min, s->stat->i_min);
}



int   main(int argv, char **argc)
{
  t_stacks   *s;

  if (argv == 2)
  {
    s = create_stacks(argc);
    min_max(s);
    //look_for_max_sequence(s);
    displayStack(s);
  }
  else 
    exit(error());
  return(1);
}
