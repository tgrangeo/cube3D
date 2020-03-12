/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_image.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrangeo <tgrangeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 15:03:19 by tgrangeo          #+#    #+#             */
/*   Updated: 2020/03/12 11:54:12 by tgrangeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cube3d.h"

void	ft_vertical_line(int x, int heightwall, t_params *param)
{
	int		y;
	int		size_sky;

	y = 0;
	size_sky = (param->size_y - heightwall) / 2;
	while (y < param->size_y)
	{
		if (y < size_sky)
			param->img.data[x + y * param->size_x] = 0x00ffff;
		else if (y < size_sky + heightwall)
			param->img.data[x + (y * param->size_x)] = 0x004FB4;
		else
			param->img.data[x + (y * param->size_x)] = 0x696969;
		y++;
	}
}
