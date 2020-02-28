/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrangeo <tgrangeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 14:17:31 by tgrangeo          #+#    #+#             */
/*   Updated: 2020/02/28 15:31:15 by tgrangeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef	struct	s_pos
{
	double 		x;
	double 		y;

}				t_pos;

typedef	struct	s_dir
{
	double 		x;
	double 		y;

}				t_dir;

typedef	struct	s_plane
{
	double 		x;
	double 		y;

}				t_plane;

typedef	struct	s_raydir
{
	double 		x;
	double 		y;

}				t_raydir;

typedef	struct	s_map
{
	int 		x;
	int 		y;

}				t_map;


typedef struct	s_img
{
	int			*data;
	int			bpp;
	int 		size_line;
	int			endian;
	
}				t_img;
//
typedef	struct	s_sidedist
{
	double 		x;
	double 		y;

}				t_sidedist;

typedef	struct	s_deltadist
{
	double 		x;
	double 		y;

}				t_deltadist;

typedef	struct	s_step
{
	double 		x;
	double 		y;

}				t_step;

typedef struct s_params 
{
	t_img		*img;
	t_map		*map;
	t_raydir	*raydir;
	t_plane		*plane;
	t_dir		*dir;
	t_pos		*pos;
	t_sidedist	*sidedist;
	t_deltadist	*deltadist;
	t_step		*step;
	void		*win_ptr;
	void		*mlx_ptr;
	void		*img_ptr;
	int			size_x;
	int			size_y;
	double		time;
	double		cameraX;
	double		oldTime;
	int			hit;
    int			side;
	double		walldist;
	int			line_height;
	int			drawstart;
	int			drawend;
}				t_params;

#endif