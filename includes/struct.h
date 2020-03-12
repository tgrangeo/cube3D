/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrangeo <tgrangeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 14:17:31 by tgrangeo          #+#    #+#             */
/*   Updated: 2020/03/12 18:23:27 by tgrangeo         ###   ########.fr       */
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
	
}				t_img;

typedef	struct s_key
{
	int w;
	int a;
	int s;
	int d;
	int	ar;
	int af;
	
}				t_key;

typedef struct	s_parse
{
	char	**map;
	char	*tex_no;
	char	*tex_so;
	char	*tex_we;
	char	*tex_ea;
}				t_parse;



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
	t_key		key;
	t_parse		parse;
	void		*win_ptr;
	void		*mlx_ptr;
	void		*img_ptr;
	int			size_x;
	int			size_y;
	double		cameraX;
	int			hit;
    int			side;
	double		walldist;
	int			color;
	double		ms;
	double		rotspeed;
	int 		perm_x;
	int 		perm_y;
}				t_params;

#endif