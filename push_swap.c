/* This program implements a stack in terms of a linked list. */
# include <stdio.h>
# include <stdlib.h>
# include "libft/libft.h"

typedef struct s_stack
{
    char element;
    struct s_stack *next;
}               t_stack;

t_stack *begin = NULL;
t_stack *top = NULL;

t_stack *getnode()
{
   t_stack *temporary;

    temporary=(t_stack *) malloc( sizeof(t_stack)) ;
    printf("\nEnter Element (0 <= N <= 30000): ");
    scanf("%d", &temporary -> element);
    temporary -> next = NULL;
    return (temporary);
}

void push(t_stack *newnode)
{
   t_stack *temporary;

    if(newnode == NULL)
    {
        printf("\nThe Stack is Completely Fillled");
        return;
    }
    if (begin == NULL)
    {
        begin = newnode;
        top = newnode;
    }
    else 
    {
    temporary = begin;
    while( temporary -> next != NULL)
        temporary = temporary -> next;
    temporary -> next = newnode;
    top = newnode;
    }
    printf("\nElement is pushed into the Stack");
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

void displayStack()
{
 t_stack *temporary;

  if (top == NULL)
    printf("\nStack is Exhausted ");
  else
  {
    temporary = begin;
    printf("\nElements in the stack : ");
    printf("\nLeft-Most Element Represents Bottom  :  ");
    printf("Right-Most Element Represents Top \n\n");
    printf("%d", temporary -> element);
    while(temporary != top)
    {
      temporary = temporary -> next;
      printf("\t%d ", temporary -> element);
    }
  }
 }

int stackMenu()
{
  int intChoice;

  printf("\n\nEnter 1 to Push an Element into Stack. ");
  printf("\nEnter 2 to Pop an Element from Stack. ");
  printf("\nEnter 3 to Displays the Stack on the Screen.");
  printf("\nEnter 4 to Stop the Execution of Program.");
  printf("\nEnter your choice (0 <= N <= 4): ");
  scanf("%d", &intChoice);
  
  return intChoice;
}

void main(int argv, char **argc)
{
  int     intChoice;
  t_stack *newnode;
  char **p;

  /* check the data*/
  p = ft_strsplit(argc[1], ' ');
  do
  {
    intChoice = stackMenu();
    switch(intChoice)
    {
      case 1:
        newnode = getnode();
        push(newnode);
        break;
      case 2:
        popItem();
        break;
      case 3:
        displayStack();
        break;
      case 4:
        exit(0);
    }
    fflush(stdin);
  } 
  while (1);
}

