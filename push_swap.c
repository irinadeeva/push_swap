/* This program implements a stack in terms of a linked list. */
# include "ft_push_swap.h"

t_stack *begin = NULL;
t_stack *top = NULL;

void displayStack()
{
  t_stack *temporary;

    temporary = begin;
    printf("%d", temporary -> element);
    while(temporary != top)
    {
      temporary = temporary -> next;
      printf("\t%d ", temporary -> element);
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

void  look_for_max_sequence(t_stacks *s)
{
   t_stack  *temporary;

   temporary = begin;
   
}

int   main(int argv, char **argc)
{
  t_stacks   *s;

  if (argv == 2)
  {
    s = create_stacks(argc);
    look_for_max_sequence(s);
    displayStack();
  }
  else 
    exit(error());
  return(1);
}
