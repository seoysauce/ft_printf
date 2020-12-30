/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojeong <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/30 16:39:08 by seojeong          #+#    #+#             */
/*   Updated: 2020/12/30 16:39:09 by seojeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*check_str(const char *s1, const char *s2, size_t len, size_t index)
{
	size_t		temp_index;
	const char	*p1;
	const char	*p2;

	while (index < len)
	{
		if (*s1 == *s2)
		{
			temp_index = index;
			p1 = s1;
			p2 = s2;
			while (*p1 && *p1 == *p2 && temp_index < len)
			{
				p1++;
				p2++;
				temp_index++;
			}
			if (*p2 == '\0')
				return ((char *)s1);
		}
		s1++;
		index++;
	}
	return (NULL);
}

char	*ft_strnstr(const char *s1, const char *s2, size_t len)
{
	if (*s2 == '\0')
		return ((char *)s1);
	if (len == 0)
		return (NULL);
	return (check_str(s1, s2, len, 0));
}
