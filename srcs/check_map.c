/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomasgrangeon <thomasgrangeon@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/10 11:40:57 by thomasgrang       #+#    #+#             */
/*   Updated: 2020/11/02 11:49:43 by thomasgrang      ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

static int	checker2(t_params *param, int ici_x, int ici_y)
{
	while (param->worldmap[param->c.y][ici_x] == 0)
	{
		param->c.y++;
		if (param->worldmap[param->c.y][ici_x] == 9)
			return (0);
	}
	param->c.y = ici_y;
	while (param->worldmap[param->c.y][ici_x] == 0)
	{
		param->c.y--;
		if (param->worldmap[param->c.y][ici_x] == 9)
			return (0);
	}
	return (1);
}

static int	checker(t_params *param, int ici_x, int ici_y)
{
	param->c.x = ici_x;
	param->c.y = ici_y;
	while (param->worldmap[ici_y][param->c.x] == 0)
	{
		param->c.x++;
		if (param->worldmap[ici_y][param->c.x] == 9)
			return (0);
	}
	param->c.x = ici_x;
	while (param->worldmap[ici_y][param->c.x] == 0)
	{
		param->c.x--;
		if (param->worldmap[ici_y][param->c.x] == 9)
			return (0);
	}
	if (checker2(param, ici_x, ici_y) == 0)
		return (0);
	return (1);
}

int			ft_check_map(t_params *param)
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
					dprintf(1, "Error\nmap invalid\n");
					exit(0);
				}
			x++;
		}
		x = 0;
		y++;
	}
	return (1);
}
