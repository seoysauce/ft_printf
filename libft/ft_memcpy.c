/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojeong <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/30 17:45:17 by seojeong          #+#    #+#             */
/*   Updated: 2020/12/30 17:45:20 by seojeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t		index;
	char		*dest;
	const char	*source;

	dest = (char *)dst;
	source = (const char *)src;
	if (dest == NULL && source == NULL)
		return (NULL);
	index = 0;
	while (index < n)
	{
		dest[index] = source[index];
		index++;
	}
	return (dst);
}
