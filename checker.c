/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhugo <bhugo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 16:31:38 by bhugo             #+#    #+#             */
/*   Updated: 2020/02/17 21:15:02 by bhugo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_checker.h"

void    run_operations(t_operations *operations, t_stacks *s)
{
    t_operations    *tmp;

    tmp = operations;
    while (tmp != NULL)
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
    int             i;

    if (!(tmp = (t_operations*)malloc(sizeof(t_operations))))
        exit(error());
    if ((i = get_next_line(STDIN, &tmp->commad)) == -1)
        exit(error());
    if (!tmp->commad)
        return(NULL);
    check_operations(tmp->commad);
    tmp->next = NULL;
    operations = tmp;
    while (i > 0)
    {
        if (!(tmp2 = (t_operations*)malloc(sizeof(t_operations))))
            exit(error());
        if ((i = get_next_line(STDIN, &tmp2->commad)) == -1)
            exit(error());
        if (i < 1)
        {
            free(tmp2);
            break;
        }
        check_operations(tmp2->commad);
        tmp->next = tmp2;
        tmp = tmp->next;   
        tmp->next = NULL;
    }
    return(operations);
}


void    free_operations(t_operations *operations)
{
    t_operations *tmp;
    t_operations *tmp2;

    tmp = operations;
    tmp2 = tmp->next;
    while (tmp)
    {
        free(tmp);
        tmp = tmp2;
        if (tmp2->next != NULL)
            tmp2 = tmp2->next;
        else
            tmp2 = NULL;
    }
}

int main(int argv, char **argc)
{
    t_stacks        *s;
    t_operations    *operations;
    
    if (argv >= 2)
    {
        s = create_stacks(argv, argc);
        operations = read_commands();
        run_operations(operations, s);
        if (check_sort(s, argv - 1) == 1)
            write(1, "OK\n", 3);
        else
            write(1, "KO\n", 3);
    free_stacks(s);
    //free_operations(operations);
    }
    return (1);
}