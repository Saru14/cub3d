/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thvanher <thvanher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/11 10:50:01 by thvanher          #+#    #+#             */
/*   Updated: 2020/08/11 10:50:22 by thvanher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	const unsigned char	*csrc;
	unsigned char		*cdst;
	size_t				i;

	csrc = (const unsigned char *)src;
	cdst = (unsigned char *)dst;
	if (!dst && !src)
		return (0);
	i = 0;
	if (csrc < cdst)
	{
		while (i < n)
		{
			cdst[n - i - 1] = csrc[n - i - 1];
			i++;
		}
	}
	else
	{
		i = -1;
		while (++i < n)
			cdst[i] = csrc[i];
	}
	return (dst);
}
