#ifndef FT_PUSH_SWAP_H
# define FT_PUSH_SWAP_H

# include "libft/libft.h"
# include <stdio.h>
# include <stdlib.h>

typedef struct s_stack
{
    int            element;
    int            i;                  // number of an element
    int            for_max_seq;
    struct s_stack *next;
}               t_stack;

typedef struct s_statistic
{
    int            min;
    int            max;
    int            i_min;
    int            i_max;
}               t_stat;

typedef struct		s_stacks
{
	t_stack     *a;
	t_stack		*b;
    t_stack     *top_a;
    t_stack     *top_b;
    t_stat      *stat;
    int         len_a;
}                 t_stacks;

void    check_duplicates(char **p, t_stacks *s);
int     varify_integer(char *p);
int		error(void);
t_stacks *create_stacks(char **argc);
void    push(t_stacks *s, t_stack *temporary);
void    pb(t_stacks *s);
void  throw_to_stack_b(t_stacks *s);
void    sa(t_stacks *s);
void    ra(t_stacks *s);
void    rra(t_stacks *s);
void  sort_3(t_stacks *s)

#endif