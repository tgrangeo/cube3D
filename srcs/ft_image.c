/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_image.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrangeo <tgrangeo@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 15:03:19 by tgrangeo          #+#    #+#             */
/*   Updated: 2020/10/01 16:13:18 by tgrangeo         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

void	ft_vertical_line(int x, int h_wall, t_params *p)
{
	int		size_sky;
	t_img	texture;

	p->c.y = 0;
	p->c.x = 0;
	size_sky = (p->size_y - h_wall) / 2;
	texture = good_tex(p);
	if (ft_wall_face(p) == 'W' || ft_wall_face(p) == 'E')
		p->tex.tex_x = p->hhiitt.x - (int)p->hhiitt.x;
	else if (ft_wall_face(p) == 'N' || ft_wall_face(p) == 'S')
		p->tex.tex_x = p->hhiitt.y - (int)p->hhiitt.y;
	while (p->c.y < p->size_y)
	{
		if (p->c.y < size_sky)
			p->img.data[x + p->c.y * p->size_x] = p->color_sky;
		else if (p->c.y < size_sky + h_wall)
		{
			p->c.x = p->c.y * p->size_x + x;
			p->tex.tex_y = ((double)p->c.y - (double)size_sky) / (double)h_wall;
			tex_to_img(p, p->c.x, texture);
		}
		else
			p->img.data[x + (p->c.y * p->size_x)] = p->color_floor;
		p->c.y++;
	}
}
