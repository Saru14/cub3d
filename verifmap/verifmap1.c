/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verifmap1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbodson <jbodson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 19:20:39 by jbodson           #+#    #+#             */
/*   Updated: 2021/01/19 18:00:21 by jbodson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../srcs/cub3d.h"

int		ft_verifmap(t_data *data)
{
	ft_verifcharacters(data);
	ft_veriffirstline(data);
	ft_veriflastline(data);
	ft_veriffirstcolumn(data);
	ft_veriflastcolumn(data);
	ft_verifholes(data);
	if (data->perso != 1)
		printf("map error 7\n");
	return 1;
}

int		ft_verifholes(t_data *data)
{
	int i;
	int j;

	i = 0;
	while (data->map[i + 1])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == 7)
				ft_verifspaces(data, i, j);
			j++;
		}
		i++;
	}
	return 1;
}

int		ft_verifspaces(t_data *data, int i, int j)
{
	if (i == 0 || j == 0)
	{
		printf("map error 6\n");
		return 1;
	}
	if (data->map[i][j - 1] == -1 || !data->map[i][j - 1])
		printf("map error 6\n");
	if (data->map[i][j + 1] == -1 || !data->map[i][j + 1])
		printf("map error 6\n");
	if (data->map[i + 1][j] == -1 || !data->map[i + 1][j])
		printf("map error 6\n");
	if (data->map[i - 1][j] == -1 || !data->map[i - 1][j])
		printf("map error 6\n");
	if (data->map[i + 1][j + 1] == -1 || !data->map[i + 1][j + 1])
		printf("map error 6\n");
	if (data->map[i - 1][j - 1] == -1 || !data->map[i - 1][j - 1])
		printf("map error 6\n");
	if (data->map[i + 1][j - 1] == -1 || !data->map[i + 1][j - 1])
		printf("map error 6\n");
	if (data->map[i - 1][j + 1] == -1 || !data->map[i - 1][j + 1])
		printf("map error 6\n");
	return 1;
}

int		ft_veriflastcolumn(t_data *data)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while(data->map[i][j])
	{
		while(data->map[i][j])
		{
			i++;
		}
		i--;
		if (data->map[i][j] != -1 && data->map[i][j] != 1)
			printf("map error 5\n");
		i = 0;
		j++;
	}
	return 1;
}

int		ft_veriffirstcolumn(t_data *data)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (data->map[0][i])
	{
		if(data->map[0][i] != -1 && data->map[0][i] != 1)
			printf("map no valid4\n");
		i++;
	}
	return 1;
}

int		ft_verifcharacters(t_data *data)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (data->map[i][j])
	{
		while(data->map[i][j])
		{
			if (data->map[i][j] > 7 || data->map[i][j] < -1)
			{
				printf("map not valid1\n");
			}
			j++;
		}
		i++;
		j = 0;
	}
	return 1;
}

int		ft_veriffirstline(t_data *data)
{
	int i;

	i = 0;
	while (data->map[i][0] == -1)
		i++;
	while (data->map[i][0])
	{
		if (data->map[i][0] != 1 && data->map[i][0] != -1)
			printf ("map not valid2\n");
		i++;
	}
	return 1;
}

int		ft_veriflastline(t_data *data)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (data->map[0][i])
		i++;
	i--;
	while (data->map[j][i] == -1)
		j++;
	while(data->map[j][i])
	{
		if (data->map[j][i] != 1 && data->map[j][i] != -1)
			printf("map not valid3\n");
			j++;
	}
	return 1;
}