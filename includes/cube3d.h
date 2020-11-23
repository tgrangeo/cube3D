/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomasgrangeon <thomasgrangeon@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 11:11:22 by tgrangeo          #+#    #+#             */
/*   Updated: 2020/11/23 12:57:08 by thomasgrang      ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE3D_H
# define CUBE3D_H

# include "../libft/libft.h"
# include "../minilibx/mlx.h"
# include "keys.h"
# include "struct.h"
# include <math.h>

int			ft_close(t_params *param);
int			ft_key_press(int key, t_params *param);
int			ft_key_release(int key, t_params *param);
int			new_image(t_params *param);
void		ft_vertical_line(int x, int heightwall, t_params *param);
void		ft_parse_config(t_params *param, char *cube);
t_params	ft_init_struct(void);
double		ft_raycasting(int x, t_params *param);
int			ft_idle(t_params *param);
void		move_front(t_params *param, t_vector_d *fpos);
void		move_left(t_params *param, t_vector_d *fpos);
void		move_right(t_params *param, t_vector_d *fpos);
void		move_back(t_params *param, t_vector_d *fpos);
void		move_cam_left(t_params *param);
void		move_cam_right(t_params *param);
int			ft_loop(t_params *param);
void		ft_size_tab(t_params *param, char *cube);
void		ft_map_tab(t_params *param, char *cube);
void		ft_init_map(t_params *param, int in_char);
void		ft_init_map_two(t_params *param, int in_char);
int			ft_check_map(t_params *param);
void		init_tex(t_params *param);
char		ft_wall_face(t_params *param);
t_img		good_tex(t_params *param);
void		tex_to_img(t_params *param, int i, t_img texture);
void		ft_init_sprite(t_params *param, int x, int y);
void		raycast_sprite(t_params *p);
void		raycast_sprite_init(t_sprite *s, t_params *p);
void		define_res(t_params *param, char *str);
int			recup_int(char *str, t_params *param);
void		check_line(char *str, t_params *param);
int			is_line_map(char *str);
void		ft_map_tab2(t_params *param, char	*buffer, int **temp_map);
void		ft_ligne(int *map, char *str, t_params *param, int line);
void		ft_ligne2(int *map, char *str, t_params *param, int line);
void		define_pos(t_params *param, char dir, int x, int y);
void		free_tab_2D(int	**tab, int line);
void		ft_bitmap_image(t_bmp *bmp, int fd, t_img img);
int			ft_save_bitmap(const char *filename, t_params params);

#endif
