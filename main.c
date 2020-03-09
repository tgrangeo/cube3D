#include "includes/cube3d.h"

int	ft_idle(t_params *param)
{

	if (param->key.w == 1)
		move_front(param);
	if (param->key.a == 1)
		move_left(param);
	if (param->key.s == 1)
		move_back(param);
	if (param->key.d == 1)
		move_right(param);
	if (param->key.ar == 1)
		move_cam_right(param);
	if (param->key.af == 1)
		move_cam_left(param);
	












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

int main(void)
{
	t_params	param;

	param = ft_init_struct();
	//dprintf(1, "size_y: %d\n\n", param.size_y);
	param.mlx_ptr = mlx_init();

	param.win_ptr = mlx_new_window(param.mlx_ptr, param.size_x, param.size_y, "suce");

	param.img.img = mlx_new_image(param.mlx_ptr, param.size_x, param.size_y);
	param.img.data = (int *)mlx_get_data_addr(param.img.img, &param.img.bpp, &param.img.size_line, &param.img.endian);
	mlx_loop_hook(param.mlx_ptr, ft_idle, &param);
	mlx_hook(param.win_ptr, 2, 0, ft_key_press, &param);
	mlx_hook(param.win_ptr, 3, 0, ft_key_release, &param);
  	mlx_hook(param.win_ptr, 17, 0, ft_close, &param);

  	mlx_loop(param.mlx_ptr);
  return (0);
}