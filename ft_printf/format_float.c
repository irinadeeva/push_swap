/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_float.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhugo <bhugo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 12:21:19 by bhugo             #+#    #+#             */
/*   Updated: 2019/12/23 11:29:46 by bhugo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_print.h"

void	print_str_float(char *s, t_printf *p)
{
	int		sign;
	int		i;

	i = 0;
	sign = check_sign(&s, p);
	if (p->flag_minus == 1)
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

void	check_point(char **s, t_printf *p)
{
	char	*tmp;

	if (p->flag_hash == 1 && p->precision == 0)
	{
		tmp = *s;
		*s = ft_strjoin(tmp, ".");
		free(tmp);
	}
}

void	print_float2(char *s, t_printf *p)
{
	int		sign;
	int		i;

	i = 0;
	sign = check_sign(&s, p);
	check_point(&s, p);
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

void	print_float(char *s, t_printf *p)
{
	if ((ft_isdigit(*s) == 0 && *s != '-') ||
			(ft_isdigit(*(s + 1)) == 0 && *s == '-'))
	{
		p->flag_zero = 0;
		s[0] == 'n' ? p->flag_plus = 0 : 0;
		s[0] == 'n' ? p->flag_space = 0 : 0;
		print_str_float(s, p);
	}
	else
		print_float2(s, p);
}

int		format_float(t_printf *p)
{
	long double	n;
	double		f;
	char		*float2str;
	char		*long2str;

	p->precision < 0 || p->precision > LON_LEN ? p->precision = DEF_PRE : 0;
	if (p->length_capital_l == 1)
	{
		n = va_arg(p->arg_ptr, long double);
		if (!(long2str = (char*)malloc(sizeof(char) * (LON_LEN))))
			exit(-1);
		long_double_trouble(&n, p->precision, long2str);
		print_float(long2str, p);
	}
	else
	{
		f = va_arg(p->arg_ptr, double);
		if (!(float2str = (char*)malloc(sizeof(char) * (DUB_LEN))))
			exit(-1);
		double_trouble(&f, p->precision, float2str);
		print_float(float2str, p);
	}
	return (1);
}
