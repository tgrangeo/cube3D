/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrangeo <tgrangeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 11:11:22 by tgrangeo          #+#    #+#             */
/*   Updated: 2020/02/28 14:18:53 by tgrangeo         ###   ########.fr       */
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
void		ft_vertical_line(int heigt, t_params *param);
void		ft_parse_config(t_params *param);
void		ft_vertical_line2(int heigt, t_params *param);
void		ft_couloir(t_params *param, int largeur);
void		ft_init_struct(t_params *param);


#endif