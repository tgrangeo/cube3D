/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomasgrangeon <thomasgrangeon@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/08 16:23:31 by thomasgrang       #+#    #+#             */
/*   Updated: 2020/09/29 20:43:28 by thomasgrang      ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cube3d.h"

void	ft_init_sprite(t_params *param, int x, int y)
{
	if (param->spr.x == 0 && param->spr.y == 0)
	{
		x += 1;
		y += 1;
		param->spr.x = x + 1;
		param->spr.y = y;
	}
	else
	{
		dprintf(1, " --------------\n|   Map Error  |\n| multi sprite |\n --------------\n");
		exit(0);
	}
}