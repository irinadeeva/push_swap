
# include "ft_push_swap.h"

t_stack *begin = NULL;
t_stack *top = NULL;

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
      printf("\t%d ", temporary -> for_max_seq);
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

int  look_for_max_sequence()
{
   t_stack  *tmp;
   t_stack  *tmp_2;
   int  max;

  if (begin == top) 
    return (1);
   tmp = begin;
   tmp_2 = tmp->next;
   max = 1;
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
            max < tmp_2->for_max_seq ? max = tmp_2->for_max_seq : 0;
          }
       }
      tmp = tmp->next;
     }
     tmp_2 = tmp_2->next;
   }
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
