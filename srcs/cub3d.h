/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbodson <jbodson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 16:38:14 by jbodson           #+#    #+#             */
/*   Updated: 2021/01/11 16:57:04 by jbodson          ###   ########.fr       */
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
}				t_data;

#endif
