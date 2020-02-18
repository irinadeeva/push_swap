/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_alignment.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhugo <bhugo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 20:21:17 by bhugo             #+#    #+#             */
/*   Updated: 2019/12/11 20:46:35 by bhugo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_print.h"

/*
** выравнивание строки взависимости от флагов
*/

/*
** проверка знака: избавляемся от него (нужно для отработки флага '0')
*/

int		check_sign(char **s, t_printf *p)
{
	char	*tmp;

	if (*s[0] == '-')
	{
		(!(tmp = ft_strdup(*s + 1))) ? free_memory(&(*s)) : 0;
		free(*s);
		*s = tmp;
		p->flag_plus = 0;
		p->flag_space = 0;
		return (-1);
	}
	else if (p->flag_plus == 1)
	{
		p->flag_space = 0;
		return (1);
	}
	return (0);
}

void	ft_put_space(char *s, t_printf *p, int sign)
{
	int		count;

	count = 0;
	if (p->flag_hash == 1)
	{
		p->specifier == 'o' ? p->width-- : 0;
		p->specifier == 'x' || p->specifier == 'X' ?
				p->width -= 2 : 0;
	}
	(p->flag_plus == 1 || sign != 0 || p->flag_space == 1) ? p->width-- : 0;
	if (p->width > (int)ft_strlen(s))
	{
		count = p->width - (int)ft_strlen(s);
		while (--count >= 0)
			write_buffer(" ", 0, p);
	}
}

void	ft_put_space_zero(char *s, t_printf *p, int sign)
{
	int		count;
	int		len;

	count = 0;
	len = ((int)ft_strlen(s) > p->precision ? (int)ft_strlen(s) : p->precision);
	if (p->flag_hash == 1)
	{
		p->specifier == 'o' ? p->width-- : 0;
		p->specifier == 'x' || p->specifier == 'X' ? p->width -= 2 : 0;
	}
	(p->flag_plus == 1 || sign != 0 || p->flag_space == 1) ? p->width-- : 0;
	if (p->width > (int)ft_strlen(s))
	{
		count = p->width - (int)ft_strlen(s);
		while (--count >= 0)
			write_buffer("0", 0, p);
	}
}

void	printf_width(char *s, t_printf *p, int sign)
{
	if (p->width >= 0 && p->flag_zero == 0)
		ft_put_space(s, p, sign);
	if (p->width >= 0 && p->flag_zero == 1)
		ft_put_space_zero(s, p, sign);
}

void	reload_output_with_precision(char **s, t_printf *p)
{
	char	*tmp;
	char	*res;
	int		len;
	int		i;

	len = ft_strlen(*s);
	p->specifier == 'o' && p->flag_hash == 1 && p->precision > 0 ?
		p->precision-- : 0;
	if (p->precision == 0 && *s[0] == '0')
		*s[0] = '\0';
	if (p->precision > len)
	{
		i = p->precision - len;
		(!(tmp = ft_strnew(i))) ? free_memory(&(*s)) : 0;
		while (i-- > 0)
			tmp[i] = '0';
		(!(res = ft_strjoin(tmp, *s))) ? free_memory(&(*s)) : 0;
		free(tmp);
		free(*s);
		*s = res;
	}
}
