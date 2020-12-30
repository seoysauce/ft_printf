/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojeong <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/30 16:34:10 by seojeong          #+#    #+#             */
/*   Updated: 2020/12/30 16:34:13 by seojeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		check_charset(char ch, const char *set)
{
	int index;

	index = 0;
	while (set[index])
	{
		if (set[index] == ch)
			return (1);
		index++;
	}
	return (0);
}

static size_t	start_point(const char *str, char const *set)
{
	size_t str_len;
	size_t start;

	start = 0;
	str_len = ft_strlen(str);
	while (start < str_len)
	{
		if (check_charset(str[start], set) == 0)
			return (start);
		start++;
	}
	return (start);
}

static size_t	end_point(const char *str, char const *set)
{
	size_t str_len;
	size_t end;

	str_len = ft_strlen(str);
	end = str_len - 1;
	while (end > 0)
	{
		if (check_charset(str[end], set) == 0)
			return (end);
		end--;
	}
	return (end);
}

char			*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	size_t	length;
	char	*res;

	if (s1 == NULL || set == NULL)
		return (NULL);
	start = start_point(s1, set);
	end = end_point(s1, set);
	if (start > end)
	{
		res = (char *)malloc(1);
		if (res == NULL)
			return (NULL);
		res[0] = '\0';
		return (res);
	}
	length = end - start + 1;
	res = (char *)malloc((length + 1) * sizeof(char));
	if (res == NULL)
		return (NULL);
	ft_memcpy(res, s1 + start, length);
	res[length] = '\0';
	return (res);
}
