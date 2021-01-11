/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbodson <jbodson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 16:44:45 by jbodson           #+#    #+#             */
/*   Updated: 2021/01/11 17:26:03 by jbodson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../srcs/cub3d.h"

int ft_parsing_data(char *line, t_data *data)
{
	
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