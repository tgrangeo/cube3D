/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrangeo <tgrangeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 18:41:38 by tgrangeo          #+#    #+#             */
/*   Updated: 2020/03/12 11:47:51 by tgrangeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cube3d.h"

static int new_image(t_params *param)
{
	int x;
	int wallheight;
	double dist;

	x = 0;
	dist = 0;
	while (x < param->size_x)
	{
		dist = ft_raycasting(x, param);
		wallheight = (int)(param->size_y / dist);
		ft_vertical_line(x, wallheight, param);
		x++;
	}
	mlx_put_image_to_window(param->mlx_ptr, param->win_ptr, param->img.img, 0, 0);
	return (1);
}


int	ft_loop(t_params *param)
{
	//check_next_pos(param);
	if (param->key.w == 1)
		move_front(param);
	if (param->key.a == 1)
		move_left(param);
	if (param->key.s == 1)
		move_back(param);
	if (param->key.d == 1)
		move_right(param);
	if (param->key.ar == 1)
		move_cam_right(param);
	if (param->key.af == 1)
		move_cam_left(param);
	new_image(param);
	return (1);
}