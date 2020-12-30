/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojeong <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 17:20:37 by seojeong          #+#    #+#             */
/*   Updated: 2020/12/30 16:43:53 by seojeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		init_info(t_info *info)
{
	info->flag = 0;
	info->width = 0;
	info->prec = 0;
	info->point_zero = 0;//정밀도가 안쓰인경우와 정밀도가 쓰였지만 정밀도가 0인경우.
	info->ret = 0; //출력한 개수 리턴값 반환.
}

const char	*read_info(va_list ap, const char *form, int *ret)
{
	t_info *info;//구조체를 가리키는 포인터.s

	if (!(info = (t_info *)malloc(sizeof(t_info))))
		return (NULL); //할당되지않는다면 NULL반환
	init_info(info);//구조체 초기화.
	form = read_flag(form, info);//flag부분의 form이 넘어가짐.
	form = read_width(form, info, ap);
	if (*form == '.')
		form = read_prec(form, info, ap);
	form = print_form_spec(form, info, ap);//서식지정자에 맞게 출력.
	*ret += info->ret; //공백, 0 등 총 출력할 값 더해줌.
	free(info);
	info = NULL;
	return (form);
}

int parse(va_list ap, const char *form)
{
	int ret;

	ret = 0;
	while (*form)
	{
		if (*form == '%')//서식지정자
		{
			form++;//%다음으로 넘겨줌.
			if (!(form = read_info(ap, form, &ret)))
				//read_info반환값이 NULL이라면 return (0)실행
				return (0);
		}
		else if (*form != '%')//서식지정자 x
		{
			ret++;
			write(1, form, 1);
		}
		form++;
	}
	return (ret);
}

int ft_printf(const char *form, ...)
{
	va_list ap;
	int ret;

	va_start(ap, form);//ap가 form다음의 인자(가변인자)를 가리키게함.
	ret = parse(ap, form);
	va_end(ap);
	return (ret);
}

