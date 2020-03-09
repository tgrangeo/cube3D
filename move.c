/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrangeo <tgrangeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 17:18:56 by tgrangeo          #+#    #+#             */
/*   Updated: 2020/03/09 17:42:09 by tgrangeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cube3d.h"

void	move_front(t_params *param)
{
	param->pos.x += param->dir.x * param->ms;
	param->pos.y += param->dir.y * param->ms;
}

void	move_back(t_params *param)
{
	param->pos.x -= param->dir.x * param->ms;
	param->pos.y -= param->dir.y * param->ms;
}

void	move_right(t_params *param)
{
	param->pos.x += param->plane.x * param->ms;
	param->pos.y += param->plane.y * param->ms;
}

void	move_left(t_params *param)
{
	param->pos.x -= param->plane.x * param->ms;
	param->pos.y -= param->plane.y * param->ms;
}

void	move_cam_right(t_params *param)
{
    double oldDirX = param->dir.x;
    double oldPlaneX = param->plane.x;
    param->dir.x = param->dir.x * cos(param->rotspeed) - param->dir.y * sin(param->rotspeed);
    param->dir.y = oldDirX * sin(param->rotspeed) + param->dir.y * cos(param->rotspeed);
    param->plane.x = param->plane.x * cos(param->rotspeed) - param->plane.y * sin(param->rotspeed);
    param->plane.y = oldPlaneX * sin(param->rotspeed) + param->plane.y * cos(param->rotspeed);
}

void	move_cam_left(t_params *param)
{
    double oldDirX = param->dir.x;
    double oldPlaneX = param->plane.x;
    param->dir.x = param->dir.x * cos(-param->rotspeed) - param->dir.y * sin(-param->rotspeed);
    param->dir.y = oldDirX * sin(-param->rotspeed) + param->dir.y * cos(-param->rotspeed);
    param->plane.x = param->plane.x * cos(-param->rotspeed) - param->plane.y * sin(-param->rotspeed);
    param->plane.y = oldPlaneX * sin(-param->rotspeed) + param->plane.y * cos(-param->rotspeed);
}
