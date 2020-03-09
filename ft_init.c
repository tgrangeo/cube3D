/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrangeo <tgrangeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 10:52:08 by tgrangeo          #+#    #+#             */
/*   Updated: 2020/03/09 17:44:31 by tgrangeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cube3d.h"

t_params	ft_init_struct(void)
{
	t_params	param;

	param.size_y = 1080;
	param.size_x = 1920;
	param.pos.x = 2.5;
	param.pos.y = 2.5;
	param.dir.x = 1;
	param.dir.y = 0;
	param.plane.x = 0;
	param.plane.y = 0.66;
	param.color = 0x34eb40;
	param.ms = 0.10;
	param.rotspeed = 0.06;
	return (param);
}
