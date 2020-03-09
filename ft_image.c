/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_image.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrangeo <tgrangeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 15:03:19 by tgrangeo          #+#    #+#             */
/*   Updated: 2020/03/09 17:46:46 by tgrangeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cube3d.h"

void	ft_vertical_line(int x, int heightwall, t_params *param)
{
	int		y;
	int		size_sky;

	y = 0;
	//dprintf(1, "1:%d\n", param->size_y);
	//dprintf(1, "2:%d\n", heightwall);
	size_sky = (param->size_y - heightwall) / 2;
	//dprintf(1, "sky:%d\n", size_sky);
	//dprintf(1, "wall:%d\n", size_sky + heightwall);
	while (y < param->size_y)
	{
		//dprintf(1, "h:%d\n", param->size_y);
		if (y < size_sky)
		{
			//dprintf(1, "y:%d\n", y);
			param->img.data[x + y * param->size_x] = 0x00ffff;
			//dprintf(1, "salut plafond\n");
		}
		else if (y < size_sky + heightwall)
		{
			//dprintf(1, "salut mur\n");
			param->img.data[x + (y * param->size_x)] = 0x004FB4;
		}
		else
		{
			//dprintf(1, "salut sol\n");
			param->img.data[x + (y * param->size_x)] = 0x696969;
		}
		y++;
	}
}
