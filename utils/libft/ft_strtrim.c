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

static int	start_new_str(char const *s1, char const *set, int *i)
{
	int j;
	int start;

	j = ft_strlen((char *)s1);
	while (ft_strchr(set, s1[*i]))
		(*i)++;
	start = *i;
	if (*i < j - 1)
	{
		while (ft_strchr(set, s1[j - 1]))
		{
			(*i)++;
			j--;
		}
	}
	return (start);
}

char		*ft_strtrim(char const *s1, char const *set)
{
	char	*new;
	int		i;
	int		j;
	int		start;

	if (!s1 || !set)
		return (0);
	i = 0;
	start = start_new_str(s1, set, &i);
	j = 0;
	if (!(new = malloc((ft_strlen((char *)s1) - i + 1) * sizeof(char))))
		return (0);
	while (ft_strlen((char *)s1) - i++ > 0)
		new[j++] = s1[start++];
	new[j] = '\0';
	return (new);
}
