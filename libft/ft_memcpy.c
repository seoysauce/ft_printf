/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunkim <hyunkim@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/24 04:10:28 by hyunkim           #+#    #+#             */
/*   Updated: 2020/08/05 01:05:22 by hyunkim          ###   ########.fr       */
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
