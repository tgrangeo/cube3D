/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_image.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomasgrangeon <thomasgrangeon@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 15:03:19 by tgrangeo          #+#    #+#             */
/*   Updated: 2020/09/29 20:39:48 by thomasgrang      ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */


#include "includes/cube3d.h"

void	ft_vertical_line(int x, int heightwall, t_params *param)
{
	int		y;
	int 	i;
	int		size_sky;
	t_img	texture;

	y = 0;
	i = 0;
	size_sky = (param->size_y - heightwall) / 2;
	texture = good_tex(param);
	if (ft_wall_face(param) == 'W' || ft_wall_face(param) ==  'E')
		param->tex.tex_x = param->hhiitt.x - (int)param->hhiitt.x;
	else if (ft_wall_face(param) == 'N' || ft_wall_face(param) == 'S')
		param->tex.tex_x = param->hhiitt.y - (int)param->hhiitt.y;
	while (y < param->size_y)
	{
		if (y < size_sky)
			param->img.data[x + y * param->size_x] = param->color_sky;
		else if (y < size_sky + heightwall)
		{
			i = y * param->size_x + x;
            param->tex.tex_y = ((double)y - (double)size_sky) / (double)heightwall;
            tex_to_img(param, i, texture);
		}
		else
			param->img.data[x + (y * param->size_x)] = param->color_floor;
		y++;
	}
}
