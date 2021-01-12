/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbodson <jbodson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 12:19:08 by jbodson           #+#    #+#             */
/*   Updated: 2021/01/12 17:02:14 by jbodson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../srcs/cub3d.h"

int			ft_inset(int c, char *set)
{
    while (set && *set)
    {
        if (c == *set)
            return (1);
        set++;
    }
    return (0);
}

int			ft_isspace(int c)
{
	if (c == ' ' || c == 't' || c == '\n' || c == 'v' || c == 'f' || c == 'r')
	return (1);
	return (0);
}

int			ft_next_arg(char *l)
{
	int	i;

	i = 0;
	while (l && ft_isspace(l[i]))
		i++;
	while (l && (ft_isdigit(l[i]) || ft_inset(l[i], ".,-")))
		i++;
	return (i);
}