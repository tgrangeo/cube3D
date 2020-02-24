#include "includes/cube3d.h"

int     ft_close(t_params *param)
{
    mlx_clear_window(param->mlx_ptr, param->win_ptr);
    mlx_destroy_window(param->mlx_ptr, param->win_ptr);
    exit (EXIT_SUCCESS);
    return (0);
}

int		ft_key_press(int key, t_params *param)
{
	if (key == KEY_ESCAPE)
		ft_close(param);
	if (key == KEY_A)
		dprintf(1, "pressed\n");
	return (1);
}

int		ft_key_release(int key, t_params *param)
{
	(void)param;
	if (key == KEY_A)
		dprintf(1, "release\n");
	return (1);
}