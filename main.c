#include "includes/cube3d.h"

int main(void)
{
	t_params	param;

	ft_init_struct(&param);
	param.mlx_ptr = mlx_init();
	param.win_ptr = mlx_new_window(param.mlx_ptr, param.size_x, param.size_y, "Title");
	ft_new_image(&param);

  	mlx_hook(param.win_ptr, 17, 0, ft_close, &param);
	mlx_hook(param.win_ptr, 2, 0, ft_key_press, &param);
	mlx_hook(param.win_ptr, 3, 0, ft_key_release, &param);
  	mlx_loop(param.mlx_ptr);
  return (0);
}