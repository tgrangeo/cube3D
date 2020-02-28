/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrangeo <tgrangeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 10:18:11 by tgrangeo          #+#    #+#             */
/*   Updated: 2020/02/28 15:30:38 by tgrangeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "includes/cube3d.h"

# define mapWidtparam->size_y 24
# define mapHeight 24

ft_raycasting(t_params *param)
{
	int worldmap[mapWidth][mapHeight]=
	{
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
		{1,0,1,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,1,0,1,1},
		{1,0,1,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,1,0,1,1},
		{1,0,1,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,1,0,1,1},
		{1,0,1,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,1,0,1,1},
		{1,0,1,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,1,0,1,1},
		{1,0,1,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,1,0,1,1},
		{1,0,1,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,1,0,1,1},
		{1,0,1,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,1,0,1,1},
		{1,0,1,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,1,0,1,1},
		{1,0,1,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,1,0,1,1},
		{1,0,1,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,1,0,1,1},
		{1,0,1,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,1,0,1,1},
		{1,0,1,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,1,0,1,1},
		{1,0,1,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,1,0,1,1},
		{1,0,1,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,1,0,1,1},
		{1,0,1,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,1,0,1,1},
		{1,0,1,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,1,0,1,1},
		{1,0,1,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,1,0,1,1},
		{1,0,1,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,1,0,1,1},
		{1,0,1,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,1,0,1,1},
		{1,0,1,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,1,0,1,1},
		{1,0,1,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,1,0,1,1},
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
	};
	int	x;

	x = 0;
	while (x++ < param->size_x)
	{
		param->cameraX = 2 * x / (double)param->size_x - 1;
		param->raydir->x = param->dir->x + param->plane->x * param->cameraX;
		param->raydir->y = param->dir->y + param->plane->y * param->cameraX;
		if (param->raydir->x < 0)
    	{
    	  param->step->x = -1;
    	  param->sidedist->x = (param->pos->x - param->map->x) * param->deltadist->x;
    	}
    	else
    	{
    	  param->step->x = 1;
    	  param->sidedist->x = (param->map->x + 1.0 - param->pos->x) * param->deltadist->x;
    	}
    	if (param->raydir->y < 0)
    	{
    	  param->step->y = -1;
    	  param->sidedist->y = (param->pos->y - param->map->y) * param->deltadist->y;
    	}
    	else
    	{
    	  param->step->y = 1;
    	  param->sidedist->y = (param->map->y + 1.0 - param->pos->y) * param->deltadist->y;
    	}
		while (param->hit == 0)
      	{
        	if(param->sidedist->x < param->sidedist->y)
        	{
          		param->sidedist->x += param->deltadist->x;
          		param->map->x += param->step->x;
          		param->side = 0;
        	}
        	else
        	{
         		param->sidedist->y += param->deltadist->y;
         		param->map->y += param->step->y;
         		param->side = 1;
        	}
        	if(worldmap[param->map->x][param->map->y] > 0)
				param->hit = 1;
      	}
		if(param->side == 0) 
			param->walldist = (param->map->x - param->pos->x + (1 - param->step->x) / 2) / param->raydir->x;
      	else
			param->walldist = (param->map->y - param->pos->y + (1 - param->step->y) / 2) / param->raydir->y;
		param->line_height = (int)(param->size_y / param->walldist);
		param->drawstart = -param->line_height / 2 + param->size_y / 2;
    	if (param->drawstart < 0)
			param->drawstart = 0;
    	param->drawend = param->line_height / 2 + param->size_y / 2;
    	if (param->drawend >= param->size_y)
			param->drawend = param->size_y - 1;
	}
	








}