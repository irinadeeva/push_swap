/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhugo <bhugo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 19:50:22 by bhugo             #+#    #+#             */
/*   Updated: 2019/12/11 20:45:24 by bhugo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_print.h"

void	printf_sign(t_printf *p, int sign)
{
	if (sign == 1 || p->flag_space == 1)
	{
		if (p->flag_plus == 1)
			write_buffer("+", 0, p);
		else
			write_buffer(" ", 0, p);
	}
	else if (sign == -1)
		write_buffer("-", 0, p);
}

void	printf_order(char *s, t_printf *p, int i, int sign)
{
	printf_sign(p, sign);
	printf_width(s, p, sign);
	while (s[i] != '\0')
		write_buffer(&s[i++], 0, p);
}

/*
** печать с обработкой флагов integer
*/

void	print_int(char *s, t_printf *p)
{
	int sign;
	int i;

	i = 0;
	sign = check_sign(&s, p);
	reload_output_with_precision(&s, p);
	if (p->flag_zero == 1)
		printf_order(s, p, i, sign);
	else if (p->flag_minus == 1)
	{
		printf_sign(p, sign);
		while (s[i] != '\0')
			write_buffer(&s[i++], 0, p);
		printf_width(s, p, sign);
	}
	else
	{
		printf_width(s, p, sign);
		printf_sign(p, sign);
		while (s[i] != '\0')
			write_buffer(&s[i++], 0, p);
	}
	free(s);
}
