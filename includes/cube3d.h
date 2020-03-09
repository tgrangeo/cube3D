/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrangeo <tgrangeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 11:11:22 by tgrangeo          #+#    #+#             */
/*   Updated: 2020/03/09 17:38:29 by tgrangeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include "../libft/libft.h"
# include "../minilibx/mlx.h"
# include "keys.h"
# include "struct.h"
# include <math.h>

int			ft_close(t_params *param);
int			ft_key_press(int key, t_params *param);
int			ft_key_release(int key, t_params *param);
void		ft_new_image(t_params *param);
void		ft_vertical_line(int x, int heightwall, t_params *param);
void		ft_parse_config(t_params *param);
t_params	ft_init_struct(void);
double		ft_raycasting(int x, t_params *param);
int 		ft_idle(t_params *param);
void		move_front(t_params *param);
void		move_left(t_params *param);
void		move_right(t_params *param);
void		move_back(t_params *param);
void		move_cam_left(t_params *param);
void		move_cam_right(t_params *param);


#endif