/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrangeo <tgrangeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 10:52:08 by tgrangeo          #+#    #+#             */
/*   Updated: 2020/02/28 15:07:16 by tgrangeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cube3d.h"

void	ft_init_struct(t_params *param)
{
	t_img		img;
	t_pos		pos;
	t_dir		dir;
	t_plane		plane;
	t_map		map;
	t_sidedist	sidedist;
	t_deltadist	deltadist;
	t_step		step;

	param->img = &img;
	param->pos = &pos;
	param->dir = &dir;
	param->plane = &plane;
	param->map = &map;
	ft_parse_config(param);
	param->pos->x = 12;
	param->pos->y = 12;
	param->dir->x = -1;
	param->dir->y = 0;
	param->plane->x = 0;
	param->plane->y = 0.66;
	param->time = 0;
	param->oldTime = 0;
	param->map->y = (int)param->pos->y;
	param->map->x = (int)param->pos->x;
	param->hit = 0;
}
