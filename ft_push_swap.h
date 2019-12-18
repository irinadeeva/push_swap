#ifndef FT_PUSH_SWAP_H
# define FT_PUSH_SWAP_H

# include "libft/libft.h"
# include <stdio.h>
# include <stdlib.h>

typedef struct s_stack
{
    int            element;
    int            i;
    struct s_stack *next;
}               t_stack;

typedef struct		s_stacks
{
	t_stack     *a;
	t_stack			*b;
 //   t_stack     *begin;
 //   t_stack     *top;
    int         len_a;
}                 t_stacks;

void    check_duplicates(char **p, t_stacks *s);
int     varify_integer(char *p);
int		error(void);
t_stacks *create_stacks(char **argc);
void push(t_stack *a);

#endif