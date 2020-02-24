#include "includes/cube3d.h"

int main(void)
{
	t_params	param;
	int		*data;
	int x = 0;
	int y = 0;
	t_img		img;

	param.size_x = 1920;
	param.size_y = 1080;
	param.mlx_ptr = mlx_init();
	param.win_ptr = mlx_new_window(param.mlx_ptr, param.size_x, param.size_y, "Title");

	param.img_ptr = mlx_new_image(param.mlx_ptr, param.size_x, param.size_y);
	data = (int *)mlx_get_data_addr(param.img_ptr, &img.bpp, &img.size_line, &img.endian);
	y = 540;
	while(x < 1920)
	{
		data[x + y * img.size_line /4] = 0xFFFFFF;
		x++;
	}
	mlx_put_image_to_window(param.mlx_ptr, param.win_ptr, param.img_ptr, 0, 0);
	dprintf(1, "%d\n%d\n%d\n", img.bpp, img.size_line, img.endian);

  	mlx_hook(param.win_ptr, 17, 0, ft_close, &param);
	mlx_hook(param.win_ptr, 2, 0, ft_key_press, &param);
	mlx_hook(param.win_ptr, 3, 0, ft_key_release, &param);
  	mlx_loop(param.mlx_ptr);
  return (0);
}