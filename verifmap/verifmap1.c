/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verifmap1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbodson <jbodson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 19:20:39 by jbodson           #+#    #+#             */
/*   Updated: 2021/01/13 19:35:34 by jbodson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../srcs/cub3d.h"

int		ft_verifmap(t_data *data)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while(data->map[i][j])
	{
		while(data->map[i][j])
		{
			printf("%d", data->map[i][j]);
			j++;
		}
		i++;
		printf("\n");
	}
	return 1;
}