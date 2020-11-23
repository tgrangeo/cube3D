/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomasgrangeon <thomasgrangeon@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/01 13:56:46 by tgrangeo          #+#    #+#             */
/*   Updated: 2020/11/23 12:52:27 by thomasgrang      ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

int		ft_close(t_params *param)
{
	mlx_clear_window(param->mlx_ptr, param->win_ptr);
	mlx_destroy_window(param->mlx_ptr, param->win_ptr);
	exit(EXIT_SUCCESS);
	return (0);
}

int		ft_key_press(int key, t_params *param)
{
	if (key == KEY_ESCAPE)
		ft_close(param);
	if (key == KEY_A)
		param->key.a = 1;
	if (key == KEY_S)
		param->key.s = 1;
	if (key == KEY_D)
		param->key.d = 1;
	if (key == KEY_W)
		param->key.w = 1;
	if (key == KEY_LEFT)
		param->key.ar = 1;
	if (key == KEY_RIGHT)
		param->key.af = 1;
	return (1);
}

int		ft_key_release(int key, t_params *param)
{
	if (key == KEY_A)
		param->key.a = 0;
	if (key == KEY_S)
		param->key.s = 0;
	if (key == KEY_D)
		param->key.d = 0;
	if (key == KEY_W)
		param->key.w = 0;
	if (key == KEY_LEFT)
		param->key.ar = 0;
	if (key == KEY_RIGHT)
		param->key.af = 0;
	return (1);
}
