/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_config.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrangeo <tgrangeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 11:21:40 by tgrangeo          #+#    #+#             */
/*   Updated: 2020/02/25 12:34:28 by tgrangeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cube3d.h"

void	ft_parse_config(t_params *param)
{
	int		fd;
	char	*str;

	fd = open("map.cub", O_RDONLY);
	while (get_next_line(fd, &str) > 0)
	{
		if (str[0] == 'R')
		{
			param->size_y = ft_atoi(str + 1);
			param->size_x = ft_atoi(str + 10);
			dprintf(1, "x : %d\n", param->size_x);
			dprintf(1, "y : %d\n", param->size_y);
		}
		free(str);
	}
}