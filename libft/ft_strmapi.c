/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojeong <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/30 16:36:19 by seojeong          #+#    #+#             */
/*   Updated: 2020/12/30 16:36:23 by seojeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	index;
	size_t	length;
	char	*res;

	if (s == NULL)
		return (NULL);
	index = 0;
	length = ft_strlen(s);
	if (!(res = (char*)malloc((length + 1) * sizeof(char))))
		return (NULL);
	while (index < length)
	{
		res[index] = (*f)(index, s[index]);
		index++;
	}
	res[index] = '\0';
	return (res);
}
