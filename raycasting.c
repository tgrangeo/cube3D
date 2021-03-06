/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomasgrangeon <thomasgrangeon@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 10:18:11 by tgrangeo          #+#    #+#             */
/*   Updated: 2020/10/01 10:03:59 by thomasgrang      ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */


#include "includes/cube3d.h"


	double	ft_raycasting(int	x, t_params *param)	
	{
		param->cameraX = 2 * x / (double)param->size_x - 1;
		param->raydir.x = param->dir.x + param->plane.x * param->cameraX;
		param->raydir.y = param->dir.y + param->plane.y * param->cameraX;
		param->map.x = (int)param->pos.x;
		param->map.y = (int)param->pos.y;

		param->hit = 0;
		param->side = 0;
		
		param->deltadist.x = fabs(1 / param->raydir.x);
      	param->deltadist.y = fabs(1 / param->raydir.y);
	  
		if (param->raydir.x < 0)
    	{
    	  param->step.x = -1;
    	  param->sidedist.x = (param->pos.x - param->map.x) * param->deltadist.x;
    	}
    	else
    	{
    	  param->step.x = 1;
    	  param->sidedist.x = (param->map.x + 1.0 - param->pos.x) * param->deltadist.x;
    	}
    	if (param->raydir.y < 0)
    	{
    	  param->step.y = -1;
    	  param->sidedist.y = (param->pos.y - param->map.y) * param->deltadist.y;
    	}
    	else
    	{
    	  param->step.y = 1;
    	  param->sidedist.y = (param->map.y + 1.0 - param->pos.y) * param->deltadist.y;
    	}
		while (param->hit == 0)
      	{
        	if(param->sidedist.x < param->sidedist.y)
        	{
          		param->sidedist.x += param->deltadist.x;
          		param->map.x += param->step.x;
          		param->side = 0;
        	}
        	else
        	{
         		param->sidedist.y += param->deltadist.y;
         		param->map.y += param->step.y;
         		param->side = 1;
			}
			if(param->worldmap[param->map.x][param->map.y] == 1)
				param->hit = 1;
		}
		if (param->side == 0)
			param->walldist = (param->map.x - param->pos.x + (1 - param->step.x) / 2) / param->raydir.x;
      	else
			param->walldist = (param->map.y - param->pos.y + (1 - param->step.y) / 2) / param->raydir.y;
		
		param->hhiitt.x = param->pos.x + param->raydir.x * param->walldist;
		param->hhiitt.y = param->pos.y + param->raydir.y * param->walldist;
		
		return (param->walldist);
	}
