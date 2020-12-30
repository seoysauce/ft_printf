/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojeong <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/30 16:40:40 by seojeong          #+#    #+#             */
/*   Updated: 2020/12/30 16:40:41 by seojeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int ch)
{
	const char *start;

	start = str;
	while (*str)
		str++;
	while (str != start && *str != (char)ch)
		str--;
	if (*str == (char)ch)
		return ((char *)str);
	return (NULL);
}
