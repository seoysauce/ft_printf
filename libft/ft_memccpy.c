/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojeong <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/30 16:36:50 by seojeong          #+#    #+#             */
/*   Updated: 2020/12/30 16:36:51 by seojeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	char		*dest;
	const char	*source;
	char		ch;

	dest = dst;
	source = src;
	ch = c;
	while (n--)
	{
		*dest++ = *source;
		if (*source == ch)
			return ((void*)dest);
		source++;
	}
	return (NULL);
}
