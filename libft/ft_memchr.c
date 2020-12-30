/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojeong <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/30 16:38:08 by seojeong          #+#    #+#             */
/*   Updated: 2020/12/30 16:38:09 by seojeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *ptr, int value, size_t n)
{
	const char	*str;
	char		ch;

	str = (const char *)ptr;
	ch = value;
	while (n--)
	{
		if (*str == ch)
			return ((void*)str);
		str++;
	}
	return (NULL);
}
