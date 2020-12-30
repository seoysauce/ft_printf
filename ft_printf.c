/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojeong <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 17:20:37 by seojeong          #+#    #+#             */
/*   Updated: 2020/12/30 18:32:26 by seojeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		init_info(t_info *info)
{
	info->flag = 0;
	info->width = 0;
	info->prec = 0;
	info->point_zero = 0;
	info->ret = 0;
}

const char	*read_info(va_list ap, const char *form, int *ret)
{
	t_info *info;

	if (!(info = (t_info *)malloc(sizeof(t_info))))
		return (NULL);
	init_info(info);
	form = read_flag(form, info);
	form = read_width(form, info, ap);
	if (*form == '.')
		form = read_prec(form, info, ap);
	form = print_form_spec(form, info, ap);
	*ret += info->ret;
	free(info);
	info = NULL;
	return (form);
}

int			parse(va_list ap, const char *form)
{
	int ret;

	ret = 0;
	while (*form)
	{
		if (*form == '%')
		{
			form++;
			if (!(form = read_info(ap, form, &ret)))
				return (0);
		}
		else if (*form != '%')
		{
			ret++;
			write(1, form, 1);
		}
		form++;
	}
	return (ret);
}

int			ft_printf(const char *form, ...)
{
	va_list	ap;
	int		ret;

	va_start(ap, form);
	ret = parse(ap, form);
	va_end(ap);
	return (ret);
}
