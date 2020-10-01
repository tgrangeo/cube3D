/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_conf_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomasgrangeon <thomasgrangeon@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/25 20:44:51 by thomasgrang       #+#    #+#             */
/*   Updated: 2020/10/01 12:17:22 by thomasgrang      ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cube3d.h"

static int is_line_map(char *str)
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

static void check_line(char *str, t_params *param)
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

void ft_size_tab(t_params *param)
{
	int fd;
	char *buffer;
	int line;
	int i;

	i = 0;
	line = 0;
	param->first_line = 0;
	param->y_map = 1;
	param->x_map = 0;
	buffer = NULL;
	fd = open("map.cub", O_RDONLY);
	while (get_next_line(fd, &buffer) > 0)
	{
		check_line(buffer, param);
		free(buffer);
	}
	check_line(buffer, param);
	free(buffer);
	close(fd);
}

static void define_pos(t_params *param, char dir, int x, int y)
{
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

static void ft_ligne(int *map, char *str, int x_map, t_params *param, int line)
{
	int x;
	int y;

	x = 0;
	y = 0;
	map[y++] = 9;
	while (y < x_map)
	{
		if (str[x] == '1' && x < ft_strlen(str))
			map[y] = 1;
		else if (str[x] == '0' && x < ft_strlen(str))
			map[y] = 0;
		else if (str[x] == '2' && x < ft_strlen(str))
		{
			map[y] = 2;
			ft_init_sprite(param, x, line);
		}
		else if (x >= ft_strlen(str))
			map[y] = 9;
		else if (str[x] == ' ')
			map[y] = 9;
		else if (str[x] == 'N' || str[x] == 'S' || str[x] == 'E' || str[x] == 'W')
		{
			map[y] = 0;
			define_pos(param, str[x], x, line);
		}
		x++;
		y++;
	}
	map[y] = 9;
}

static void ft_first_last(int *map, int x_map)
{
	int x;

	x = 0;
	while (x <= x_map)
	{
		map[x] = 9;
		x++;
	}
}

//static void afficherTableau(int **grille, int x, int y)
//{
//    int i;
//    int j;
//
//	i = 0;
//	j = 0;
//
//	while (i <= y)
//	{
//		dprintf(1, "%d-",i);
//		while (j <= x)
//		{
//			dprintf(1, "%d", grille[i][j]);
//			j++;
//		}
//		dprintf(1,"\n");
//		j = 0;
//		i++;
//	}
//}

void ft_map_tab(t_params *param)
{
	int fd;
	char *buffer;
	int line;
	int **temp_map;
	int i = 0;	
	fd = open("map.cub", O_RDONLY);
	line = 1;
	temp_map = (int **)malloc((param->y_map) * sizeof(int *));
	temp_map[i] = (int *)malloc(param->x_map * sizeof(int));
	ft_first_last(temp_map[i++], param->x_map);
	while (get_next_line(fd, &buffer) > 0)
	{
		if (line >= param->first_line && is_line_map(buffer) == 1)
		{
			temp_map[i] = (int *)malloc((param->x_map) * sizeof(int));
			ft_ligne(temp_map[i], buffer, param->x_map, param, i);
			i++;
		}
		free(buffer);
		line++;
	}
	if (is_line_map(buffer) == 1)
	{
		temp_map[i] = (int *)malloc((param->x_map) * sizeof(int));
		ft_ligne(temp_map[i], buffer, param->x_map, param, i);
		i++;
	}
	temp_map[i] = (int *)malloc(param->x_map * sizeof(int));
	ft_first_last(temp_map[i], param->x_map);
	if (buffer[0] != '\0')
		free(buffer);
	close(fd);
	param->worldmap = temp_map;
	//afficherTableau(temp_map, param->x_map, param->y_map);
}