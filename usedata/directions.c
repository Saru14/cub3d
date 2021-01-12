/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   directions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbodson <jbodson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 12:45:33 by jbodson           #+#    #+#             */
/*   Updated: 2021/01/12 15:35:15 by jbodson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../srcs/cub3d.h"

int		ft_north(t_data *data, char *line)
{
	int		i;
	int		j;

	i = 1;
	j = 0;
	data->path_north = ft_calloc(sizeof(char), (ft_strlen(line) + 1));
	while (line[i] >= 33 && line[i] <= 126)
		data->path_north[j++] = line[i++];
	data->path_north[j] = '\0';
	/*
	** il faut open(../../sprites/eagle.png, O_RDONLY)
	*/
	if (data->path_north == NULL)
		return (0);
	else
		return (1);
}

int		ft_south(t_data *data, char *line)
{
	int		i;
	int		j;

	i = 1;
	j = 0;
	data->path_south = ft_calloc(sizeof(char), (ft_strlen(line) + 1));
	while (line[i] >= 33 && line[i] <= 126)
		data->path_south[j++] = line[i++];
	data->path_south[j] = '\0';
	/*
	** il faut open(../../sprites/eagle.png, O_RDONLY)
	*/
	if (data->path_south == NULL)
		return (0);
	else
		return (1);
}

int		ft_west(t_data *data, char *line)
{
	int		i;
	int		j;

	i = 1;
	j = 0;
	data->path_west = ft_calloc(sizeof(char), (ft_strlen(line) + 1));
	while (line[i] >= 33 && line[i] <= 126)
		data->path_west[j++] = line[i++];
	data->path_west[j] = '\0';
	/*
	** il faut open(../../sprites/eagle.png, O_RDONLY)
	*/
	if (data->path_west == NULL)
		return (0);
	else
		return (1);
}

int		ft_east(t_data *data, char *line)
{
	int		i;
	int		j;

	i = 1;
	j = 0;
	data->path_east = ft_calloc(sizeof(char), (ft_strlen(line) + 1));
	while (line[i] >= 33 && line[i] <= 126)
		data->path_east[j++] = line[i++];
	data->path_east[j] = '\0';
	/*
	** il faut open(../../sprites/eagle.png, O_RDONLY)
	*/
	if (data->path_east == NULL)
		return (0);
	else
		return (1);
}