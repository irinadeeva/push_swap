/* This program implements a stack in terms of a linked list. */
# include <stdio.h>
# include <stdlib.h>

struct intStack
{
    int element;
    struct intStack *next;
};

typedef struct intStack node;
node *begin=NULL;
node *top = NULL;

node* getnode()
{
    node *temporary;

    temporary=(node *) malloc( sizeof(node)) ;
    printf("\nEnter Element (0 <= N <= 30000): ");
    scanf("%d", &temporary -> element);
    temporary -> next = NULL;
    return (temporary);
}

void pushItem(node *newnode)
{
    node *temporary;

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
  node *temporary;
  
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
  node *temporary;

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

void main()
{
  int intChoice;
  node *newnode;
  
  do
  {
    intChoice = stackMenu();
    switch(intChoice)
    {
      case 1:
        newnode = getnode();
        pushItem(newnode);
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

