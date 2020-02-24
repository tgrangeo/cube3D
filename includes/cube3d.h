/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrangeo <tgrangeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 11:11:22 by tgrangeo          #+#    #+#             */
/*   Updated: 2020/02/24 15:48:57 by tgrangeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include "../libft/libft.h"
# include "../minilibx/mlx.h"
# include "keys.h"
# include <unistd.h>
# include <stdio.h>

typedef struct	s_img
{
	int		bpp;
	int 	size_line;
	int		endian;

}				t_img;

typedef struct s_params 
{
	t_img	img;
	void	*win_ptr;
	void	*mlx_ptr;
	void	*img_ptr;
	int		size_x;
	int		size_y;
}				t_params;

int			ft_close(t_params *param);
int			ft_key_press(int key, t_params *param);
int			ft_key_release(int key, t_params *param);
void		ft_new_image(int x, int y, t_params *param);


#endif