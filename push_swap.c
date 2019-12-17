/* This program implements a stack in terms of a linked list. */
# include <stdio.h>
# include <stdlib.h>
# include "libft/libft.h"

typedef struct s_stack
{
    int            element;
    struct s_stack *next;
}               t_stack;

typedef struct		s_stacks
{
	t_stack     *a;
	t_stack			*b;
  int         len_a;
}                 t_stacks;

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
there are duplicates. => check_duplicates(char **p)
check_duplicates(char **p) helps to detect cases like "01" or ""
*/

void  check_duplicates(char **p, t_stacks *s)
{
  int i;
  int k;
  int len;

  while (p[s->len_a])
    s->len_a++;
  ((len = s->len_a) == 0) ? exit(error()) : 0;
  if (len == 1)
  {
    i = 0;
    p[0][i] == '-' || p[0][i] == '+' ? i++ : 0;
    p[0][i] == '0' && p[0][++i] != '\0' ? exit(error()) : 0;
  }
  while(--len)
  {
    i = 0;
    k = len;
    while (i < k)
    {
       (p[k][0] == '0' && p[k][1] != '\0') ? exit(error()) : 0;
       if (ft_strlen(p[i]) == ft_strlen(p[k])) 
          ft_strcmp(p[i], p[k]) == 0 ? exit(error()) : i++;
       else 
          i++;
    }
  }
}

int varify_integer(char *p)
{
  int  i;

  i = 0;
  p[0] == '-' || p[0] == '+' ? i++ : 0;
  if (p[i] >= '3')
    exit(error());
  else if (p[i] == '2')
  { 
    i++;
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
  }
  return (1);
}

 t_stack    *getlist(char *p)
{
  t_stack *temporary;
  int i;

  i = 0;
  (ft_strlen(p) > 11) ? exit(error()) : 0;
  (ft_strlen(p) == 10 || (ft_strlen(p) == 11 && (p[i] == '-' || p[i] == '+'))) ? varify_integer(p) : 0;
  p[0] == '-' || p[0] == '+'  ? i++ : 0;
  while (p[i])
     ft_isdigit(p[i]) ? i++ : exit(error());
  temporary = (t_stack *)malloc(sizeof(t_stack));
  temporary -> element = ft_atoi(p);
  temporary -> next = NULL;
  return (temporary);
}

void  create_stack_a(char **argc, t_stacks *s)
{
  char      **p;
  int       i;

  i = -1;
  p = ft_strsplit(argc[1], ' ');
  check_duplicates(p, s);
  while(p[++i]) 
  {
    s->a = getlist(p[i]);
    push(s->a);
  }
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
  create_stack_a(argc, s);
  return(s);
}

int   main(int argv, char **argc)
{
  t_stacks   *s;

  if (argv == 2)
  {
    s = create_stacks(argc);
    displayStack();
  }
  else 
    exit(error());
  return(1);
}
