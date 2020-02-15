/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhugo <bhugo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 16:31:38 by bhugo             #+#    #+#             */
/*   Updated: 2020/02/15 19:05:36 by bhugo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_checker.h"

void    run_operations(t_operations *operations, t_stacks *s)
{
    t_operations    *tmp;

    tmp = operations;
    while (tmp)
    {
        ft_strcmp(tmp->commad, "pa") == 0 ? pa(s, 1) : 0;
        ft_strcmp(tmp->commad, "pb") == 0 ? pb(s, 1) : 0;
        ft_strcmp(tmp->commad, "sa") == 0 ? sa(s, 1) : 0;
        ft_strcmp(tmp->commad, "sb") == 0 ? sb(s, 1) : 0;
        ft_strcmp(tmp->commad, "ss") == 0 ? ss(s, 1) : 0;
        ft_strcmp(tmp->commad, "ra") == 0 ? ra(s, 1) : 0;
        ft_strcmp(tmp->commad, "rb") == 0 ? rb(s, 1) : 0;
        ft_strcmp(tmp->commad, "rr") == 0 ? rr(s, 1) : 0;
        ft_strcmp(tmp->commad, "rra") == 0 ? rra(s, 1) : 0;
        ft_strcmp(tmp->commad, "rrb") == 0 ? rrb(s, 1) : 0;
        ft_strcmp(tmp->commad, "rrr") == 0 ? rrr(s, 1) : 0;
        tmp = tmp->next;
    }
}

void    check_operations(char *str)
{
    if (ft_strcmp(str, "pa") != 0 && ft_strcmp(str, "pb") != 0 && 
        ft_strcmp(str, "sa") != 0 && ft_strcmp(str, "sb") != 0 && 
        ft_strcmp(str, "ss") != 0 && ft_strcmp(str, "rr") != 0 && 
        ft_strcmp(str, "ra") != 0 && ft_strcmp(str, "rb") != 0 && 
        ft_strcmp(str, "rra") != 0 && ft_strcmp(str, "rrb") != 0 && 
        ft_strcmp(str, "rrr") != 0)
        exit(error());
}

t_operations    *read_commands()
{
    t_operations    *operations;
    t_operations    *tmp;
    t_operations    *tmp2;

    if (!(operations = (t_operations*)malloc(sizeof(t_operations))))
        exit(error());
    if (get_next_line(STDIN, &operations->commad) == -1)
        exit(error());
    check_operations(operations->commad);
    if (!(tmp = (t_operations*)malloc(sizeof(t_operations))))
        exit(error());
    operations->next = tmp;
    while (get_next_line(STDIN, &tmp->commad) > 0)
    {
        check_operations(tmp->commad);
        if (!(tmp2 = (t_operations*)malloc(sizeof(t_operations))))
            exit(error());
        tmp->next = tmp2;
        tmp = tmp->next;   
    }
    return(operations);
}


int main(int argv, char **argc)
{
    t_stacks        *s;
    t_operations    *operations;
    
    if (argv >= 2)
    {
        s = create_stacks(argv, argc);
        operations = read_commands();
        //run_operations(operations, s);
        if ( check_sort(s, argv - 1) == 1)
            write(1, "OK", 2);
        else
             write(1, "KO", 2);
    }
    return (1);
}