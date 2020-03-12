#include "includes/cube3d.h"

int main(void)
{
	t_params	param;

	param = ft_init_struct();
	//ft_parse_config(&param);
	param.mlx_ptr = mlx_init();
	param.win_ptr = mlx_new_window(param.mlx_ptr, param.size_x, param.size_y, "suce");

	param.img.img = mlx_new_image(param.mlx_ptr, param.size_x, param.size_y);
	param.img.data = (int *)mlx_get_data_addr(param.img.img, &param.img.bpp, &param.img.size_line, &param.img.endian);
	mlx_loop_hook(param.mlx_ptr, ft_loop, &param);
	mlx_hook(param.win_ptr, 2, 0, ft_key_press, &param);
	mlx_hook(param.win_ptr, 3, 0, ft_key_release, &param);
	mlx_hook(param.win_ptr, 17, 0, ft_close, &param);
  	mlx_loop(param.mlx_ptr);
  return (0);
}