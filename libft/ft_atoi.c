/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojeong <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/30 16:33:07 by seojeong          #+#    #+#             */
/*   Updated: 2020/12/30 16:33:09 by seojeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	is_space(int ch)
{
	if (ch >= 9 && ch <= 13)
		return (1);
	if (ch == 32)
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	int index;
	int minus;
	int res;

	index = 0;
	minus = 1;
	res = 0;
	while (is_space(str[index]) == 1)
		index++;
	if (str[index] == '+' || str[index] == '-')
	{
		if (str[index] == '-')
			minus *= -1;
		index++;
	}
	while (str[index] >= '0' && str[index] <= '9')
	{
		res *= 10;
		res += str[index] - '0';
		index++;
	}
	return (res * minus);
}
