#include "includes/cube3d.h"

static int new_image(t_params *param)
{
	int x;
	int wallheight;
	double dist;

	x = 0;
	dist = 0;
	while (x < param->size_x)
	{
		dist = ft_raycasting(x, param);
		wallheight = (int)(param->size_y / dist);
		ft_vertical_line(x, wallheight, param);
		x++;
	}
	mlx_put_image_to_window(param->mlx_ptr, param->win_ptr, param->img.img, 0, 0);
	return (1);
}

void	ft_col(t_params *param, t_vector_d *fpos)
{
	if (param->worldmap[(int)(fpos->x + param->pos.x)][(int)param->pos.y] >= 1)
		param->perm_x = 0;
	else
		param->perm_x = 1;
	
	if (param->worldmap[(int)param->pos.x][(int)(fpos->y + param->pos.y)] >= 1)
		param->perm_y = 0;
	else
		param->perm_y = 1;
}


int	ft_loop(t_params *param)
{
	t_vector_d	fpos;

	if (param->key.w == 1)
		move_front(param, &fpos);
	if (param->key.a == 1)
		move_left(param, &fpos);
	if (param->key.s == 1)
		move_back(param, &fpos);
	if (param->key.d == 1)
		move_right(param, &fpos);
	if (param->key.ar == 1)
		move_cam_right(param);
	if (param->key.af == 1)
		move_cam_left(param);
	ft_col(param, &fpos);
	param->pos.x = param->pos.x + (fpos.x * param->perm_x);
	param->pos.y = param->pos.y + (fpos.y * param->perm_y);
	new_image(param);
	return (1);
}