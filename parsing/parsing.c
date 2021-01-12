/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbodson <jbodson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 16:44:45 by jbodson           #+#    #+#             */
/*   Updated: 2021/01/12 15:40:33 by jbodson          ###   ########.fr       */
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
    return (1);
}

int		get_data(t_data *data, char *file)
{
	int		fd;
	int		res;
	char	*line;

	res = 0;
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
	if (fd > 0 && res)
		return (1);
	else
		return (0);
}