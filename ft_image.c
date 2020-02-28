/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_image.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrangeo <tgrangeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 15:03:19 by tgrangeo          #+#    #+#             */
/*   Updated: 2020/02/28 10:29:52 by tgrangeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cube3d.h"

void	ft_new_image(t_params *param)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	param->img_ptr = mlx_new_image(param->mlx_ptr, param->size_x, param->size_y);
	param->img->data = (int *)mlx_get_data_addr(param->img_ptr, &param->img->bpp, &param->img->size_line, &param->img->endian);
	y = param->size_y / 2;
	while (x < param->size_x)
	{
		param->img->data[x + y * param->size_x] = 0x34eb40;
		x++;
	}
	ft_couloir(param, 600);
	/*ft_vertical_line(360, param);
	ft_vertical_line2(360, param);*/
	mlx_put_image_to_window(param->mlx_ptr, param->win_ptr, param->img_ptr, 0, 0);
	//dprintf(1, "%d\n%d\n%d\n", param->img->bpp, param->img->size_line, param->img->endian);
}

void	ft_couloir(t_params *param, int largeur)
{
	int x;
	int y;
	int len;

	x = 0;
	y = 0;
	len = param->size_y;
	while (y < param->size_y + len)
	{
		while (x++ < param->size_x / 2 - largeur / 2)
			param->img->data[x + y * param->size_x] = 0x34eb40;
		x = 0;
		len--;
		y++;
	}
}

/*
void	ft_vertical_line(int heigt, t_params *param)
{
	int x;
	int y;
	int len;

	(void)heigt;
	x = 0;
	len = param->size_y;
	y = 0;
	while (x < param->size_x / 2 - 100)
	{
		while (y < len)
		{
			param->img->data[x + y * param->size_x] = 0x34eb40;
			printf("%d\n", y);
			y++;
		}
		x += 1;
		len -= 1;
		y = 0;
	}
}

void	ft_vertical_line2(int heigt, t_params *param)
{
	int x;
	int y;
	int len;

	(void)heigt;
	x = param->size_x;
	len = param->size_y;
	y = 0;
	while (x > param->size_x / 2 - 100)
	{
		while (y < len)
		{
			param->img->data[x + y * param->size_x] = 0x34eb40;
			printf("%d\n", y);
			y--;
		}
		x -= 1;
		len -= 1;
		y = len;
	}
}*/