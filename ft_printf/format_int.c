/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhugo <bhugo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 19:02:30 by bhugo             #+#    #+#             */
/*   Updated: 2019/12/11 20:35:15 by bhugo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_print.h"

/*
** отрабатываем длину переменной типа int
** и перекравающие друг друга параметры
** отправляем на печать в print_int
*/

int	format_int(t_printf *p)
{
	long long	d;
	char		*s;

	d = va_arg(p->arg_ptr, long long);
	if ((d == LLONG_MIN || d == LONG_MIN) &&
		p->length_l != 1 && p->length_ll != 1)
		(!(s = ft_strdup("0"))) ? exit(-1) : 0;
	else if (p->length_hh == 1)
		(!(s = ft_itoa((char)d))) ? exit(-1) : 0;
	else if (p->length_h == 1)
		(!(s = ft_itoa((short)d))) ? exit(-1) : 0;
	else if (p->length_l == 1 || p->length_ll == 1)
	{
		if (d == LLONG_MIN || d == LONG_MIN)
			(!(s = ft_strdup("-9223372036854775808"))) ? exit(-1) : 0;
		else
			(!(s = ft_long_itoa((long)d))) ? exit(-1) : 0;
	}
	else
		(!(s = ft_itoa((int)d))) ? exit(-1) : 0;
	p->flag_minus == 1 ? p->flag_zero = 0 : 0;
	p->precision > -1 ? p->flag_zero = 0 : 0;
	print_int(s, p);
	return (1);
}
