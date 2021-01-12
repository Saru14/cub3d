/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbodson <jbodson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 16:37:49 by jbodson           #+#    #+#             */
/*   Updated: 2021/01/12 16:42:02 by jbodson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int main(int argc, char **argv)
{
	t_data *data;
	data = (t_data*)malloc(sizeof(t_data));
	if (!data)
		return (0);
	argc = 0;
	if (argv[1])
	{
		get_data(data, argv[1]);
	}
}