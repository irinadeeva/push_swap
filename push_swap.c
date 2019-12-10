/* This program implements a stack in terms of a linked list. */
# include <stdio.h>
# include <stdlib.h>
# include "libft/libft.h"

typedef struct s_stack
{
    int            element;
    struct s_stack *next;
}               t_stack;

t_stack *begin = NULL;
t_stack *top = NULL;


void displayStack()
{
  t_stack *temporary;

  //if (top == NULL)
  //  printf("\nStack is Exhausted ");
  //else
 // {
      temporary = begin;
   // printf("\nElements in the stack : ");
   // printf("\nLeft-Most Element Represents Bottom  :  ");
   // printf("Right-Most Element Represents Top \n\n");
    printf("%d", temporary -> element);
    while(temporary != top)
    {
      temporary = temporary -> next;
      printf("\t%d ", temporary -> element);
    }
 // }
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

 t_stack    *getlist(char *p)
{
  t_stack *temporary;
  int i;

  i = 0;
  temporary = (t_stack *)malloc(sizeof(t_stack));
  while (p[i])
  {
    if (ft_isdigit(p[i]) || p[i] == '-')
        i++;
    else
      exit(error());
  }
  temporary -> element = ft_atoi(p);
  temporary -> next = NULL;
  return (temporary);
}

int   main(int argv, char **argc)
{
  t_stack   *a;
  char      **p;
  int       i;

  i = -1;
  /* check the data*/
  if (argv == 2)
  {
    p = ft_strsplit(argc[1], ' ');
    while(p[++i]) 
    {
      a = getlist(p[i]);
      push(a);
    }
  displayStack();
  }
  else 
    exit(error());
  return(1);
}

