/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_config.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomasgrangeon <thomasgrangeon@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 11:21:40 by tgrangeo          #+#    #+#             */
/*   Updated: 2020/10/01 12:16:05 by thomasgrang      ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */


#include "includes/cube3d.h"

static char	*recup_char(char *str, t_params *param)
{
	int		i;
	int		y;
	char	*new;

	i = 0;
	y = 0;
	while (str[y] == ' ')
		y++;
	while (str[i + y] >= 41)
		i++;
	new = ft_substr(str, y, i + 1);
	param->parse.i += i + 1;
	return (new);
}

static int	recup_int(char *str, t_params *param)
{
	int		i;
	int		ret;

	i = 0;
	ret = 0;
	while (ft_isdigit(str[i]) == 0)
		i++;
	ret = ft_atoi(str + i);
	param->parse.i += ft_count_int(ret) + i;
	return (ret);
}

static int	ft_parse_3(t_params *param, char *str)
{
	if (str[param->parse.i] == 'C')
	{
		t_rgb	sky;

		sky.r = recup_int(str + param->parse.i, param);
		sky.g = recup_int(str + param->parse.i, param);
		sky.b = recup_int(str + param->parse.i, param);
		param->color_sky = sky.r * 65536 + sky.g * 256 + sky.b;
	}
	else if (str[param->parse.i] == 'F')
	{
		t_rgb	floor;

		floor.r = recup_int(str + param->parse.i, param);
		floor.g = recup_int(str + param->parse.i, param);
		floor.b = recup_int(str + param->parse.i, param);
		param->color_floor = floor.r * 65536 + floor.g * 256 + floor.b;
	}
	return (1);
}

static int	ft_parse_2(t_params *param, char *str)
{	
	param->parse.i = 0;
	while (str[param->parse.i])
	{
		if (str[param->parse.i] == 'N' && param->parse.tex_no == NULL)
			param->parse.tex_no = recup_char(str + 3, param);
		else if (str[param->parse.i] == 'S' && str[param->parse.i + 1] == 'O' && param->parse.tex_so == NULL)
			param->parse.tex_so = recup_char(str + 3, param);
		else if (str[param->parse.i] == 'W' && param->parse.tex_we == NULL)
			param->parse.tex_we = recup_char(str + 3, param);
		else if (str[param->parse.i] == 'E' && param->parse.tex_ea == NULL)
			param->parse.tex_ea = recup_char(str + 3, param);
		else if (str[param->parse.i] == 'S' && str[param->parse.i + 1] != 'O' && param->sprite == NULL)
			param->sprite = recup_char(str + 2, param);
		else if (str[param->parse.i] == 'R')
		{
			param->size_x = recup_int(str + param->parse.i, param);
			if (param->size_x > 1920)
				param->size_x = 1920;
			param->size_y = recup_int(str + param->parse.i, param);
			if (param->size_y > 1080)
				param->size_y = 1080;
		}
		ft_parse_3(param, str);
		param->parse.i++;
	}
	return (1);
}

void	ft_parse_config(t_params *param)
{
	int		fd;
	char	*buffer;


	//premiere partie
	buffer = NULL;
	fd = open("map.cub", O_RDONLY);
	while (get_next_line(fd, &buffer) > 0)
	{
		ft_parse_2(param, buffer);
		free(buffer);
	}
	ft_parse_2(param, buffer);
	free(buffer);
	close(fd);

	//partie map
	ft_size_tab(param);
	ft_map_tab(param);
	ft_check_map(param);
}