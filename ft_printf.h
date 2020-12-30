/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojeong <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/30 16:24:56 by seojeong          #+#    #+#             */
/*   Updated: 2020/12/30 18:30:05 by seojeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _FT_PRINTF_H
# define _FT_PRINTF_H

# include <stdio.h>
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include "./libft/libft.h"

typedef struct		s_info
{
	int		flag;
	int		width;
	int		prec;
	int		point_zero;
	int		ret;
}					t_info;

void				init_info(t_info *info);
const char			*read_info(va_list ap, const char *form, int *ret);
int					parse(va_list ap, const char *form);
int					ft_printf(const char *form, ...);

const char			*read_flag(const char *form, t_info *info);
const char			*read_width(const char *form, t_info *info, va_list ap);
const char			*read_prec(const char *form, t_info *info, va_list ap);
const char			*print_form_spec(const char *form, t_info *info,
va_list ap);
void				print_c(t_info *info, va_list ap, const char *form);
void				print_p(t_info *info, va_list ap);
void				print_s_1(t_info *info, int *size, char *data);
void				print_s(t_info *info, va_list ap);
void				print_diux_1(t_info *info, int *size,\
									long long data, const char *form);
void				print_diux_2(t_info *info, int *size,\
									long long data, const char *form);
void				print_diux(t_info *info, va_list ap, const char *form);
int					ft_isnum(char c);
void				arr_init(int *size, int i);
int					hex_leng_2(unsigned long long n, int point_zero);
void				ft_putthex2(unsigned long long n);
int					leng(long long n, const char *form);

void				ft_put_data(long long data, const char *form);
void				ft_putdata(long long data);
void				ft_puthex(unsigned long long data);
void				ft_puthex2(unsigned long long data);

#endif
