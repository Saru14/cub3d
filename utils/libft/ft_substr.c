/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thvanher <thvanher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/11 10:50:01 by thvanher          #+#    #+#             */
/*   Updated: 2020/08/24 17:54:06 by thvanher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *src, unsigned int start, size_t len)
{
	char	*new;
	int		srclen;
	int		i;

	if (!src)
		return (0);
	srclen = ft_strlen((char *)src);
	if (srclen - start < len)
		len = (size_t)(srclen - start);
	if (!(new = (char *)malloc((len + 1) * sizeof(char))))
		return (0);
	i = 0;
	if (srclen < (int)start)
	{
		new[i] = '\0';
		return (new);
	}
	else
		ft_memcpy(new, src + start, len);
	new[len] = '\0';
	return (new);
}
