/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojeong <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/30 16:35:03 by seojeong          #+#    #+#             */
/*   Updated: 2020/12/30 16:35:05 by seojeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	valid_charset(char ch, char charset)
{
	if (ch == charset)
		return (1);
	return (0);
}

static int	ft_len(char const *s, char c)
{
	int cnt;

	cnt = 0;
	while (*s && valid_charset(*s, c) == 0)
	{
		cnt++;
		s++;
	}
	return (cnt);
}

static int	ft_size(char const *s, char c)
{
	int flag;
	int size;
	int i;

	flag = 1;
	size = 0;
	i = 0;
	while (s[i])
	{
		if (flag == 1 && valid_charset(s[i], c) == 0)
		{
			size++;
			flag = 0;
		}
		if (valid_charset(s[i], c) == 1)
			flag = 1;
		i++;
	}
	return (size);
}

char		**ft_split(char const *s, char c)
{
	int		size;
	char	**res;
	int		ch_len;
	int		i;
	int		j;

	size = ft_size(s, c);
	if (!(res = (char **)malloc(sizeof(char *) * (size + 1))))
		return (NULL);
	res[size] = NULL;
	i = 0;
	while (i < size)
	{
		if ((ch_len = ft_len(s, c)) != 0)
		{
			res[i] = (char *)malloc(sizeof(char) * (ch_len + 1));
			j = 0;
			while (*s && valid_charset(*s, c) == 0)
				res[i][j++] = *s++;
			res[i++][j] = '\0';
		}
		else
			s++;
	}
	return (res);
}
