/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_upper_hex.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhugo <bhugo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 19:10:12 by bhugo             #+#    #+#             */
/*   Updated: 2019/12/11 20:40:54 by bhugo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_print.h"

/*
** отрабатываем длину переменной типа unsigned int as a hexadecimal number
** X - upper-case
** и перекравающие друг друга параметры
** отправляем на печать в print_oct
*/

int	format_upper_hex(t_printf *p)
{
	char					*s;
	unsigned long long int	u;

	u = va_arg(p->arg_ptr, unsigned long long int);
	if (p->length_h == 1)
		(!(s = ft_itoa_base_capital((unsigned short)u, 16))) ? exit(-1) : 0;
	if (p->length_hh == 1)
		(!(s = ft_itoa_base_capital((unsigned char)u, 16))) ? exit(-1) : 0;
	if (p->length_l == 1)
		(!(s = ft_itoa_base_capital_long((unsigned long int)u, 16))) ?
			exit(-1) : 0;
	if (p->length_ll == 1)
		(!(s = ft_itoa_base_capital_long((unsigned long long int)u, 16))) ?
			exit(-1) : 0;
	if (p->length_h + p->length_hh + p->length_l + p->length_ll == 0)
		(!(s = ft_itoa_base_capital(u, 16))) ? exit(-1) : 0;
	if (p->flag_minus == 1 || p->precision > -1)
		p->flag_zero = 0;
	if (s[0] == '0' && s[1] == '\0')
		p->flag_hash = 0;
	print_oct(s, p);
	return (1);
}
