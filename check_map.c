/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomasgrangeon <thomasgrangeon@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/10 11:40:57 by thomasgrang       #+#    #+#             */
/*   Updated: 2020/10/01 10:50:15 by thomasgrang      ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cube3d.h"

static int checker(t_params *param, int ici_x, int ici_y)
{
	int x;
	int y;

	x = ici_x;
	y = ici_y;
	while (param->worldmap[ici_y][x] == 0)
	{
		x++;
		if (param->worldmap[ici_y][x] == 9)
			return (0);
	}
	x = ici_x;
	while (param->worldmap[ici_y][x] == 0)
	{
		x--;
		if (param->worldmap[ici_y][x] == 9)
			return (0);
	}
	while (param->worldmap[y][ici_x] == 0)
	{
		y++;
		if (param->worldmap[y][ici_x] == 9)
			return (0);
	}
	y = ici_y;
	while (param->worldmap[y][ici_x] == 0)
	{
		y--;
		if (param->worldmap[y][ici_x] == 9)
			return (0);
	}
	return (1);
	
}

int		ft_check_map(t_params *param)
{
	int x;
	int y;

	x = 0;
	y = 0;
	while (y <= param->y_map)
	{
		while (x <= param->x_map)
		{
			if (param->worldmap[y][x] == 0)
				if (checker(param, x, y) == 0)
				{
					dprintf(1, " -----------\n| Map Error |\n -----------\n");
					exit(0);
				}
			x++;
		}
		x = 0;
		y++;
	}
	return(1);
}