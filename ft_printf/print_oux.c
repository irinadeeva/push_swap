/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_oux.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhugo <bhugo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 19:57:18 by bhugo             #+#    #+#             */
/*   Updated: 2019/12/11 20:45:13 by bhugo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_print.h"

/*
** печать с обработкой флагов o,u, x, X
*/

void	printf_hash(char *s, t_printf *p)
{
	if (p->specifier == 'o' && p->flag_hash == 1 && s[0] == '0' && s[1] == '\0')
		p->flag_hash = 0;
	if (p->specifier == 'x' && p->flag_hash == 1 && s[0] == '0' && s[1] == '\0')
		p->flag_hash = 0;
	if (p->specifier == 'X' && p->flag_hash == 1 && s[0] == '0' && s[1] == '\0')
		p->flag_hash = 0;
	if (p->flag_hash == 1 && s != '\0')
	{
		p->specifier == 'o' ? write_buffer("0", 0, p) : 0;
		p->specifier == 'x' ? ft_putstr_buffer("0x", p) : 0;
		p->specifier == 'X' ? ft_putstr_buffer("0X", p) : 0;
	}
}

void	print_order(char *s, t_printf *p, int i, int sign)
{
	printf_hash(s, p);
	printf_width(s, p, sign);
	while (s[i] != '\0')
		write_buffer(&s[i++], 0, p);
}

void	print_oct(char *s, t_printf *p)
{
	int sign;
	int i;

	i = 0;
	sign = check_sign(&s, p);
	reload_output_with_precision(&s, p);
	if (p->flag_zero == 1)
		print_order(s, p, i, sign);
	else if (p->flag_minus == 1)
	{
		printf_hash(s, p);
		while (s[i] != '\0')
			write_buffer(&s[i++], 0, p);
		printf_width(s, p, sign);
	}
	else
	{
		printf_width(s, p, sign);
		printf_hash(s, p);
		while (s[i] != '\0')
			write_buffer(&s[i++], 0, p);
	}
	free(s);
}
