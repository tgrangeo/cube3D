/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_conf_3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomasgrangeon <thomasgrangeon@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/01 14:35:26 by tgrangeo          #+#    #+#             */
/*   Updated: 2020/11/02 11:42:42 by thomasgrang      ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

int			is_line_map(char *str)
{
	int i;

	i = 0;
	while (str[i] == ' ')
		i++;
	if (str[i] == '1' || str[i] == '0' || str[i] == '2')
		return (1);
	else
		return (0);
}

void		check_line(char *str, t_params *param)
{
	int i;

	i = 0;
	if (is_line_map(str) == 0 && param->y_map == 0)
		param->first_line++;
	else
	{
		if (is_line_map(str) == 1)
			param->y_map++;
		if (param->x_map < ft_strlen(str))
			param->x_map = ft_strlen(str) + 1;
	}
}

void		ft_map_tab2(t_params *param, char *buffer, int **temp_map)
{
	if (is_line_map(buffer) == 1)
	{
		temp_map[param->i] = (int *)malloc((param->x_map) * sizeof(int));
		ft_ligne(temp_map[param->i], buffer, param, param->i);
		param->i++;
	}
}

void		ft_ligne2(int *map, char *str, t_params *param, int line)
{
	if (str[param->l.x] == '2' && param->l.x < ft_strlen(str))
	{
		map[param->l.y] = 2;
		ft_init_sprite(param, param->l.x, line);
	}
	else if (param->l.x >= ft_strlen(str))
		map[param->l.y] = 9;
	else if (str[param->l.x] == ' ')
		map[param->l.y] = 9;
	else if (str[param->l.x] == 'N' || str[param->l.x] == 'S'
			|| str[param->l.x] == 'E' || str[param->l.x] == 'W')
	{
		map[param->l.y] = 0;
		define_pos(param, str[param->l.x], param->l.x, line);
	}
}

void		move_front(t_params *param, t_vector_d *fpos)
{
	fpos->x = param->dir.x * param->ms;
	fpos->y = param->dir.y * param->ms;
}
