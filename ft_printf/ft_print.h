/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhugo <bhugo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 19:11:35 by bhugo             #+#    #+#             */
/*   Updated: 2020/02/18 17:13:14 by bhugo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINT_H
# define FT_PRINT_H
# include <stdarg.h>
# include "../libft/libft.h"
# include <limits.h>
# define BUFF 1024
# define DEF_PRE 6
# define DUB_LEN 1076
# define LON_LEN 16447

typedef struct		s_printf
{
	va_list			arg_ptr;
	char			*format;
	int				count;
	char			flag_minus;
	char			flag_plus;
	char			flag_zero;
	char			flag_hash;
	char			flag_space;
	int				width;
	int				precision;
	char			length_l;
	char			length_ll;
	char			length_capital_l;
	char			length_h;
	char			length_hh;
	char			specifier;
}					t_printf;

typedef union		u_val
{
	double			n;
	struct
	{
		uint32_t	lo;
		uint32_t	hi;
	}				u32;
}					t_val;

typedef struct		s_bg
{
	uint32_t		n[128];
	int32_t			lo;
	int32_t			hi;
	int				sign:1;
}					t_bg;

typedef union		u_val64
{
	long double		n;
	struct
	{
		uint64_t	lo;
		uint64_t	hi;
	}				u64;
}					t_val64;

typedef struct		s_bgl
{
	uint32_t		n[2048];
	int32_t			lo;
	int32_t			hi;
	unsigned int	sign : 1;
}					t_bgl;

extern unsigned int	g_ten_pow[];

void				div_dub_hi(t_bg *nd, uint32_t *carry, uint32_t *i);
void				div_long_hi(t_bgl *nd, uint32_t *carry, uint32_t *i);
void				div_dub_last
(t_bg *nd, uint32_t *carry, uint32_t *i, uint32_t pos);
void				div_long_last
(t_bgl *nd, uint32_t *carry, uint32_t *i, uint32_t pos);
void				div_nd_dub(t_bg *nd, uint32_t pos);
void				div_nd_long(t_bgl *nd, uint32_t pos);
void				mult_dub_main(t_bg *nd, uint32_t *carry, uint32_t *i);
void				mult_long_main(t_bgl *nd, uint32_t *carry, uint32_t *i);
void				mult_dub_last
(t_bg *nd, uint32_t *carry, uint32_t *i, uint32_t pos);
void				mult_long_last
(t_bgl *nd, uint32_t *carry, uint32_t *i, uint32_t pos);
void				mult_nd_dub(t_bg *nd, uint32_t pos, uint32_t carry);
void				round_up(uint32_t *nd, int nd_lo, int i);
void				round_lo(int pre, int prepos, int *ndlo);
int					round_tail(int nd_lo, int pre, uint32_t *nd, int mask);
void				do_long_round(t_bgl *nd, int *pre);
void				do_round_dub(t_bg *nd, int *pre);
void				dubtoi(int up, char **pos, uint32_t u, int pre);
void				write_bef_dot_dub(t_bg *nd, char **pos);
void				write_bef_long_dot(t_bgl *nd, char **pos);
void				write_af_lo_dot(t_bgl *nd, char **pos, int pre, int zero);
void				write_af_dub_dot(t_bg *nd, char **pos, int pre, int zero);
char				*long_2_str(t_bgl *nd, int pre, char *str, int zero);
int					expa_choice(unsigned int val);
void				mult_nd_long(t_bgl *nd, uint32_t pos, uint32_t carry);
char				*bad_num_long(t_val64 *tmp, char *dubstr, int sign);
void				get_long_fracture(t_val64 *tmp, t_bgl *nd, int32_t *expa);
char				*long_double_trouble(long double *n, int pre, char *dubstr);
char				*dub_2_str(t_bg *nd, int pre, char *str, int zero);
char				*bad_num_dubl(t_val *tmp, char *dubstr, int sign);
void				get_dub_fracture(t_val *tmp, t_bg *nd, int32_t *expa);
void				implicit_bit(int32_t *expa, t_bg *nd);
char				*double_trouble(double *n, int pre, char *dubstr);
int					ft_printf(const char *format, ...);
char				*ft_itoa_base(unsigned int n, int base);
char				*ft_itoa_base_capital(unsigned int n, int base);
int					ft_atoi_parser(char **str);
char				*ft_strndup(int n, char *s1);
char				*ft_long_itoa(long n);
int					format_percent(t_printf *p);
int					format_upper_hex(t_printf *p);
int					format_hex(t_printf *p);
int					format_unsigned_int(t_printf *p);
int					format_oct(t_printf *p);
int					format_int(t_printf *p);
int					format_pointer(t_printf *p);
int					format_char(t_printf *p);
int					format_str(t_printf *p);
int					check_sign(char **s, t_printf *p);
void				reload_output_with_precision(char **s, t_printf *p);
void				printf_width(char *s, t_printf *p, int sign);
void				ft_put_space(char *s, t_printf *p, int sign);
void				ft_put_space_zero(char *s, t_printf *p, int sign);
char				*ft_itoa_base_long(unsigned long long int n, int base);
void				print_oct(char *s, t_printf *p);
char				*ft_itoa_base_capital_long
(unsigned long long int n, int base);
int					format_float(t_printf *p);
void				print_int(char *s, t_printf *p);
int					write_buffer(char *s, int end, t_printf *p);
void				ft_putchar_buffer(char c, t_printf *p);
void				ft_putstr_buffer(char const *s, t_printf *p);
void				print_int(char *s, t_printf *p);
void				print_oct(char *s, t_printf *p);
int					free_memory(char **s);
void				print_str(char *s, t_printf *p);
char				*long_double_trouble(long double *n, int pre, char *dubstr);
char				*double_trouble(double *n, int pre, char *dubstr);
void				printf_sign(t_printf *p, int sign);
void				printf_order(char *s, t_printf *p, int i, int sign);

#endif
