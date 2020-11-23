/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_conf_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomasgrangeon <thomasgrangeon@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/25 20:44:51 by thomasgrang       #+#    #+#             */
/*   Updated: 2020/11/20 13:51:34 by thomasgrang      ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

void			ft_size_tab(t_params *param, char *cube)
{
	int		fd;
	char	*buffer;
	int		line;
	int		i;

	i = 0;
	line = 0;
	param->first_line = 0;
	param->y_map = 1;
	param->x_map = 0;
	buffer = NULL;
	fd = open(cube, O_RDONLY);
	while (get_next_line(fd, &buffer) > 0)
	{
		check_line(buffer, param);
		free(buffer);
	}
	check_line(buffer, param);
	free(buffer);
	close(fd);
}

void			define_pos(t_params *param, char dir, int x, int y)
{
	if (param->pos.x > 0 || param->pos.y > 0)
	{
		dprintf(1, "Error\nmultiple start position\n");
		exit(0);
	}
	if (dir == 'N' || dir == 'S')
	{
		param->pos.x = y + 0.5;
		param->pos.y = x + 1.5;
		ft_init_map_two(param, (int)dir);
	}
	if (dir == 'E' || dir == 'W')
	{
		param->pos.x = y - 0.5;
		param->pos.y = x + 1.5;
		ft_init_map(param, (int)dir);
	}
}

void			ft_ligne(int *map, char *str, t_params *param, int line)
{
	param->l.x = 0;
	param->l.y = 0;
	map[param->l.y++] = 9;
	while (param->l.y < param->x_map)
	{
		if (str[param->l.x] == '1' && param->l.x < ft_strlen(str))
			map[param->l.y] = 1;
		else if (str[param->l.x] == '0' && param->l.x < ft_strlen(str))
			map[param->l.y] = 0;
		ft_ligne2(map, str, param, line);
		param->l.x++;
		param->l.y++;
	}
	map[param->l.y] = 9;
}

static void		ft_first_last(int *map, int x_map)
{
	int x;

	x = 0;
	while (x <= x_map)
	{
		map[x] = 9;
		x++;
	}
}

void			ft_map_tab(t_params *param, char *cube)
{
	int		fd;
	char	*buffer;
	int		line;
	int		**temp_map;

	param->i = 0;
	fd = open(cube, O_RDONLY);
	line = 1;
	temp_map = (int **)malloc((param->y_map) * sizeof(int *));
	temp_map[param->i] = (int *)malloc(param->x_map * sizeof(int));
	ft_first_last(temp_map[param->i++], param->x_map);
	while (get_next_line(fd, &buffer) > 0)
	{
		if (line++ >= param->first_line)
			ft_map_tab2(param, buffer, temp_map);
		free(buffer);
	}
	if (is_line_map(buffer) == 1)
		ft_map_tab2(param, buffer, temp_map);
	temp_map[param->i] = (int *)malloc(param->x_map * sizeof(int));
	ft_first_last(temp_map[param->i], param->x_map);
	if (buffer[0] != '\0')
		free(buffer);
	close(fd);
	param->worldmap = temp_map;
}
