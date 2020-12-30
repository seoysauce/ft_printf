/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojeong <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/30 16:34:54 by seojeong          #+#    #+#             */
/*   Updated: 2020/12/30 16:34:55 by seojeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t num)
{
	char		*dest;
	const char	*source;
	size_t		index;

	index = 0;
	dest = dst;
	source = src;
	if (dest == 0 && source == 0)
		return (NULL);
	if (dest <= source)
	{
		while (index++ < num)
			*dest++ = *source++;
	}
	else
	{
		dest += num - 1;
		source += num - 1;
		while (index++ < num)
			*dest-- = *source--;
	}
	return (dst);
}
