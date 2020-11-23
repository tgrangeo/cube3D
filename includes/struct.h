/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomasgrangeon <thomasgrangeon@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 14:17:31 by tgrangeo          #+#    #+#             */
/*   Updated: 2020/11/23 12:44:45 by thomasgrang      ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef	struct	s_vector_d
{
	double		x;
	double		y;
}				t_vector_d;

typedef	struct	s_vector_i
{
	int			x;
	int			y;
}				t_vector_i;

typedef struct	s_img
{
	void		*img;
	int			*data;
	int			bpp;
	int			size_line;
	int			endian;
	void		*ptr;
	int			width;
	int			height;
}				t_img;

typedef struct	s_texture
{
	t_img		no;
	t_img		so;
	t_img		ea;
	t_img		we;
	double		tex_x;
	double		tex_y;
}				t_texture;

typedef	struct	s_key
{
	int			w;
	int			a;
	int			s;
	int			d;
	int			ar;
	int			af;
}				t_key;

typedef struct	s_rgb
{
	int			r;
	int			g;
	int			b;
}				t_rgb;

typedef struct	s_parse
{
	int			i;
	char		*tex_no;
	char		*tex_so;
	char		*tex_we;
	char		*tex_ea;
}				t_parse;

typedef struct	s_sprite
{
	int			color;
	int			texy;
	int			texx;
	int			d;
	double		spritex;
	double		spritey;
	double		invdet;
	double		transformx;
	double		transformy;
	int			spritescreenx;
	int			spritewidth;
	int			spriteheight;
	int			drawstarty;
	int			drawstartx;
	int			drawendx;
	int			drawendy;
	int			y;
	int			stripe;
}				t_sprite;

typedef struct	s_bitmap_file_header
{
	unsigned char	bitmap_type[2];
	int				file_size;
	short			reserved1;
	short			reserved2;
	unsigned int	offset_bits;
}				t_bfh;

typedef struct	s_bitmap_image_header
{
	unsigned int	size_header;
	unsigned int	width;
	unsigned int	height;
	short int		planes;
	short int		bit_count;
	unsigned int	compression;
	unsigned int	image_size;
	unsigned int	ppm_x;
	unsigned int	ppm_y;
	unsigned int	clr_used;
	unsigned int	clr_important;
}				t_bih;

typedef	struct	s_bmp
{
	t_bih	bih;
	t_bfh	bfh;
	int		fd;
}				t_bmp;

typedef struct	s_params
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
	double		cam_x;
	int			hit;
	int			side;
	double		walldist;
	int			color_sky;
	int			color_floor;
	double		ms;
	double		rotspeed;
	int			perm_x;
	int			perm_y;
	char		*sprite;
	int			first_line;
	int			y_map;
	int			x_map;
	int			**worldmap;
	int			tex_num;
	double		wallx;
	int			tex_x;
	int			tex_w;
	int			tex_h;
	int			*zbuffer;
	t_img		s;
	t_sprite	ss;
	t_vector_d	sss;
	t_vector_i	l;
	t_vector_i	c;
	t_vector_i	v;
	int			i;
	char		*cube;
	int			fd;
}				t_params;

#endif
