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

char	*ft_strnstr(const char *hs, const char *ne, size_t n)
{
	unsigned int	i;
	int				length;

	if (*ne == 0)
		return ((char *)hs);
	length = ft_strlen((char *)ne);
	i = 0;
	while (hs[i] && i + length <= n)
	{
		if (!ft_strncmp(hs + i, ne, length))
			return ((char *)(hs + i));
		i++;
	}
	return (0);
}
