/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_config.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrangeo <tgrangeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 11:21:40 by tgrangeo          #+#    #+#             */
/*   Updated: 2020/03/12 19:55:06 by tgrangeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cube3d.h"

static char	*recup_char(char *str)
{
	int		i;
	char	*new;

	i = 0;
	while (str[i] == ' ')
		i++;
	new = ft_substr(str, i, ft_strlen(str));
	return (new);
}

static int	recup_int(char *str)
{
	int		i;
	int		ret;

	i = 0;
	while (ft_isdigit(str[i]) == 0)
		i++;
	ret = ft_atoi(str + i);
	return (ret);
}

static int	ft_parse_2(t_params *param, char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == 'N' && str[i + 1] == 'O')
			param->parse.tex_no = recup_char(str + i + 2);
		else if (str[i] == 'S' && str[i + 1] == 'O')
			param->parse.tex_so = recup_char(str + i + 2);
		else if (str[i] == 'W' && str[i + 1] == 'E')
			param->parse.tex_we = recup_char(str + i + 2);
		else if (str[i] == 'E' && str[i + 1] == 'A')
			param->parse.tex_ea = recup_char(str + i + 2);
		else if (str[i] == 'R')
		{
			param->size_x = recup_int(str + i + 1);
			param->size_y = recup_int(str + i + ft_count_int(param->size_x));
		}
		i++;
	}
	return (1);
}

void	ft_parse_config(t_params *param)
{
	int		fd;
	int		i;
	char	*buffer;

	i = 0;
	buffer = NULL;
	fd = open("map.cub", O_RDONLY);
	while (get_next_line(fd, &buffer) > 0)
	{
		ft_parse_2(param, buffer);
		free(buffer);
		i++;
	}
	dprintf(1, "x:%d\n", param->size_x);
	dprintf(1, "y:%d\n", param->size_y);
	free(buffer);
}