/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojeong <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/30 16:35:47 by seojeong          #+#    #+#             */
/*   Updated: 2020/12/30 16:35:50 by seojeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	count_size(int n)
{
	int	res;

	if (n == 0)
		return (1);
	if (n < 0)
		res = 1;
	else
		res = 0;
	while (n != 0)
	{
		n /= 10;
		res += 1;
	}
	return (res);
}

char		*ft_itoa(int n)
{
	char			*res;
	int				size;
	long long int	k;

	size = count_size(n);
	res = (char*)malloc(sizeof(char) * (size + 1));
	if (res == NULL)
		return (NULL);
	res[size] = '\0';
	k = n;
	if (k == 0)
		res[0] = '0';
	while (k != 0)
	{
		if (k < 0)
		{
			res[0] = '-';
			k *= -1;
		}
		res[size - 1] = (k % 10) + '0';
		k /= 10;
		size--;
	}
	return (res);
}
