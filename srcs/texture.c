/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrangeo <tgrangeo@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/01 12:21:50 by thomasgrang       #+#    #+#             */
/*   Updated: 2020/10/01 14:31:17 by tgrangeo         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

void	init_tex(t_params *param)
{
	param->tex.no.ptr = mlx_xpm_file_to_image(param->mlx_ptr,
		param->parse.tex_no, &param->tex.no.width, &param->tex.no.height);
	param->tex.no.data = (int *)mlx_get_data_addr(param->tex.no.ptr,
		&param->tex.no.bpp, &param->tex.no.size_line,
		&param->tex.no.endian);
	param->tex.so.ptr = mlx_xpm_file_to_image(param->mlx_ptr,
		param->parse.tex_so, &param->tex.so.width, &param->tex.so.height);
	param->tex.so.data = (int *)mlx_get_data_addr(param->tex.so.ptr,
		&param->tex.so.bpp, &param->tex.so.size_line,
		&param->tex.so.endian);
	param->tex.ea.ptr = mlx_xpm_file_to_image(param->mlx_ptr,
		param->parse.tex_ea, &param->tex.ea.width, &param->tex.ea.height);
	param->tex.ea.data = (int *)mlx_get_data_addr(param->tex.ea.ptr,
		&param->tex.ea.bpp, &param->tex.ea.size_line, &param->tex.ea.endian);
	param->tex.we.ptr = mlx_xpm_file_to_image(param->mlx_ptr,
		param->parse.tex_we, &param->tex.we.width, &param->tex.we.height);
	param->tex.we.data = (int *)mlx_get_data_addr(param->tex.we.ptr,
		&param->tex.we.bpp, &param->tex.we.size_line, &param->tex.we.endian);
	param->s.ptr = mlx_xpm_file_to_image(param->mlx_ptr, param->sprite,
		&param->s.width, &param->s.height);
	param->s.data = (int *)mlx_get_data_addr(param->s.ptr, &param->s.bpp,
		&param->s.size_line, &param->s.endian);
}

char	ft_wall_face(t_params *param)
{
	if (param->side == 1)
	{
		if (param->step.y > 0)
			return ('W');
		else
			return ('E');
	}
	else if (param->side == 0)
	{
		if (param->step.x > 0)
			return ('S');
		else
			return ('N');
	}
	return (0);
}

t_img	good_tex(t_params *param)
{
	char ret;

	ret = ft_wall_face(param);
	if (ret == 'W')
		return (param->tex.we);
	else if (ret == 'E')
		return (param->tex.ea);
	else if (ret == 'N')
		return (param->tex.no);
	return (param->tex.so);
}

void	tex_to_img(t_params *param, int i, t_img texture)
{
	int it;

	it = (int)(param->tex.tex_y * (double)texture.height) *
		(texture.size_line / 4) + (int)(param->tex.tex_x *
		(double)texture.width);
	param->img.data[i] = texture.data[it];
}

void	define_res(t_params *param, char *str)
{
	param->size_x = recup_int(str + param->parse.i, param);
	if (param->size_x > 1920)
		param->size_x = 1920;
	param->size_y = recup_int(str + param->parse.i, param);
	if (param->size_y > 1080)
		param->size_y = 1080;
}
