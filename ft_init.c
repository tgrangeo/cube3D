/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomasgrangeon <thomasgrangeon@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 10:52:08 by tgrangeo          #+#    #+#             */
/*   Updated: 2020/09/01 12:39:35 by thomasgrang      ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cube3d.h"

t_params	ft_init_struct(void)
{
	t_params	param;

	param.size_y = 0;
	param.size_x = 0;
	param.pos.x = 0;
	param.pos.y = 0;
	param.dir.x = 1;
	param.dir.y = 0;
	param.plane.x = 0;
	param.plane.y = 0.66;
	param.ms = 0.10;
	param.rotspeed = 0.04;
	param.texWidth = 64;
	param.texHeight = 64;
	return (param);
}

void            ft_init_map_two(t_params *param, int in_char)
{
    if (in_char == 'S')
    {
        param->dir.x = 1;
        param->dir.y = 0;
        param->plane.x = 0;
        param->plane.y = -0.66;
    }
    else if (in_char == 'N')
    {
        param->dir.x= -1;
        param->dir.y = 0;
        param->plane.x = 0;
        param->plane.y = 0.66;
    }
}

void            ft_init_map(t_params *param, int in_char)
{
    if (in_char == 'E')
    {
        param->dir.x = 0;
        param->dir.y = 1;
        param->plane.x = 0.66;
        param->plane.y = 0;
    }
    else if (in_char == 'W')
    {
        param->dir.x = 0;
        param->dir.y = -1;
        param->plane.x = -0.66;
        param->plane.y = 0;
    }
}