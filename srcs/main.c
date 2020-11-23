/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomasgrangeon <thomasgrangeon@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/01 13:56:59 by tgrangeo          #+#    #+#             */
/*   Updated: 2020/11/23 13:26:21 by thomasgrang      ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

int main(int ac, char **av)
{
	t_params	param;

	if (ac <= 1 || ac > 3)
		{
			dprintf(1, "Error\nwrong number of arguments\n");
			exit(0);
		}
	if (ac >= 2)
		if (open(av[1], O_RDONLY) == -1)
		{
			dprintf(1, "Error\nwrong arguments\n");
			exit(0);
		}
	if (ac == 3 && ft_strncmp("--save", av[2], 6))
		{
			dprintf(1, "Wrong arguments, a ton of choice:\n\t--save");
			exit(0);
		}
	param = ft_init_struct();
	ft_parse_config(&param, av[1]);
	param.mlx_ptr = mlx_init();
	init_tex(&param);
	if (!(param.zbuffer = (int*)malloc((sizeof(int)) * param.size_x)))
		return (0);
	param.win_ptr = mlx_new_window(param.mlx_ptr, param.size_x, param.size_y, "cube3d");
	param.img.img = mlx_new_image(param.mlx_ptr, param.size_x, param.size_y);
	param.img.data = (int *)mlx_get_data_addr(param.img.img, &param.img.bpp, &param.img.size_line, &param.img.endian);
	if (ac == 3)
		ft_save_bitmap("save.bmp", param);
	mlx_loop_hook(param.mlx_ptr, ft_loop, &param);
	mlx_hook(param.win_ptr, 2, 0, ft_key_press, &param);
	mlx_hook(param.win_ptr, 3, 0, ft_key_release, &param);
	mlx_hook(param.win_ptr, 17, 0, ft_close, &param);
  	mlx_loop(param.mlx_ptr);
	free(param.zbuffer);
  	return (0);
}