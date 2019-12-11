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

/* check the data: 
some arguments aren’t integers,
some arguments are bigger than an integer => varify_integer(char *p)
there are duplicates.
*/

int varify_integer(char *p)
{
  int  i;

  i = 0;
  p[i] == '-' ? i++ : 0;
  p[i] == '1' || p[i] == '2' ? i++ : exit(error());
  p[i] == '0' || p[i] == '1' ? i++ : exit(error());
  p[i] >= '0' && p[i] <= '4' ? i++ : exit(error());
  p[i] >= '0' && p[i] <= '7' ? i++ : exit(error());
  p[i] >= '0' && p[i] <= '4' ? i++ : exit(error());
  p[i] >= '0' && p[i] <= '8' ? i++ : exit(error());
  p[i] >= '0' && p[i] <= '3' ? i++ : exit(error());
  p[i] >= '0' && p[i] <= '6' ? i++ : exit(error());
  p[i] >= '0' && p[i] <= '4' ? i++ : exit(error());
  if (p[0] == '-')
    p[i] >= '0' && p[i] <= '8' ? i++ : exit(error());
  else 
    p[i] >= '0' && p[i] <= '7' ? i++ : exit(error());
  return (1);
}

 t_stack    *getlist(char *p)
{
  t_stack *temporary;
  int i;

  i = 0;
  (ft_strlen(p) > 11 || (ft_strlen(p) == 11 && p[i] != '-')) ? exit(error()) : 0;
  (ft_strlen(p) == 10 || (ft_strlen(p) == 11 && p[i] == '-')) ? varify_integer(p) : 0;
  p[0] == '-' ? i++ : 0;
  while (p[i])
     ft_isdigit(p[i]) ? i++ : exit(error());
  temporary = (t_stack *)malloc(sizeof(t_stack));
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

