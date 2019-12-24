
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

void displayStack()
{
  t_stack *temporary;

    temporary = begin;
    printf("%d", temporary -> element);
    printf("\t%d ", temporary -> for_max_seq);
    while(temporary != top)
    {
      temporary = temporary -> next;
      printf("\t%d ", temporary -> element);
      reset();
      printf("\t%d ", temporary -> for_max_seq);
      yellow();
    }
 }

void push(t_stack *a)
{
   t_stack *temporary;

    if (a == NULL)
    {
        printf("\nThe Stack is Completely Fillled");
        return;
    }
    if (begin == NULL)
    {
        begin = a;
        top = a;
    }
    else 
    {
      temporary = begin;
      while (temporary -> next != NULL)
          temporary = temporary -> next;
      temporary -> next = a;
      top = a;
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
	return (-1);
}

void  compare_elements(int *max)
{
  t_stack  *tmp;
  t_stack  *tmp_2;

  tmp = begin;
  tmp_2 = tmp->next;
  while (tmp_2)
   {
     tmp = begin;
     while (tmp->i < tmp_2->i)
     {
       if (tmp->element < tmp_2->element)
       {
         if(tmp_2->for_max_seq <= tmp->for_max_seq)
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


int  look_for_max_sequence()
{
  int      max;

  if (begin == top) 
    return (1);
  max = 1;
  compare_elements(&max);
  return(1);
}


int   main(int argv, char **argc)
{
  t_stacks   *s;

  if (argv == 2)
  {
    s = create_stacks(argc);
    look_for_max_sequence();
    displayStack();
  }
  else 
    exit(error());
  return(1);
}
