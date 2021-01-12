/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   res_sprite_rgb.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbodson <jbodson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 15:34:23 by jbodson           #+#    #+#             */
/*   Updated: 2021/01/12 15:46:25 by jbodson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../srcs/cub3d.h"

int		ft_resolution(t_data *data, char *line)
{
	int		x;
	int		y;

	mlx_get_screen_size(data->mlx_ptr, &x, &y);
	data->largeur = ft_atoi(line);
	if (data->largeur > x)
		data->largeur = x;
	line += ft_next_arg(line);
	data->hauteur = ft_atoi(line);
	if (data->hauteur > y)
		data->hauteur = y;
		if (!data->hauteur || !data->largeur)
		return (0);
	return (1);
}

int		ft_sprite(t_data *data, char *line)
{
	int		i;
	int		j;

	i = 1;
	j = 0;
	data->path_sprite = ft_calloc(sizeof(char), (ft_strlen(line) + 1));
	while (line[i] >= 33 && line[i] <= 126)
		data->path_sprite[j++] = line[i++];
	data->path_sprite[j] = '\0';
	/*
	** il faut open(../../sprites/pillar.png, O_RDONLY)
	*/
	if (data->path_sprite == NULL)
		return (0);
	else
		return (1);
}

int		ft_ciel(t_data *data, char *line)
{
	int i;

	i = 0;
	data->c1 = ft_atoi(line);
	while (*line == ft_isspace(*line) || *line == ',')
		line++;
	data->c2 = ft_atoi(line);
	while (*line == ft_isspace(*line) || *line == ',')
		line++;
	data->c3 = ft_atoi(line);
	if (!data->c1 || !data->c2 || !data->c3)
		return (0);
	return (1);
}

int		ft_flour(t_data *data, char *line)
{
	int i;

	i = 0;
	data->f1 = ft_atoi(line);
	while (*line == ft_isspace(*line) || *line == ',')
		line++;
	data->f2 = ft_atoi(line);
	while (*line == ft_isspace(*line) || *line == ',')
		line++;
	data->f3 = ft_atoi(line);
	if (!data->f1 || !data->f2 || !data->f3)
		return (0);
	return (1);
}