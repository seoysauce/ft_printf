/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_info.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojeong <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 16:57:16 by seojeong          #+#    #+#             */
/*   Updated: 2020/12/30 16:45:39 by seojeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

const char *read_flag(const char *form, t_info *info)
{
	while (*form == '-' || *form == '0')
	{
		if (*form == '-') //왼쪽정렬
			info->flag = 1;
		else if (*form == '0')	 //'0'과'-'플래그가 동시에 존재한다면 '-'플래그사용
			if (info->flag != 1) //ex) prinft("[%0-5d]",123); [123  ]
				info->flag = 2;
		form++; //flag 부분을 다음으로 옮김.
	}
	return (form);
}

const char *read_width(const char *form, t_info *info, va_list ap)
{
	if (*form == '*' && form++)		   //form++ 아래로 내리고 테스트해보기.
		info->width = va_arg(ap, int); //char short경우 int사용.
	else
		while (ft_isnum(*form) == 1)
			info->width = info->width * 10 + (*form++ - '0'); //읽고 넘김.
	if (info->width < 0) //만약 *값으로 음수를 받았다면 폭을 양의 값으로 고치고 '-'플래그를 뜻하는 1를 넣어준다.
	{					 //ex) printf("[%0-5d\n",123);
		info->width *= -1;
		info->flag = 1; //flag - 로 바꿔줌.
	}
	return (form);
}

const char *read_prec(const char *form, t_info *info, va_list ap)
{
	form++;
	while (*form == '0')
		form++; //printf("[%.3s]")  == prinft("[%.0003s]")
	if (*form == '*' && form++) //정밀도 위치에 wildcard가 온 경우
		info->prec = va_arg(ap, int);
	if (ft_isnum(*form) == 1) //아닌 경우
		while (ft_isnum(*form) == 1)
			info->prec = info->prec * 10 + (*form++ - '0');
	if (info->prec == 0 && info->flag == 2 && *form != '%')
		//정밀도 값이 0이고 '0'플래그와 서식지정자 %외 다른 지정자가 사용되었다면 '0'플래그는 무시.
		//printf("[%0*.*u]\n", 8, 0, 8); [       8]
		//printf("[%0*.*%]\n", 8, 0);    [0000000%]
		info->flag = 0;
	if (info->prec == 0)
		//point_zero=1인 경우는 '.'이 있을 경우이고    .   .0   두가지임.
		//정밀도가 0이면 point_zero = 1
		//point_zero를 사용하는이유
		//printf("[%*s]\n", 3, "hello");   [hello]
		//printf("[%*.s]\n", 3, "hello");  [   ] 폭 3
		info->point_zero = 1;
	return (form);
}

const char *print_form_spec(const char *form, t_info *info, va_list ap)
{
	if (*form == 'c' || *form == '%')
		print_c(info, ap, form);
	// printf("%%");
	else if (*form == 's')
		print_s(info, ap);
	else if (*form == 'p')
		print_p(info, ap);
	else if (*form == 'd' || *form == 'i' || *form == 'u' || *form == 'x' || *form == 'X')
		print_diux(info, ap, form);
	else
		return (NULL);
	return (form);
}
