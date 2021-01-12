/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbodson <jbodson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 16:38:14 by jbodson           #+#    #+#             */
/*   Updated: 2021/01/12 17:02:21 by jbodson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <math.h>
# include <fcntl.h>
# include "../minilbx/mlx.h"
# include "../utils/libft/libft.h"
# include "../utils/gnl/get_next_line.h"

typedef struct	s_data
{
	int		largeur;
	int		hauteur;
	char	*path_north;
	char	*path_west;
	char	*path_south;
	char	*path_east;
	char	*path_sprite;
	int		c1;
	int		c2;
	int		c3;
	int		f1;
	int		f2;
	int		f3;
	void	*mlx_ptr;
	void	*mlx_win;
}				t_data;

void	ft_putstr_fd(char *s, int fd);
int		get_data(t_data *data, char *file);
int		ft_isspace(int c);
int		ft_next_arg(char *l);
int		ft_east(t_data *data, char *line);
int		ft_south(t_data *data, char *line);
int		ft_west(t_data *data, char *line);
int		ft_north(t_data *data, char *line);
int		ft_flour(t_data *data, char *line);
int		ft_ciel(t_data *data, char *line);
int		ft_sprite(t_data *data, char *line);
int		ft_resolution(t_data *data, char *line);
int			ft_inset(int c, char *set);

#endif
