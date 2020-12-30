/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojeong <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/30 16:28:36 by seojeong          #+#    #+#             */
/*   Updated: 2020/12/30 16:28:41 by seojeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_isnum(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

void arr_init(int *size, int i)
{
	int j;

	j = 0;
	while (j < i)
	{
		size[j] = 0;
		j++;
	}
}

int hex_leng_2(unsigned long long n, int point_zero)
{
	int i;


	i = 0;
	if (n == 0) //값이 0이고
	{
		if (point_zero) //'.'존재하고 prec=0인경우 -> point_zero = 1
			return (0); //ft_printf("[%10.p]\n",0); //[        0x]  공백 1자리를 더 늘려줘야해서 return 0
		else //정밀도가 존재하지않는 경우, 존재할경우 값이 0이아닌 경우
			return (1); //ft_printf("[%10p]\n",0);  //[       0x0] 공백 1자리를 빼줘야해서 return 1
	}
	while (n != 0 && ++i) //p자릿수 계산.
		n /= 16;
	return (i);
}

void ft_putthex2(unsigned long long n)
{
	if (n >= 16)
	{
		ft_putthex2(n / 16);
		write(1, &"0123456789abcdef"[n % 16], 1);
	}
	else
		write(1, &"0123456789abcdef"[n % 16], 1);
}

int leng(long long n, const char *form)
{
	int i;

	if (n == 0)
		return (1);
	i = 0;
	if (*form == 'd' || *form == 'i' || *form == 'u')
		while (n != 0 && ++i)
			n /= 10;
	else if (*form == 'x' || *form == 'X')
		while (n != 0 && ++i)
			n /= 16;
	return (i);
}

