/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbodson <jbodson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 16:44:45 by jbodson           #+#    #+#             */
/*   Updated: 2021/01/18 16:06:26 by jbodson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../srcs/cub3d.h"

int ft_parsing_data(char *line, t_data *data)
{
	if (!line)
		return (0);
	if (line[0] == 0)
		return (1);
	if (line[0] == 'R' && ft_isspace(line[1]))
		return (ft_resolution(data, &line[1]));
	if (line[0] == 'N' && line[1] == 'O' && ft_isspace(line[2]))
        return (ft_north(data, &line[2]));
    if (line[0] == 'S' && line[1] == 'O' && ft_isspace(line[2]))
        return (ft_south(data, &line[2]));
    if (line[0] == 'W' && line[1] == 'E' && ft_isspace(line[2]))
        return (ft_west(data, &line[2]));
    if (line[0] == 'E' && line[1] == 'A' && ft_isspace(line[2]))
        return (ft_east(data, &line[2]));
    if (line[0] == 'S' && ft_isspace(line[1]))
        return (ft_sprite(data, &line[1]));
    if (line[0] == 'C' && ft_isspace(line[1]))
		return (ft_ciel(data, &line[1]));
	if (line[0] == 'F' && ft_isspace(line[1]))
		return (ft_flour(data, &line[1]));
	if (data->parsed == 8)
	{
		return (ft_map(data, &line[0]));
	}
    return (1);
}

int	ft_map(t_data *data, char *line)
{
	int i;

	
	i = 0;
	//printf("\n");
	while (line[i] == ' ')
	{
		data->map[i][data->lignemap] = -1;
		//printf("%d", data->map[i][data->lignemap]);
		i++;
	}
	while(line[i] != ' ' && line[i] != '\0')
	{
		if (line[i] == '1')
			data->map[i][data->lignemap] = 1;
		else if (line[i] == '0')
			data->map[i][data->lignemap] = 7;
		else if (line[i] == '2')
			data->map[i][data->lignemap] = 2;
		else if (line[i] == 'N')
			data->map[i][data->lignemap] = 3;
		else if (line[i] == 'S')
			data->map[i][data->lignemap] = 4;
		else if (line[i] == 'E')
			data->map[i][data->lignemap] = 5;
		else if (line[i] == 'W')
			data->map[i][data->lignemap] = 6;
		else
			data->map[i][data->lignemap] = 8;
		//printf("%d", data->map[i][data->lignemap]);
		i++;
	}
	data->lignemap++;
	return i;
}

int		get_data(t_data *data, char *file)
{
	int		fd;
	int		res;
	char	*line;
	int i;
	int j;
	int u = 99;
	int l = 0;

	data->map = (int **)malloc(10000 * sizeof(int *));
	while (u > 1)
	{
		data->map[l] = (int *)malloc(10000 * sizeof(int));
		u--;
		l++;
	}
	res = 0;
	i = 0;
	j = 0;
	data->parsed = 0;
	data->lignemap= 0;
	line = NULL;
	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		ft_putstr_fd("Error\nReading File : Fail_1!", 1);
		return (0);
	}
	while (get_next_line(fd, &line))
	{
		res = 1;
		ft_parsing_data(line, data);
		free(line);
	}
	free(line);
	close(fd);
	printf("\n");
	ft_verifmap(data);
	if (fd > 0 && res)
		return (1);
	else
		return (0);
}