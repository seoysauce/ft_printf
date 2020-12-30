/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojeong <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/30 16:35:57 by seojeong          #+#    #+#             */
/*   Updated: 2020/12/30 16:36:00 by seojeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *ptr, int input_char, size_t num)
{
	size_t	index;
	char	*str;
	char	ch;

	str = ptr;
	ch = input_char;
	index = 0;
	while (index < num)
	{
		str[index] = ch;
		index++;
	}
	return (ptr);
}
