/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomasgrangeon <thomasgrangeon@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 14:17:31 by tgrangeo          #+#    #+#             */
/*   Updated: 2020/10/01 10:33:50 by thomasgrang      ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H


typedef	struct	s_vector_d
{
	double 		x;
	double 		y;

}				t_vector_d;

typedef	struct	s_vector_i
{
	int 		x;
	int 		y;

}				t_vector_i;

typedef struct	s_img
{
	void		*img;
	int			*data;
	int			bpp;
	int 		size_line;
	int			endian;
	void		*ptr;
	int			width;
	int			height;
	
}				t_img;

typedef struct	s_texture
{
	t_img	no;
	t_img	so;
	t_img	ea;
	t_img	we;
	double	tex_x;
	double	tex_y;
}			t_texture;

typedef	struct s_key
{
	int w;
	int a;
	int s;
	int d;
	int	ar;
	int af;
	
}				t_key;

typedef struct	s_rgb
{
	int	r;
	int	g;
	int	b;
}				t_rgb;

typedef struct	s_parse
{
	int		i;
	char	*tex_no;
	char	*tex_so;
	char	*tex_we;
	char	*tex_ea;
}				t_parse;

typedef struct	s_sprite
{
	int		color;
	int		texy;
	int		texx;
	int		d;
	double	spritex;
	double	spritey;
	double	invdet;
	double	transformx;
	double	transformy;
	int		spritescreenx;
	int		spritewidth;
	int		spriteheight;
	int		drawstarty;
	int		drawstartx;
	int		drawendx;
	int		drawendy;
	int		y;
	int		stripe;
}				t_sprite;

typedef struct s_params 
{
	t_img		img;
	t_vector_i	map;
	t_vector_d	raydir;
	t_vector_d	plane;
	t_vector_d	dir;
	t_vector_d	pos;
	t_vector_d	sidedist;
	t_vector_d	deltadist;
	t_vector_i	step;
	t_vector_d	hhiitt;
	t_key		key;
	t_parse		parse;
	t_texture	tex;
	void		*win_ptr;
	void		*mlx_ptr;
	void		*img_ptr;
	int			size_x;
	int			size_y;
	double		cameraX;
	int			hit;
    int			side;
	double		walldist;
	int			color_sky;
	int			color_floor;
	double		ms;
	double		rotspeed;
	int 		perm_x;
	int 		perm_y;
	char		*sprite;
	int			first_line;
	int			y_map;
	int			x_map;
	int			**worldmap;
	int 		textNum;
	double		wallx;
	int			texX;
	int			texWidth;
	int			texHeight;
	int			*zbuffer;
	t_img		s;
	t_sprite	ss;
	t_vector_d	sss;
}				t_params;

#endif